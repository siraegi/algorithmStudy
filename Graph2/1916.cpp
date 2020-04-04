/*
    BOJ 1916.cpp
    최소비용 구하기 - Dijkstra’s Algorithm
    https://www.acmicpc.net/problem/1916
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef pair<int, int> edge; // next node, cost
vector<edge> g[1004]; // g[x]={ (y, c), ... } x->y (cost : c)
int dist[1004]; // dist[i] : 시작점에서 i로 가는 최단거리
//int path[1004]; // prev node
int check[1004]; // priority queue를 써서 check 배열을 사용할 필요는 없는데 시간이 조금 덜 걸린다.
int Dijkstra(int a, int b) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; //(dist[i], i)
    q.push({0, a});
    dist[a] = 0;
    while(!q.empty()){
        int now = q.top().second;
        q.pop();
        check[now] = true;
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].first;
            int cost = g[now][i].second;
            if (check[next]) continue;
            if(dist[now] + cost < dist[next]){
                dist[next] = dist[now] + cost;
                q.push({dist[next], next});
            }
        }
    }
    return dist[b];
}
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(edge(b,c));
    }
    int A, B;
    cin >> A >> B;
    fill(dist, dist+N+1, 0x7FFFFFFF);
    cout << Dijkstra(A,B);
    return 0;
}
