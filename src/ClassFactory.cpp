#include <map>
#include "ClassFactory.h"

/* private */
ClassFactory::
ClassFactory()
{
    this->class_map.clear();
    // abandon new obj
}


/* public */
void ClassFactory::
registerClass(const std::string &class_name, CreateObjFunction create_method)
{
    this->class_map[class_name] = create_method;
}


ClassFactory& ClassFactory::
getInstance()
{
    static ClassFactory factory_obj;
    return factory_obj;
}

void* ClassFactory::
newObject(const std::string &class_name)
{
    std::map<std::string, CreateObjFunction>::iterator iter = this->class_map.begin();
    iter = this->class_map.find(class_name);
    if (iter == this->class_map.end()) {
        return NULL;
    }
    return iter->second();
}
