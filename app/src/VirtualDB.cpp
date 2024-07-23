#include "VirtualDB.hpp"

Entity* VirtualDB::insert(Entity* object) {
    if(object->getID() != 0){
        return object; //Dont know how to make the errors
    }

    
}