#include <iostream>

#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

int adj[100][100];
int node, edge;
int color[100];


int Time = 1;
int startingTime[100];
int finishingTime[100];

void dfsVisit(int val) {
    color[val] = GRAY;
    startingTime[val] = Time;
    Time++;
    // work
    for(int i=0; i<node; i++) {
        if(adj[val][i] == 1) {
            if(color[i] == WHITE) {
                dfsVisit(i);
            }
        }
    }
    color[val] = BLACK;
    finishingTime[val] = Time;
    Time++;
}
void dfs(){
    for(int i=0; i<node; i++) {
        color[i] = WHITE;
    }

    for(int i=0; i<node; i++) {
        if(color[i]== WHITE) {
            dfsVisit(i);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> node;
    cin >> edge;

    cout << "Number of Nodes: "<< node <<endl;
    cout << "Number of edges: "<<edge<<endl;

    int startPoint, endPoint;
    for(int i =0; i< edge; ++i)
    {
        cin >> startPoint;
        cin >> endPoint;
        adj[startPoint][endPoint] = 1;
        adj[endPoint][startPoint] = 1;
    }

    cout << "Adjacent Matrix Representation: " <<endl;
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "" <<endl;
    }
    int value = 0;
    cout << "Adjacent Matrix of your given value. Please input: " <<endl;
    cin >> value;
    for(int i=0; i<node; i++)
    {
        if(adj[value][i] == 1)
        {
            cout << value << "  "<< i << endl;
        }
    }

    dfs();
    for(int i=0; i<node; i++) {
        cout << "Node: " << (char) ('A' +i) << " "<<startingTime[i] << " " << finishingTime[i] << endl;
    }
    return 0;
}
/* Construct the following tree
              0
            /   \
           /     \
          2 _ _ _ 1
                 / \
                /   \
               3 _ _ 4

Number of Nodes= 5
Number of Edges = 6

Nodes Edges
----------
5 - 6
----------
0 - 1
0 - 2
1 - 2
1 - 3
1 - 4
3 - 4
---------


   */



