#include <iostream>
#include <vector>
using namespace std;

// SortedList Class
class SortedList
{

private:
    vector<int> items;

public:
// Constructor
    SortedList()
    {
        items.clear();
    }
// Insert an item into the SortedList
    void insert(int item)
    {
        int pos = 0;
        while (pos < items.size() && items[pos] < item)
        {
            pos++;
        }
        items.insert(items.begin() + pos, item);
    }
// Search for an item in the SortedList
    bool search(int item)
    {
        int left = 0, right = items.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (items[mid] == item)
            {
                return true;
            }
            else if (items[mid] < item)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
// Delete an item from the SortedList
    void remove(int item)
    {
        int pos = 0;
        while (pos < items.size() && items[pos] < item)
        {
            pos++;
        }
        if (pos < items.size() && items[pos] == item)
        {
            items.erase(items.begin() + pos);
        }
    }
// Print the SortedList
    void print()
    {
        for (int i = 0; i < items.size(); i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    SortedList list;
// Item Insertion
    int num_of_items;
    cout << "Enter the number of items to insert into the list: ";
    cin >> num_of_items;
    for (int i = 0; i < num_of_items; i++)
    {
        int item;
        cout << "Enter item " << i + 1 << ": ";
        cin >> item;
        list.insert(item);
    }
    cout <<"*******************************************************************"<<endl;
    // Print the SortedList
    cout << "SortedList: ";
    list.print();
    cout <<"*******************************************************************"<<endl;
// Search for an item in Sorted List
    int search_item;
    cout << "Enter an item to search for: ";
    cin >> search_item;
    if (list.search(search_item))
    {
        cout << search_item << " is found in the list" << endl;
    }
    else
    {
        cout << search_item << " is not found in the list" << endl;
    }
    cout <<"*******************************************************************"<<endl;
// Delete an item from SortedList
    int delete_item;
    cout << "Enter an item to delete from the list: ";
    cin >> delete_item;
    list.remove(delete_item);
    cout <<"*******************************************************************"<<endl;
// Print the SortedList
    cout << "SortedList: ";
    list.print();
    cout <<"*******************************************************************"<<endl;
    return 0;
}
