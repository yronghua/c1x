#pragma once


enum EnumA : int;
enum class EnumB;

void test_declare(EnumA e) {
    LOG_FUNCTION;
    cout << e << " size:" << sizeof(e) << endl;
}

void test_declare(EnumB e);


