#include<bits/stdc++.h>

#define White 1
#define Black 2
#define Grey 3

using namespace std;

int a[100][100], color[100], parent[100], dis[100],m1=0,m2=0,maxn=0;

void BFS(int st,int v);
int main()
{
    int v,e,i,n1,n2,st;
    printf("Enter the vertices numbers: ");
    scanf("%d",&v);

    printf("\nEnter the edges numbers: ");
    scanf("%d",&e);

    printf("\nEnter the edges: \n");
    for(i=0; i<e; i++)

    {
        scanf("%d %d",&n1,&n2);
        if(m1<n1) m1 = n1;
        if(m2<n2) m2 = n2;

        a[n1][n2] = 1;
        a[n2][n1] = 1;
    }
    printf("\nEnter the starting node: ");
    scanf("%d",&st);
    if(m1>m2) maxn = m1;
    else if(m1<m2) maxn = m2;
    else maxn = m1;

    BFS(st,v);
    return 0;

}



void BFS(int st,int v)

{
    int i,j,z[v],c=0;
    for(i=0; i<=maxn; i++)
    {
        color[i] = White;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }

    dis[st] = 0;
    parent[st] = -1;
    queue <int> q;
    q.push(st);

    printf("\nThe BFS for the given graph: ");

    while(!q.empty())

    {
        int x = q.front();
        z[c++] = x;
        q.pop();
        color[x] = Grey;
        for(i=0; i<=maxn; i++)

        {
            if(a[x][i]==1)

            {
                if(color[i]==White)

                {
                    parent[i] = x;
                    dis[i] = dis[x]+1;
                    q.push(i);
                }
            }
        }
        color[x] = Black;
    }

    printf("%d ",z[0]);

    for(i=1; i<c; i++)

    {
        for(j=i; j>=0; j--)
        {
            if(z[j-1]==z[i])
            {
                z[i] = -2;
                break;
            }
        }

        if(z[i]==-2) continue;
        else printf("%d ",z[i]);
    }
}
