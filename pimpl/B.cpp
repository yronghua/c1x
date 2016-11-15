#include "stdafx.h"
#include "B.h"

CB::CB()
    : ptra(0)
{
}


CB::~CB()
{
}

void CB::test1()
{
    std::cout << __FUNCTION__ << std::endl;
	/*
    obja.test1();

    ptra = new CA();
    ptra->test1();
    ptra->test2();
	*/
}