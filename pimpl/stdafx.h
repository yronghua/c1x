// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#define BEGIN_CALSS(class_name) class class_name {

#define PUBLIC_FUNCTION(ret, func_name, ...) public: ret func_name##(__VA_ARGS__);

#define END_CLASS() };