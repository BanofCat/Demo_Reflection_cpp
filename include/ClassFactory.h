#ifndef __BAN_CLASS_FACTORY_H__
#define __BAN_CLASS_FACTORY_H__
#include <string>
#include <stdio.h>
#include <map>

typedef void* (*CreateObjFunction)();


class ClassFactory
{
private:
    std::map<std::string, CreateObjFunction> class_map;

private:
    ClassFactory();

public:
    void registerClass(const std::string &class_name, CreateObjFunction create_method);
    static ClassFactory& getInstance();
    void* newObject(const std::string &class_name);

};  // !class ClassFactory


class ClassRegister
{
public:
    ClassRegister (const std::string &class_name, CreateObjFunction create_method)
    {
        ClassFactory::getInstance().registerClass(class_name, create_method);
    }
};  // !class ClassRegister

#define REGISTER_CLASS(ClassName)               \
    ClassName* newObject##ClassName()           \
    {                                           \
        return new ClassName;                   \
    }                                           \
                                                \
    ClassRegister g_class_register##ClassName(#ClassName, (CreateObjFunction)newObject##ClassName)  


#endif // !__BAN_CLASS_FACTORY_H__