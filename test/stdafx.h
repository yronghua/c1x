// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
