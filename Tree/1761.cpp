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
    queue<int> q;
    q.push(1);
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    dist[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].to;
            int cost = g[now][i].cost;
            if(!check[next]){
                check[next] = true;
                parent[next] = now;
                depth[next] = depth[now] + 1;
                dist[next] = cost;
                q.push(next);
            }
        }
    }
}
int LCA(vector<edge>* g, int* parent, int* depth, int* dist, int a, int b){
    int distance = 0;
    if(depth[a] < depth[b])
        swap(a,b);
    
    while(depth[a] != depth[b]){
        distance += dist[a];
        a = parent[a];
    }
    
    while(a != b){
        distance += (dist[a]+dist[b]);
        a = parent[a];
        b = parent[b];
    }
    return distance;
}
int main(){
    int N, M, a, b, c;
    cin >> N;
    vector<edge> g[N+1];
    int parent[N+1]={0,};
    int depth[N+1]={0,};
    int dist[N+1]={0,};
    for(int i=1;i<N;i++){ 
        cin >> a >> b >> c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    BFS(g, parent, depth, dist, N);
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        cout << LCA(g, parent, depth, dist, a, b) << "\n";
    }
    return 0;
}