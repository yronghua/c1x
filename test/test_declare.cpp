#include "stdafx.h"
#include "test_include.h"

void test_declare(EnumB e) {
    LOG_FUNCTION;
    //cout << e << " size:" << sizeof(e) << endl;
    if (e == EnumB::kB1) {
        cout << "kB1" << endl;
        //cout << e << endl; // invalid
    }
}