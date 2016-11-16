#pragma once

class CBase
{
public:
    virtual void func1() {}
    virtual void func2(int i) {}
};

class CDeriver : public CBase
{
public:
    void func1() override {
        LOG_FUNCTION;
    }
    
    void func2(int c) {
        LOG_FUNCTION;
    }
};

class CDDeriver : public CDeriver
{
public:
    void func1() override {
        LOG_FUNCTION;
    }

    void func3(int c) {
        LOG_FUNCTION;
    }
};

void test_override()
{
    CDDeriver d;
    d.func1();
    d.func2(1);
}