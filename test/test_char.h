#pragma once




void test_char()
{
	LOG_FUNCTION;
	char* u8 = u8"�� i am a utf-8 string. \u534e";
	char16_t *u16 = u"�� i am a utf-16 string. ";
	char32_t *u32 = U"�� i am a utf-32 string. ";
	cout << u8 << endl;
	cout << u16 << endl;
	wcout << u32 << endl;

}