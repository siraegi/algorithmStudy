/*
    BOJ 1167.cpp
    트리의 지름 - BFS
    https://www.acmicpc.net/problem/1167
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> edge; // (next node, cost)
long long ans;
int BFS(vector<edge> *g, int n, int start){
    bool check[n+1] = {false,};
    long long dist[n+1] = {0,};
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].first;
            int cost = g[now][i].second;
            if(!check[next]){
                dist[next] = dist[now] + cost;
                check[next] = true;
                q.push(next);
            }
        }
    }
    int maxDistIndex = distance(dist, max_element(dist, dist+n+1));
    ans = dist[maxDistIndex];
    return maxDistIndex;
}
int main(){
    int V, a, b, c;
    cin >> V;
    vector<edge> g[V+1];
    
    for(int i=0;i<V;i++){
        cin >> a;
        while((cin >> b) && b != -1){
            cin >> c;
            edge e = make_pair(b,c);
            g[a].push_back(e);
        }
    }
    // s : 임의의 정점 1에서 가장 먼 정점
    int s = BFS(g, V, 1);
    // s에서 가장 먼 정점 구하고 그 사이 거리를 구하면 트리의 지름
    BFS(g, V, s);
    cout << ans;
    return 0;
}