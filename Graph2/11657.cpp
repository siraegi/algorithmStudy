/*
    BOJ 11657.cpp
    타임머신 - Bellman-Ford Algorithm
    https://www.acmicpc.net/problem/11657
*/
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> edge; // next node, cost
vector<edge> g[504]; // g[x]={ (y, c), ... } x->y (cost : c)
int dist[504]; // dist[i] : 시작점에서 i로 가는 최단거리
void BellmanFord(int V, int s) {
    dist[s] = 0;
    bool Ncycle = false;
    for(int v=1;v<=V;v++){
        for(int i=1;i<=V;i++){
            for(int j=0;j<g[i].size();j++){
                int next = g[i][j].first;
                int cost = g[i][j].second;
                if(dist[i]!=0x7FFFFFFF && dist[i]+cost < dist[next]){
                    dist[next] = dist[i] + cost;
                    if(v==V) Ncycle = true;
                }
            }
        }
    }
    if(Ncycle) cout << -1;
    else{
        for(int i=2;i<=V;i++){
            if(dist[i] == 0x7FFFFFFF)
                cout << -1 << endl;
            else
                cout << dist[i] << endl;
        }
    }
}
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(edge(b,c));
    }
    int INF = 0x7FFFFFFF;
    fill(dist, dist+N+1, INF);
    BellmanFord(N, 1);
    //return 0;
}
