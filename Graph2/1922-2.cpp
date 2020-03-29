/*
    BOJ 1922-2.cpp
    네트워크 연결 - MST(Kruscal's Algorithm)
    https://www.acmicpc.net/problem/1922
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> edge; // (next node, weight)
struct cmp {
    bool operator()(pair<int,edge> a, pair<int,edge> b){
        return a.first > b.first;
    }
};
struct OptimizedDisjointSet {
    vector<int> parent, height;
    OptimizedDisjointSet(int n) : parent(n+1), height (n+1,1){
        for(int i=1;i<=n;i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        
        if(x==y) return;
        // tree의 height가 더 낮은 트리를 높은 트리의 자식으로
        if(height[x]>height[y])
            swap(x, y);
        
        parent[x] = y;
        if(height[x]==height[y])
            height[x]++;
    }
};
int Kruscal(priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> q, int n){
    OptimizedDisjointSet disjointset(n);
    int cost = 0;
    while(!q.empty()){
        //priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> p=q;
        // for(int i=0;i<q.size();i++){
        //     cout << p.top().second.first <<"-"<<p.top().second.second<<", ";
        //     p.pop();
        // }
        edge now = q.top().second;
        int c = q.top().first;
        int x = now.first;
        int y = now.second;
        q.pop();
        if(disjointset.find(x) != disjointset.find(y)){
            disjointset.merge(x, y);
            //cout << x << "-" << y << ":"<<c<<endl;
            cost += c;
        }
    }

    return cost;
}
int main(){
    int N, M;
    cin >> N >> M;
    int a,b,c;
    priority_queue<pair<int, edge>, vector<pair<int, edge>>, cmp> g;
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        edge e = make_pair(a,b);
        g.push(make_pair(c,e));
    }

    cout << Kruscal(g,N);

    return 0;
}