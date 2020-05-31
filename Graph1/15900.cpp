/*
    https://www.acmicpc.net/problem/15900
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[500001];
bool check[500001];
long long cnt = 0;
//long long height[500001];
void DFS(int u, int h)
{
    if(g[u].size()==1 && u!=1)
        cnt += h;
    check[u] = true;
    //height[u] = h;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(!check[v])
            DFS(v, h+1);
    }
}
int main(){
    int n;
    cin >> n;
    int a,b;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1,0);
    
    // for(int i=2;i<=n;i++)
    // {
    //     cnt += height[i];
    //     cout << height[i]<<" ";
    // }
    if(cnt%2) cout << "Yes";
    else cout << "No";
    return 0;
}