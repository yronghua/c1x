// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>


// TODO:  在此处引用程序需要的其他头文件
#define BEGIN_CALSS(class_name) class class_name {

#define PUBLIC_FUNCTION(ret, func_name, ...) public: ret func_name##(__VA_ARGS__);

#define END_CLASS() };