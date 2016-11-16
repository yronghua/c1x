// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <memory>
#include <iostream>
#include <vector>


#include <atlbase.h>
#include <tchar.h>
#include <atlconv.h>

using namespace std;


class CLogHelper
{
public:
    CLogHelper(const char* function) {
        cout << "----------------------------------" << endl;
        cout << function << endl;
    }

    ~CLogHelper() {
        cout << endl;
    }
};

#define LOG_FUNCTION CLogHelper temp_log_function(__FUNCTION__);

// TODO:  在此处引用程序需要的其他头文件
