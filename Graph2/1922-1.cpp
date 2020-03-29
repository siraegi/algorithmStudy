/*
    BOJ 1922.cpp
    네트워크 연결 - MST(Prim's Algorithm)
    https://www.acmicpc.net/problem/1922
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> edge; // (next node, weight)
struct cmp {
    bool operator()(edge a, edge b){
        return a.second > b.second;
    }
};
int Prim(vector<edge> *g, int n, int start){
    priority_queue<edge, vector<edge>, cmp> q;
    bool visit[n+1] = {false,};
    visit[start] = true;
    for(int i=0;i<g[start].size();i++)
        q.push(g[start][i]);
    
    int cost = 0;
    while(!q.empty()){
        edge now = q.top();
        q.pop();
        if(!visit[now.first]){
            cost += now.second;
            visit[now.first] = true;
            for(int i=0;i<g[now.first].size();i++){
                q.push(g[now.first][i]);
            }
        }
    }
    return cost;
}
int main(){
    int N, M;
    cin >> N >> M;
    int a,b,c;
    vector<edge> g[N+1];
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }

    cout << Prim(g,N,1);

    return 0;
}