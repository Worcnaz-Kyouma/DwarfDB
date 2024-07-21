#include "DataInstance.hpp"
#include "VirtualDB.hpp"

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