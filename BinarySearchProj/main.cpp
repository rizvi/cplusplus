#include <iostream>

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

int main()
{
    int a[7] = {23, 34, 45, 56, 67, 78, 89};
    int position = 0;
    int numOfArray = sizeof(a)/sizeof(a[0]);
    position = binarySearchOnData(a, numOfArray, 89);
    cout<< "Position is: " <<position <<endl;
    if(position>=0) {
        cout<< "Data is found at the position: " <<position+1 << endl;
    } else {
        cout<< "Data is not found"<< endl;
    }

    return 0;
}


