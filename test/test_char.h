#pragma once

#include <codecvt>


void test_char()
{
	LOG_FUNCTION;

	//locale::global(locale(""));
	//setlocale(LC_CTYPE, "");    // MinGW gcc.

	//cout.imbue(locale(""));
	wcout.imbue(locale(""));
	

	char* c = "c 华 i am a utf-8 string.";
	char* u8 = u8"u8 华 i am a utf-8 string. \u534e";
	char16_t *u16 = u"u16 华 i am a utf-16 string. \u534e";
	char32_t *u32 = U"u32 华 i am a utf-32 string. \u534e";
	wchar_t *wc = L"wc 华 i am a utf-16 string.";
	std::wstring wstr = L"wstr 华 i am a utf-16 string. \u534e";

	cout << c << endl;
	wcout << wc << endl;
	wcout << wstr.c_str() << endl;
	wcout << (wchar_t*)u16 << endl;
	//cout.imbue(locale("zh_CN.UTF-8")); // 错误名称

	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	cout << u8 << endl;

	wcout << (wchar_t*)u16 << endl;

	char* raw_c = R"raw(the string data \stuff" )raw";
	cout << raw_c << endl;

	char16_t* raw_16 = uR"r16(this is a "Raw u16" string.)r16";
	wcout << (wchar_t*)raw_16 << endl;

	//wcout << u32 << endl;

}