#pragma once


typedef std::shared_ptr<std::wstring> wstr_ptr;
typedef std::weak_ptr<std::wstring> wstr_wptr;
void test_shared_ptr()
{
	wstr_ptr host = std::make_shared<std::wstring>();
	wstr_wptr whost = host;
	*host = CA2W("abc");
	*host = CA2W("pconline1.qqgame.qq.com.asdb");

	std::cout << host->c_str() << std::endl;
}