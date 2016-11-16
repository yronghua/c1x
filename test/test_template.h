#pragma once

#include <typeinfo>

template<typename T>
class TemplateA
{
public:
	TemplateA() {
        LOG_FUNCTION;
		cout << "name:" << typeid(T).name() << endl;
		cout << "hash:" << typeid(T).hash_code() << endl;
		cout << "raw_name:" << typeid(T).raw_name() << endl;
	}
};

template<bool bTest> class SomeType {};
std::vector<SomeType < (1>2) >> x1;

class SomeStruct
{
public:
    auto FunctionName(int x) -> int;

private:
    vector<int> arr_ = vector<int>{ 1 };
};

auto SomeStruct::FunctionName(int x) -> int
{
    LOG_FUNCTION;
    int ret = ++x;
    arr_.push_back(ret);
    for (auto &x : arr_) {
        cout << x << " ";
    }
    return ret;
}

void test_template()
{
    LOG_FUNCTION;
    cout << SomeStruct().FunctionName(1) << endl;
}