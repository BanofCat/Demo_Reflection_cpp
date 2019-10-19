#ifndef __BAN_TEST_CLASS_H__
#define __BAN_TEST_CLASS_H__
#include <stdio.h>
#include "ClassFactory.h"

class TestClassBase
{
public:
    virtual void printInfo() = 0;

};  // !class TestClassBase

class TestClassA:TestClassBase
{
public:
    void printInfo()
    {
        fprintf(stderr, "I am class TestClass A\n");
    };
};  // !class TestClassA

class TestClassB:TestClassBase
{
public:
    void printInfo()
    {
        fprintf(stderr, "I am class TestClass B\n");
    };
}; // !class TestClassB




REGISTER_CLASS(TestClassA); 
REGISTER_CLASS(TestClassB); 




#endif // !__BAN_TEST_CLASS_H__