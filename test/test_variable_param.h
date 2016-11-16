#pragma once

template<typename ...Args> struct VariableStruct
{
	static const int size = sizeof...(Args);

};

struct MyStruct1 : public VariableStruct<int>
{

};

void test_variable_param()
{
	std::cout << std::endl << __FUNCTION__ << std::endl;
	typedef VariableStruct<int, char*> MyStruct;
	std::cout << MyStruct::size << std::endl;
	std::cout << MyStruct1::size << std::endl;
}
