#ifndef DWARFDB_ENTITY_H
#define DWARFDB_ENTITY_H

#include "Database.hpp"
#include "VirtualDB.hpp"

class Entity {
friend class Database;
friend class VirtualDB;

private:
    int id;
    static Database* database;

public:
    Entity();

    int getID();

    Entity* getByID(int id);
    Entity* create(Entity* object);
    Entity* update(Entity* object);
    void remove(int id);
};

#endif