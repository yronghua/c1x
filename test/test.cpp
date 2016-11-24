// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_shared_ptr.h"
#include "test_variable_param.h"
#include "test_move.h"
#include "test_template.h"
#include "test_override.h"
#include "test_declare.h"
#include "test_include.h"
#include "test_char.h"
#include "test_class.h"
#include "test_thread.h"

#include <sstream>

namespace std {
	typedef wstring tstring;
	typedef wostringstream tostringstream;
};

class CTest
{
	friend void test_for();
public:
	CTest() : i_(0) {

	}
private:
	int i_;
};

extern template class TemplateA<CTest>;

std::tstring AddFileSplit(std::tstring file_name, int split_num)
{
	if (!file_name.empty())
	{
		std::size_t point_pos = file_name.find_last_of(_T('.'));
		if (point_pos != std::string::npos)
		{
			std::tstring ext_str = file_name.substr(point_pos, file_name.size() - point_pos);
			std::tstring point_str = file_name.erase(point_pos);
			std::tostringstream oss;
			oss << file_name << _T('_') << split_num << ext_str;
			return oss.str();
		}
	}
	return std::tstring();
}

constexpr int get_const(int v) {
	return v;
}

void test_for() {
	int my_array[5] = { 1, 2, 3, 4, 5 };
	for (int &x : my_array)
	{
		x *= 2;
	}

	CTest *my_array2[2] = { new CTest, new CTest };

	for (CTest *x : my_array2) {
		cout << x->i_ << endl;
	}
	cout << endl;
}

void test_null_point(char* ptr)
{
	cout << __FUNCTION__ << " ptr" << endl;
}

void test_null_point(int i) {
	cout << __FUNCTION__ << " int" << endl;
}

class CTypeClass
{
public:
    CTypeClass(int i) : i_(i) {}
    explicit operator bool() {
        LOG_FUNCTION;
        return i_ != 0;
    }
private:
    int i_ = 0;
};

HANDLE g_thread_event = 0;

DWORD WINAPI thread_proc(LPVOID param)
{
	WaitForSingleObject(g_thread_event, INFINITE);
	return 0;
}

#define SDK_OPENID_LEN         128   //SDK的openid的长度
#define SDK_OPENKEY_LEN        256   //SDK的openkey的长度
#define SDK_QQNICKNAME_LEN     128    //QQ的昵称的长度
#define SDK_QQHEADURL_LEN      256   //QQ的头像url的长度
#define MAX_NEW_GAME_COMMAND_DATA_BUFFER_LEN  64 * 1024 //防止过程的管道消息
#define SDK_RETCODE_GETORDER_URL_FAIL 101 //获取内购订单url失败
#define SDK_SKEY_COOKIE_LEN    256   // SkeyCookie长度

#pragma pack(1)
typedef struct tagSDKLOGININFO
{
	char   openid[SDK_OPENID_LEN];
	char   openkey[SDK_OPENKEY_LEN];
	char   qqnickname[SDK_QQNICKNAME_LEN];
	DWORD  dwSvrTime;
	char   cookieSkey[SDK_SKEY_COOKIE_LEN];
	uint64_t gameVer;
	uint64_t uin;
	uint64_t appid;
}SDKLOGININFO;
#pragma pack()

std::string GetSDKOpenid()
{
	return "abc";
}
std::string GetSDKOpenkey()
{
	return "asdfsadfsd";
}

int main()
{
	SDKLOGININFO sdklogin = { 0 };

	memcpy_s(&sdklogin.openid, SDK_OPENID_LEN, (GetSDKOpenid()).c_str(), SDK_OPENID_LEN);
	memcpy_s(&sdklogin.openkey, SDK_OPENKEY_LEN, (GetSDKOpenkey()).c_str(), SDK_OPENKEY_LEN);

	

	test_null_point(NULL);

	//std::tstring ret = AddFileSplit(_T("asd2.asdf.log"), 1);
	test_override();

	TemplateA<CTest> tempa_test;
	test_for();

	test_template();

	test_move();

	test_shared_ptr();

	test_variable_param();

	int pc_num = 2;
	//char pc[get_const(pc_num)] = { 0 }; // invalid
	char pc[get_const(2)] = { 0 };

	test_declare(EnumA::kA1);
	test_declare(EnumB::kB1);

	CTypeClass type_class(-1);
	if (type_class) {
		cout << "type_class is true" << endl;
	}
	else {
		//cout << "type-class is false" << endl;
	}

    while (type_class) {
        break;
    }

    test_char();


	test_class();

	test_thread();

    //int add_type_class = 1 + type_class; // invalid
    //cout << "add_type_class:" << add_type_class << endl;

	g_thread_event = CreateEvent(0, true, false, 0);
	::CreateThread(NULL, 0, thread_proc, 0, 0, 0);
	SetEvent(g_thread_event);
	CloseHandle(g_thread_event);

	cout << "任意键结束";
	cin.get();
    return 0;
}

CSingtonClass& CSingtonClass::GetInstance2()
{
	static CSingtonClass * s_c = NULL;
	if (s_c == NULL)
	{
		s_c = new CSingtonClass;
	}
	return *s_c;
}

CSingtonClass* g_c = NULL;

CSingtonClass* GetSington()
{
	if (g_c == NULL)
		g_c = new CSingtonClass;

	return g_c;
}