#include "stdafx.h"
#include "C.h"

/*
CC::CC()
{
}


CC::~CC()
{
}
*/
/*
void CC::test1(int a, int b) 
{
    std::cout << __FUNCTION__ << std::endl;
}
*/

#define BEGIN_IMPL_CLASS(x) class x::Pimpl{

#define END_IMPL_CLASS() };

#define IMPL_PUBLIC_FUNCTION(x, ret, func_name, ...) ret func_name##(__VA_ARGS__);


BEGIN_IMPL_CLASS(CC)

//IMPL_PUBLIC_FUNCTION(void, test1, int a, int b)

END_IMPL_CLASS()