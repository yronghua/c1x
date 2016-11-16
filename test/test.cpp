// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_shared_ptr.h"
#include "test_variable_param.h"
#include "test_move.h"
#include "test_template.h"

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

int main()
{
	//std::tstring ret = AddFileSplit(_T("asd2.asdf.log"), 1);
	TemplateA<CTest> tempa_test;

	test_move();

	test_shared_ptr();

	test_variable_param();

	int pc_num = 2;
	//char pc[get_const(pc_num)] = { 0 }; // invalid
	char pc[get_const(2)] = { 0 };

    return 0;
}

