#include <iostream>
#include <string>
#include "BinarySearch.h"

using namespace std;

int binarySearchOnData(int data[], int arraySize, int value)
{
    int first, middle, last;
    first = 0;
    last = arraySize - 1;
    while(true)
    {
        middle = (first + last) / 2;
        if (data[middle] == value)
            return middle;
        else if (first >last)
            return -1;
        else if (value < data[middle])
            last = middle - 1;
        else
            first = middle + 1;
    }
    return -1;
}
