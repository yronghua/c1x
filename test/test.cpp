// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_shared_ptr.h"
#include "test_variable_param.h"
#include <sstream>

namespace std {
	typedef wstring tstring;
	typedef wostringstream tostringstream;
};


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

int main()
{
	std::tstring ret = AddFileSplit(_T("asd2.asdf.log"), 1);

	test_shared_ptr();

	test_variable_param();

    return 0;
}

