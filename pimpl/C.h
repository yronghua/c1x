#pragma once



/*
class CC
{
public:
    CC();
    ~CC();
    void test1();
};
*/

BEGIN_CALSS(CC)
PUBLIC_FUNCTION(void, test1, int a, int b)

class Pimpl;
Pimpl *pimpl_;

END_CLASS()


