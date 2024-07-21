#ifndef DWARFDB_DATABASE_H
#define DWARFDB_DATABASE_H

#include "DataInstance.hpp"

template <typename T>
class Database {
private:
    int numberOfRegisters = 0;
public:
    virtual T* fetch(int id) = 0;
    //virtual T** fetchAll() = 0;
    //virtual T** fetch(char* field, int value) = 0;
    //virtual T** fetch(char* field, float value) = 0;
    //virtual T** fetch(char* field, char* value) = 0;
    virtual T* insert(T* object) = 0;
    virtual T* update(T* object) = 0;
    virtual void remove(int id) = 0;

    virtual int getDataCount() = 0;
};

#endif