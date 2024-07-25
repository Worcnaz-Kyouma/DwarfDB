#ifndef DWARFDB_ENTITY_H
#define DWARFDB_ENTITY_H

#include "Database.hpp"

class Entity {
friend class Database;

private:
    int id;
    static const Database* database;
    void setID(int id); //Just database relatives can make it... Through friend relation!

public:
    Entity();

    int getID();

    Entity* getByID(int id);
    Entity* create(Entity* object);
    Entity* update(Entity* object);
    void remove(int id);
};

#endif