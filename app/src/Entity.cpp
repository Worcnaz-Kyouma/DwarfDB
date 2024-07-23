#include "Entity.hpp"
#include "VirtualDB.hpp"

const Database* Entity::database = new VirtualDB();

Entity::Entity() {
    this->id = 0;
}

Entity* Entity::getByID(int id) {
    const Entity* fetchedObject = *Entity::database.fetch(id);

    return fetchedObject;
}

Entity* Entity::create(Entity* object) {
    const Entity* newObject = *Entity::database.insert(object);

    return newObject;
}

Entity* Entity::update(Entity* object) {
    const Entity* updatedObject = Entity::database.update(object);

    return updatedObject;
}


void Entity::remove(int id) {
    this->database.remove(id);
}