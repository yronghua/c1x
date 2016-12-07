#pragma once

class Foo
{
public:
	void methodA() {
		LOG_FUNCTION;
	}
	void methodInt(int a)
	{
		LOG_FUNCTION;
	}
	void methodCh(char c)
	{
		LOG_FUNCTION;
	}
};
class Bar
{
public:
	void methodB() {
		LOG_FUNCTION;
	}
};


void test_function()
{
	LOG_FUNCTION;

	std::string s1 = "abc", s2 = "def";
	const char* sz1 = "abc";
	const char* sz2 = "def";
	//LOG("abc", "def");
	int i = 2;
	LOG(sz1, sz2, 2);

	tr1::function<void()> f1; // 无参数，无返回值

	Foo foo;
	f1 = tr1::bind(&Foo::methodA, &foo);
	f1(); // 调用 foo.methodA();
	Bar bar;
	f1 = tr1::bind(&Bar::methodB, &bar);
	f1(); // 调用 bar.methodB();

	f1 = tr1::bind(&Foo::methodInt, &foo, 42);
	f1(); // 调用 foo.methodInt(42);

	f1 = tr1::bind(&Foo::methodCh, &foo, 'c');
	f1();

	tr1::function<void(int)> f2; // int 参数，无返回值

	f2 = tr1::bind(&Foo::methodInt, &foo, tr1::placeholders::_1);
	f2(53); // 调用 foo.methodInt(53);

	f2 = tr1::bind(&Foo::methodCh, &foo, tr1::placeholders::_1);
	f2('d');
}
