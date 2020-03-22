/*
    BOJ 1260.cpp
    DFS와 BFS
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
    visit[start] = true;
    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        visit[node] = true;
        q.pop();
        for(int i=0;i<g[node].size();i++){
            if(!visit[g[node][i]]){
                q.push(g[node][i]);
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

    // 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
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