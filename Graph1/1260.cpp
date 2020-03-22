/*
    BOJ 1260.cpp
    DFS¿Í BFS
    https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[1001];
vector<int> g[1001];
void DFS(int node){
    cout << node << " ";
    visit[node] = true;
    for(int i=0;i<g[node].size();i++){
        if(!visit[g[node][i]]){
            DFS(g[node][i]);
        }
    }
}
void BFS(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        visit[node] = true;
        q.pop();
        for(int i=0;i<g[node].size();i++){
            if(!visit[g[node][i]]){
                q.push(g[node][i]);
                visit[g[node][i]] = true;
            }
        }
    }
}
int main(){
    int N, M, V;
    cin >> N >> M >> V;
    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=N;i++){
        sort(g[i].begin(), g[i].end()); 
    }

    DFS(V);
    cout << endl;
    memset(visit, false, sizeof(visit));
    BFS(V);
    cout << endl;
    return 0;
}