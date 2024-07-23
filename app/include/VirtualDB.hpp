#ifndef DWARFDB_VIRTUALDB_H
#define DWARFDB_VIRTUALDB_H

#include "Entity.cpp"
#include "Database.hpp"

class VirtualDB : public Database {
private:
    Entity** objectHeap;

    Entity* fetchWithBinarySearch(int id); 
public:
    Entity* fetch(int id) override;
    Entity* insert(Entity* object) override;
    Entity* update(Entity* object) override;
    void remove(int id) override;
};

#endif