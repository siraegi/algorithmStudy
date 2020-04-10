/*
    BOJ 11725.cpp
    트리의 부모 찾기 - BFS
    https://www.acmicpc.net/problem/11725
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<int> *g, int n, int *parent){
    bool check[n+1] = {false,};
    queue<int> q;
    q.push(1);
    check[1] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            if(!check[next]){
                check[next] = true;
                parent[next] = now;
                q.push(next);
            }
        }
    }
}
int main(){
    int n, a, b;
    cin >> n;
    vector<int> g[n+1];
    int parent[n+1];
    for(int i=1;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(g, n, parent);
    for(int i=2;i<=n;i++){
        cout << parent[i] << "\n";
    }
    return 0;
}