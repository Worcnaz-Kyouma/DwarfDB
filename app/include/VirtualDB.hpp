#ifndef DWARFDB_VIRTUALDB_H
#define DWARFDB_VIRTUALDB_H

#include "Database.hpp"

template<typename T>
class VirtualDB : public Database<T> {
private:
    T** objectHeap;

    T* executeBinarySearch(int id, T** source, int sourceSize, bool deleteEntry = false); 

    // Temporary
    static void** copyArray(void** destination, int destinationSize, void** source, int beginIndexSource = 0);
public:
    T* fetch(int id) override;
    //T** fetchAll() override;
    //T** fetch(char* field, int value) override;
    //T** fetch(char* field, float value) override;
    //T** fetch(char* field, char* value) override;
    T* insert(T* object) override;
    //T* update(T* object) override; OBS: Cuidado com a busca binaria aqui
    void remove(int id) override;

    int getDataCount() override;
};

#endif