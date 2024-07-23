#ifndef DWARFDB_ENTITY_H
#define DWARFDB_ENTITY_H

#include "Database.hpp"

class Entity {
private:
    int id;
    static const Database* database;

public:
    Entity();
    int getID();
    void setID(int id); //Just database relatives can make it

    Entity* getByID(int id);
    Entity* create(Entity* object);
    Entity* update(Entity* object);
    void remove(int id);
};

#endif