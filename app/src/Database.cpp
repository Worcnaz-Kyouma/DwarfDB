#include "Database.hpp"

int Database::manageDataCount(int quantityOffset) {
    this->numberOfRegisters+=quantityOffset;

    return this->numberOfRegisters;
}

int Database::getDataCount() {
    return this->numberOfRegisters;
}

int Database::generateNextID() {
    return ++this->lastID;
}