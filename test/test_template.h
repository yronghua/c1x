#pragma once

#include <typeinfo>

template<typename T>
class TemplateA
{
public:
	TemplateA() {
		cout << "name:" << typeid(T).name() << endl;
		cout << "hash:" << typeid(T).hash_code() << endl;
		cout << "raw_name:" << typeid(T).raw_name() << endl;

	}
};
