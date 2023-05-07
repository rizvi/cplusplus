#include <iostream>

using namespace std;

// Node class for the singly LinkedList
class Node
{
public:
    int data;
    Node* next;
// Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};


// Singly LinkedList class
class LinkedList
{
private:
    Node* head;
public:
// Constructor
    LinkedList()
    {
        head = nullptr;
    }
// Insert an item at the beginning of the list
    void insertBegin(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
// Insert an item at the end of the list
    void insertEnd(int data)
    {
        Node* newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }
// Display the list
    void display()
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
// Search for an item in the list
    bool search(int data)
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            if (currentNode->data == data)
            {
                return true;
            }
            currentNode = currentNode->next;
        }
        return false;
    }
// Delete an item from the beginning of the list
    void deleteBegin()
    {
        if (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
// Delete an item from the end of the list
    void deleteEnd()
    {
        if (head != nullptr)
        {
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node* currentNode = head;
                while (currentNode->next->next != nullptr)
                {
                    currentNode = currentNode->next;
                }
                delete currentNode->next;
                currentNode->next = nullptr;
            }
        }
    }
};
int main()
{
    LinkedList list;

// Insert items at the beginning of the list
    int num_of_items;
    cout << "Enter the number of items to insert at the beginning of the list: ";
    cin >> num_of_items;
    for (int i = 0; i < num_of_items; i++)
    {
        int item;
        cout << "Enter item " << i + 1 << ": ";
        cin >> item;
        list.insertBegin(item);
    }
    cout <<"*******************************************************************"<<endl;
// Display the list
    cout << "List: ";
    list.display();
    cout <<"*******************************************************************"<<endl;
// Insert items at the end of the list
    cout << "Enter the number of items to insert at the end of the list: ";
    cin >> num_of_items;
    for (int i = 0; i < num_of_items; i++)
    {
        int item;
        cout << "Enter item " << i + 1 << ": ";
        cin >> item;
        list.insertEnd(item);
    }
    cout <<"*******************************************************************"<<endl;
// Display the list
    cout << "List: ";
    list.display();
    cout <<"*******************************************************************"<<endl;
// Search for an item
    int search_item;
    cout << "Enter an item to search for: ";
    cin >> search_item;
    if (list.search(search_item))
    {
        cout << search_item << " found in the list." << endl;
    }
    else
    {
        cout << search_item << " not found in the list." << endl;
    }
    cout <<"*******************************************************************"<<endl;
// Delete items from the beginning of the list
    int num_delete;
    cout << "Enter the number of items to delete from the beginning of the list: ";
    cin >> num_delete;
    for (int i = 0; i < num_delete; i++)
    {
        list.deleteBegin();
    }
    cout <<"*******************************************************************"<<endl;
    // Display the list after deletion
    cout << "List after deletion: ";
    list.display();
    cout <<"*******************************************************************"<<endl;
// Delete items from the end of the list
    cout << "Enter the number of items to delete from the end of the list: ";
    cin >> num_delete;
    for (int i = 0; i < num_delete; i++)
    {
        list.deleteEnd();
    }
    cout <<"*******************************************************************"<<endl;
// Display the list after deletion
    cout << "List after deletion: ";
    list.display();
    cout <<"*******************************************************************"<<endl;
    return 0;
}
