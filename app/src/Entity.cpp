#include "Entity.hpp"
#include "VirtualDB.hpp"

Database* Entity::database = new VirtualDB();

Entity::Entity() {
    this->id = 0;
}

Entity* Entity::getByID(int id) {
    Entity* fetchedObject = Entity::database->fetch(id);

    return fetchedObject;
}

Entity* Entity::create(Entity* object) {
    Entity* newObject = Entity::database->insert(object);

    return newObject;
}

Entity* Entity::update(Entity* object) {
    Entity* updatedObject = Entity::database->update(object);

    return updatedObject;
}


void Entity::remove(int id) {
    Entity::database->remove(id);
}