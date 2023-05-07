#include "iostream"

using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *headPtr;
    Node *tailPtr;

public:
    LinkedList();
    void insert_begin(int item);
    void insert_end(int item);
    void delete_first_node();
    void delete_last_node();
    void display();
};

LinkedList:: LinkedList()
{
    headPtr = NULL;
    tailPtr = NULL;
}

void LinkedList::insert_begin(int item)
{
    Node *temp = new Node;
    temp->data= item;

    temp->next= headPtr;
    if(headPtr == NULL)
    {
        tailPtr = temp;
    }
    headPtr = temp;
}

void LinkedList :: insert_end(int item)
{
    Node *temp = new Node;
    temp->data = item;

    temp->next = NULL;
    if (headPtr == NULL)
    {
        headPtr = temp;
    }
    else
    {
        tailPtr->next = temp;
    }

    tailPtr = temp;
}

//Delete first node of the list
void LinkedList :: delete_first_node()
{
    if(headPtr != NULL)
    {
        Node* temp = headPtr;
        headPtr = headPtr->next;
        free(temp);
    }
}

//Delete last node of the list
void LinkedList :: delete_last_node()
{
    Node *temp = new Node();
    temp = headPtr;
    while(temp->next != NULL)
    {
        tailPtr = temp;
        temp = temp->next;
    }
    tailPtr->next = NULL;
    delete temp;
}

void LinkedList:: display()
{
    Node *temp= new Node;
    temp=headPtr;

    while (temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}


int main ()
{
    LinkedList ob1;
    int a;
    cout << "Enter 3 integer data for inserting begin of the Linkedlist" << endl;
    for (int i=0; i<3; i++)
    {
        cin >> a;
        ob1.insert_begin (a);
    }

    cout<< "Display: " << endl;
    ob1.display ();
    cout<< endl;
    cout << "*****************************************************************" <<endl;
    int b;
    cout << "Enter 3 integer data for inserting end of the Linkedlist" << endl;
    for (int i=0; i<3; i++)
    {
        cin >> b;
        ob1.insert_end (b);
    }

    cout<< "Display: " << endl;
    ob1.display ();
    cout<< endl;
    cout << "*****************************************************************" <<endl;
    cout<< "Remove first Node: " << endl;
    ob1.delete_first_node();
    cout<< "Display: " << endl;
    ob1.display ();
    cout<< endl;
    cout << "*****************************************************************" <<endl;
    cout<< "Remove last Node: " << endl;
    ob1.delete_last_node();
    cout<< "Display: " << endl;
    ob1.display ();
    cout<< endl;
    cout << "*****************************************************************" <<endl;

}
