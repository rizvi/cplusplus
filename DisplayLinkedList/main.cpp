#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
}

void display(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p) {
    if(p!=NULL) {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

void recursiveDisplay2nd(struct Node *p) {
    if(p!=NULL) {
        recursiveDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    cout << "Hello world!" << endl;
    create(A, 5);
    display(first);

    cout << endl;
    cout << "Recursive Display: " << endl;
    recursiveDisplay(first);

    cout << endl;
    cout << "Recursive Display 2nd: " << endl;
    recursiveDisplay2nd(first);
    return 0;
}
