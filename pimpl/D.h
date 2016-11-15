#pragma once
class CD
{
public:
    CD();
    ~CD();
	void test1();
	void test2();
	
private:
	class Pimpl;

	Pimpl *pimpl_;
};

