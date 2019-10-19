#include "TestClass.h"
#include "ClassFactory.h"

int main(int argc, char* argv[])
{
    TestClassBase* t_a = (TestClassBase*) ClassFactory::getInstance().newObject("TestClassA");
    t_a->printInfo();
    TestClassBase* t_b = (TestClassBase*) ClassFactory::getInstance().newObject("TestClassB");
    t_b->printInfo();
    return 0;
}