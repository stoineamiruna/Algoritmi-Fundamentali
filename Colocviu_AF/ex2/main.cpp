#include <bits/stdc++.h>
using namespace std;
ifstream fin("graf.in");
const int N = 100005, Inf=1e9;
vector<int> G[N];
vector<int> viz(N, 0);
vector<int> cost(N, 0), activitati_critice;
int d[N], d2[N], tata[N], tata2[N], grad_intern[N], grad_extern[N];
stack<int> S;
int n, m, k, s;

void Citire(){

    cin>>n>>m>>k;
    s=n+1;
    for(int i=1; i<=k; i++){
        int x;
        cin>>x;
        G[s].push_back({x});
    }

    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        G[y].push_back({x});
    }
    n++;

}


void DFS(int x) {
    viz[x] = 1;

    for (const auto y : G[x]) {
        if (!viz[y]) {
            DFS(y);
        }
    }

    S.push(x);
}


void SortTop() {
    for (int i=1; i<=n; ++i) {
        if (!viz[i]) {
            DFS(i);
        }
    }
}

void DAG(){
    for(int i=1; i<=n; i++)
    {
        d[i]=-Inf;
        tata[i]=0;
    }

    d[s]=0;

    SortTop();

    while (!S.empty()) {
        int x=S.top();
        for (const auto& y : G[x])
        {
            if(d[x]+1>d[y]){
                d[y]=d[x]+1;
                tata[y]=x;
            }
        }
        S.pop();
    }

}

void Lant(int x, int par[]) {
    if (x == s) {
        return;
    }
    cout << x << " ";

    Lant(par[x], par);

}

int main()
{
    Citire();
    DAG();
    int vmax=-1, nod;
    for(int i=1; i<=n; i++)
        if(vmax<d[i]){
            vmax=d[i];
            nod=i;
        }
    cout<<vmax-1<<"\n";
    Lant(nod, tata);
    return 0;
}
