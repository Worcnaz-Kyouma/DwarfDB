#ifndef DWARFDB_UTILS_H
#define DWARFDB_UTILS_H

class Utils {
public:
    template<typename T>
    int executeBinarySearch(int value, T** source, int sourceSize); 

    static void** copyArray(void** destination, int destinationSize, void** source, int beginIndexSource = 0);
};

#endif