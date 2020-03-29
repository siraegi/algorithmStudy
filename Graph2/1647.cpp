/*
    BOJ 1647.cpp
    도시 분할 계획 - MST(Kruscal's Algorithm)
    https://www.acmicpc.net/problem/1647
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> edge;
struct cmp{
    bool operator()(pair<int,edge> a, pair<int,edge> b){
        return a.first > b.first;
    }
};
struct OptimizedDisjointSet{
    vector<int> parent, height;
    OptimizedDisjointSet(int n) : parent(n+1), height(n+1, 1){
        for(int i=1;i<=n;i++)
            parent[i] = i;
    }
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(height[x]>height[y])
            swap(x,y);
    
        parent[x]=y;
        if(height[x]==height[y])
            height[x]++;
    };
};
int Kruscal(priority_queue<pair<int, edge>,vector<pair<int, edge>>, cmp> q, int n){
    OptimizedDisjointSet disjointset(n);
    int cost = 0;
    int cnt = 2;
    while(cnt < n){
        int c = q.top().first;
        edge now = q.top().second;
        int x = now.first;
        int y = now.second;
        q.pop();
        if(disjointset.find(x)!=disjointset.find(y)){
            disjointset.merge(x,y);
            cost += c;
            cnt++;
        }
    }
    return cost;
}
int main(){
    int N, M;
    cin >> N >> M;
    priority_queue<pair<int, edge>,vector<pair<int, edge>>, cmp> g;
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge e = make_pair(a,b);
        g.push(make_pair(c,e));
    }
    cout << Kruscal(g, N);
    return 0;
}