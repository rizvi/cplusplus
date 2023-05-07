#include <iostream>

using namespace std;

int binarySearchOnData(int data[], int value, int low, int high)
{
    while(high >= low)
    {
        cout <<"low is: "<<low<<endl;
        cout <<"high is: "<<high<<endl;
        int middle = low + (high - low) / 2;
        if (data[middle] == value)
            return middle;
        if (value > data[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}

int main()
{
    int a[7] = {23, 34, 45, 56, 67, 78, 89};
    int position = 0;
    int numOfArray = sizeof(a)/sizeof(a[0]);
    int searchData = 34;
    position = binarySearchOnData(a, searchData, 0, numOfArray-1);
    cout<< "Position is: " <<position <<endl;
    if(position>=0)
    {
        cout<< searchData<< " Data is found at the position: " <<position << endl;
    }
    else
    {
        cout<<  searchData<< " Data is not found"<< endl;
    }

    return 0;
}


