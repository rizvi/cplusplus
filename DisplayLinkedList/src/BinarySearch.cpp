#include<iostream>

using namespace std;

int main()
{
    int a[] = {23, 34, 45, 56, 67, 78, 89};
    boolean isFound = binarySearchOnData(a, 7, 67);
    cout << "Data is "+isFound<< endl
    return 0;
}

void binarySearchOnData(int data[], int arraySize, int value)
{
    int first, middle, last;
    first = 0;
    last = arraySize - 1;
    while (true)
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

}
