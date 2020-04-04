/*
    BOJ 1753.cpp
    최단경로 - Dijkstra’s Algorithm
    https://www.acmicpc.net/problem/1753
    출력할 때 endl 대신 \n 써서 시간초과 해결
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<int, int> edge; // next node, cost
vector<edge> g[20001]; // g[x]={ (y, c), ... } x->y (cost : c)
int dist[20001]; // dist[i] : 시작점에서 i로 가는 최단거리
void Dijkstra(int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //(dist[i], i)
    q.push({0, s});
    dist[s] = 0;
    while(!q.empty()){
        int now = q.top().second;
        int nowDist = q.top().first;
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].first;
            int cost = g[now][i].second;
            if(nowDist + cost < dist[next]){
                dist[next] = nowDist + cost;
                q.push({dist[next], next});
            }
        }
    }
}
int main(){
    int V, E, start;
    cin >> V >> E >> start;
    for(int i=0;i<E;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(edge(b,c));
    }
    int INF = 0x7FFFFFFF;
    fill(dist, dist+V+1, INF);
    Dijkstra(start);
    for(int i=1;i<=V;i++){
        if(dist[i]==INF)
            cout << "INF" << "\n";
        else cout << dist[i] << "\n";   
    }
    return 0;
}
