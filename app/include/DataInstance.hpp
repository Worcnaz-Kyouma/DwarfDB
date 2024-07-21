#ifndef DWARFDB_DATAINSTANCE_H
#define DWARFDB_DATAINSTANCE_H

#include "Database.hpp"

template <typename T>
class DataInstance {
private:
    enum class DBTypes {
        VirtualDB
    };
    const Database<T> database;

public:
    DataInstance(DBTypes type);

    T* getByID(int id);
    //T** get(char* field, int value);
    //T** get(char* field, float value);
    //T** get(char* field, char* value);
    T* persist(T* object);
    void delete(int id);

};

#endif