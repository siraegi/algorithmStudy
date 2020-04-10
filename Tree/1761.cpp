/*
    BOJ 1761.cpp
    정점들의 거리 - LCA
    https://www.acmicpc.net/problem/1761
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge{
    int to, cost;
    edge(int to, int cost) : to(to), cost(cost){
    }
};
void BFS(vector<edge>* g, int* parent, int* depth, int* dist, int n){
    bool check[n+1]={false,};
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].to;
            int cost = g[now][i].cost;
            if(!check[next]){
                check[next] = true;
                parent[next] = now;
                dist[next] = cost;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
}
int LCA(int* parent, int* depth, int* dist, int a, int b){
    int distance = 0;
    if(depth[a]<depth[b])
        swap(a,b);
    while(depth[a]!=depth[b]){
        distance += dist[a];
        a = parent[a];
    }
    while(a!=b){
        distance += (dist[a]+dist[b]);
        a = parent[a];
        b = parent[b];
    }
    return distance;
}
int main(){
    int n, m, a, b, c;
    cin >> n;
    vector<edge> g[n+1];
    int depth[n+1]={0,};
    int dist[n+1]={0,};
    int parent[n+1]={0,};
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    BFS(g,parent,depth,dist,n);
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << LCA(parent, depth, dist, a, b) << "\n";
    }
    return 0;
}