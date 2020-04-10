/*
    BOJ 11437.cpp
    LCA - Lowest Common Ancestor
    https://www.acmicpc.net/problem/11437
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<int>* g, int* parent, int* depth, int n){
    bool check[n+1]={false,};
    queue<int> q;
    q.push(1);
    check[1] = true;
    depth[1] = 0;
    parent[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            if(!check[next]){
                check[next] = true;
                parent[next] = now;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
}
int LCA(vector<int>* g, int* parent, int* depth, int a, int b){
    if(depth[a] < depth[b])
        swap(a,b);
    
    while(depth[a] != depth[b])
        a = parent[a];
    
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}
int main(){
    int N, M, a, b;
    cin >> N;
    vector<int> g[N+1];
    int parent[N+1]={0,};
    int depth[N+1]={0,};
    for(int i=1;i<N;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    BFS(g, parent, depth, N);
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        cout << LCA(g, parent, depth, a, b)<<"\n";
    }
    return 0;
}