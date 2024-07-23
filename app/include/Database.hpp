#ifndef DWARFDB_DATABASE_H
#define DWARFDB_DATABASE_H

#include "Entity.hpp"

class Database {
private:
    int numberOfRegisters = 0;
    int lastID = 0;
public:
    virtual Entity* fetch(int id) = 0;
    virtual Entity* insert(Entity* object) = 0;
    virtual Entity* update(Entity* object) = 0;
    virtual void remove(int id) = 0;

    virtual int manageDataCount(int quantityOffset);
    virtual int getDataCount();
    
    virtual int generateNextID();
};

#endif