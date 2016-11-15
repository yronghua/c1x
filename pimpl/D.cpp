#include "stdafx.h"
#include "D.h"


class CD::Pimpl : public CD {
public:
	void test1();

	void test2()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	void test3()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

private:
	void test4()
	{

	}
};


void CD::Pimpl::test1()
{
	std::cout << __FUNCTION__ << std::endl;
}

CD::CD()
{
}


CD::~CD()
{
}


void CD::test1()
{
	pimpl_->test1();
}

void CD::test2()
{
	pimpl_->test2();
}



