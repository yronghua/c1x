// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_shared_ptr.h"
#include "test_variable_param.h"
#include "test_move.h"
#include "test_template.h"
#include "test_override.h"
#include "test_declare.h"
#include "test_include.h"

#include <sstream>

namespace std {
	typedef wstring tstring;
	typedef wostringstream tostringstream;
};

class CTest
{

};

extern template class TemplateA<CTest>;

std::tstring AddFileSplit(std::tstring file_name, int split_num)
{
	if (!file_name.empty())
	{
		std::size_t point_pos = file_name.find_last_of(_T('.'));
		if (point_pos != std::string::npos)
		{
			std::tstring ext_str = file_name.substr(point_pos, file_name.size() - point_pos);
			std::tstring point_str = file_name.erase(point_pos);
			std::tostringstream oss;
			oss << file_name << _T('_') << split_num << ext_str;
			return oss.str();
		}
	}
	return std::tstring();
}

constexpr int get_const(int v) {
	return v;
}

class CTypeClass
{
public:
    CTypeClass(int i) : i_(i) {}
    explicit operator bool() {
        LOG_FUNCTION;
        return i_ != 0;
    }
private:
    int i_ = 0;
};


int main()
{
	//std::tstring ret = AddFileSplit(_T("asd2.asdf.log"), 1);
    test_override();

	TemplateA<CTest> tempa_test;

    test_template();

	test_move();

	test_shared_ptr();

	test_variable_param();

	int pc_num = 2;
	//char pc[get_const(pc_num)] = { 0 }; // invalid
	char pc[get_const(2)] = { 0 };

    test_declare(EnumA::kA1);
    test_declare(EnumB::kB1);

    CTypeClass type_class(-1);
    if (type_class) {
        cout << "type_class is true" << endl;
    }
    else {
        cout << "type-class is false" << endl;
    }

    //int add_type_class = 1 + type_class; // invalid
    //cout << "add_type_class:" << add_type_class << endl;

    return 0;
}

