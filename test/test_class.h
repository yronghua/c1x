#pragma once


class NonNewable
{
public:
	//void* operator new(size_t) = delete;
	void print() {
		cout << __FUNCTION__ << endl;
	}
};

void test_class()
{
	LOG_FUNCTION;
#ifndef _DEBUG
//#error("wrong debug");
#endif

	GetSington()->GetInstance2();

	//static_assert(_DEBUG, "not debug");

	NonNewable stack_obj;
	stack_obj.print();


	char buffer[100] = { 0 };
	NonNewable* heap_obj = new(buffer) NonNewable();
	heap_obj->print();
}
