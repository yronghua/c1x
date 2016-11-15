// pimpl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"


#define TO_STRING2(x) #x  
#define TO_STRING(x) TO_STRING1(x)  
#define TO_STRING1(x) #x  
#define PARAM(x) #x  
#define ADDPARAM(x) INT_##x  

int main()
{
	/*
	const char *str = TO_STRING(PARAM(ADDPARAM(1)));
	printf("%s\n", str);

	str = TO_STRING2(PARAM(ADDPARAM(1)));
	printf("%s\n", str);
	*/


    CA a;
    a.test1();

    CB b;
    b.test1();

    //CC c;
    //c.test1(0,0);

    CD d;
    d.test1();

    return 0;
}

