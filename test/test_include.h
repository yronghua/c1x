#pragma once


enum EnumA : int {
    kA1 = 3,
    kA2,
};

enum class EnumB {
    kB1 = 4,
    kB2,
};


class CSingtonClass
{
public:
	CSingtonClass() {
		LOG_FUNCTION;
	}
	/*
	static CSingtonClass& GetInstance()
	{
		static CSingtonClass * s_c = NULL;
		if (s_c == NULL)
		{
			s_c = new CSingtonClass;
		}
		return *s_c;
	}
	*/

	CSingtonClass& GetInstance2();
};

CSingtonClass* GetSington();