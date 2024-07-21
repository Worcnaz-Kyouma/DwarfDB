#include "DataInstance.hpp"
#include "VirtualDB.hpp"

/*
Well... That guy seems useless... but i thought about that and i think it haves its value. Like, with that class we can abstract the number of Database types we have in the lib, so the user will just use that class passing a type of DB to it and just use! But... just for that? Keep looking useless... but yeah, i think its worth it.
*/

template<typename T>
DataInstance<T>::DataInstance(DataInstance::DBTypes type) {
    switch(type) {
        case DataInstance::DBTypes::VirtualDB:
            this->database = VirtualDB<T>();
            break;
        default:
            //throw new Error(); ?! So tem error default da std -_-
            break;
    }
}

template<typename T>
T* DataInstance<T>::getByID(int id) {
    const T* object = this->database.fetch(id);

    return object;
}

template<typename T>
T* DataInstance<T>::persist(T* object) {
    if(object->id == 0) {
        object->id = this->database->getDataCount() + 1;

        return this->database.insert(object);
    }

    return this->database.update(object);
}

template<typename T>
void DataInstance<T>::remove(int id) {
    this->database.remove(id);
}