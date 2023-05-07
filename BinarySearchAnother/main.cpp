#include <iostream>
#include <string>
#include "BinarySearch.h"

using namespace std;

int main()
{
    int a[7] = {23, 34, 45, 56, 67, 78, 89};
    int position = 0;
    int numOfArray = sizeof(a)/sizeof(a[0]);
    position = binarySearchOnData(a, numOfArray, 89);
    cout<< "Position is: " <<position <<endl;
    if(position>=0)
    {
        cout<< "Data is found at the position: " <<position+1 << endl;
    }
    else
    {
        cout<< "Data is not found"<< endl;
    }

    return 0;
}
