#include "VirtualDB.hpp"

template<typename T>
T* VirtualDB<T>::fetch(int id){
    const T* searchObject = this->executeBinarySearch(id, this->objectHeap, this->numberOfRegisters);
    return searchObject;
}

template<typename T>
T* VirtualDB<T>::insert(T* object){
    const T** newObjectHeapSpace = new T*[this->numberOfRegisters + 1];
    const T** newObjectHeap = this->copyArray(newObjectHeapSpace, this->numberOfRegisters, this->objectHeap);

    this->numberOfRegisters++;

    newObjectHeap[this->numberOfRegisters] = object;

    return object;
}

template<typename T>
void VirtualDB<T>::remove(int id){
    if(this->numberOfRegisters == 0) {
        return;
    }

    this->executeBinarySearch(id, this->objectHeap, this->numberOfRegisters, true);

    this->numberOfRegisters--;

    const T** newObjectHeap = new T*[this->numberOfRegisters];

    int i = 0;
    for(int c = 0; c<this->numberOfRegisters; c++){
        if(this->objectHeap[c] == nullptr) {
            continue;
        }

        newObjectHeap[i] = this->objectHeap[c];
    }

    this->objectHeap = newObjectHeap;
}

template<typename T>
int VirtualDB<T>::getDataCount() {
    return this->numberOfRegisters;
}

template<typename T>
T* VirtualDB<T>::executeBinarySearch(int id, T** source, int sourceSize, bool deleteEntry = false) {
    if(sourceSize == 1) {
        if(deleteEntry) {
            delete source[0];
            source[0] = nullptr;
        }

        return source[0];
    }
    
    const int middleIndex = sourceSize / 2;
    const T* middleObject = source[middleIndex];

    const bool isOnTheMiddle = middleObject->id == id;
    if(isOnTheMiddle) {
        if(deleteEntry) {
            delete middleObject;
            middleObject = nullptr;
        }

        return middleObject;
    }

    const bool isInFirstHalf = middleId > id;

    if(isInFirstHalf) {
        const int newSize = middleIndex;

        const T** firstHalfSpace = new T*[newSize];

        const T** firstHalf = this->copyArray(firstHalfSpace, newSize, source);

        return this->executeBinarySearch(id, firstHalf, newSize);
    } else {
        const int newSize = middleIndex - sourceSize % 2 == 0 ? 1 : 0;

        const T** secondHalfSpace = new T*[newSize];

        const T** secondHalf = this->copyArray(secondHalfSpace, newSize, source, middleIndex + 1);

        return this->executeBinarySearch(id, secondHalf, newSize);
    }
}

template<typename T>
void** VirtualDB<T>::copyArray(void** destination, int numberOfCopies, void** source, int beginIndexSource = 0) {
    if(numberOfCopies == 0) {
        return destination;
    }

    for(int c = beginIndexSource; c<numberOfCopies; c++) {
        destination[c] = source[c];
    }

    return destination;
}