#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("graf.in");

using namespace std;

const int NMAX = 100005, INF=1e9;
int viz[NMAX + 1], P1[NMAX+1], P2[NMAX+1];
int n,m;
vector<int> G[NMAX + 1], T1[NMAX + 1], T2[NMAX + 1];

void Citire()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int y, x;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void BFS(int x){
    queue <int> q;
    q.push(x);
    viz[x]=1;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(auto next: G[x]){
            if(!viz[next]){
                P1[next]=x;
                q.push(next);
                viz[next]=1;
                T1[x].push_back(next);
                T1[next].push_back(x);
            }
        }
    }
}

void DFS(int x)
{
    viz[x]=1;

    for(auto y: G[x])
        if(viz[y]==0)
        {
            P2[y]=x;
            T2[x].push_back(y);
            T2[y].push_back(x);
            DFS(y);
        }
}
int main()
{
    Citire();
    BFS(1);
    for(int i=1; i<=n; i++)
        viz[i]=0;

    DFS(1);
    for(int i=1; i<=n; i++)
        if(viz[i]==0)
    {
        cout<<"Nu\n";
        return 0;
    }
    bool ok=0;

    for(int i=1; i<=n&&ok==0; i++)
        if(P1[i]!=P2[i])
            ok=1;
    if(ok==0)
        cout<<"Nu\n";
    else
    {
        cout<<"Da\n";

        for(int x=1; x<=n; x++)
        {
            for(auto y: T1[x])
                cout<<y<<" ";
            cout<<"\n";
        }

        for(int x=1; x<=n; x++)
        {
            for(auto y: T2[x])
                cout<<y<<" ";
            cout<<"\n";
        }




    }
    return 0;
}
