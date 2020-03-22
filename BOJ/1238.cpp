//
//  1238.cpp
//  Dijkstra Algorithm
//
//  Created by ShiHaYeon on 10/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, X;
vector<pair<int,int>> fg[1004]; // forwardgraph[source]={(destination,cost),...}
vector<pair<int,int>> bg[1004]; // backwardgraph[destination]={(source,cost),...}
// source node, # of nodes
vector<int> Dijkstra1(int s, int n){
    // 다음 방문할 최단거리인 노드를 빨리 찾기 위해 (cost, node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(n+1, 0x7FFFFFFF); // 최단거리
    distance[s] = 0;
    // (cost, node)
    pq.push({0,s}); // node s 자기 자신에게 가는 비용은 0
    while(!pq.empty()){
        int node = pq.top().second; //current node
        int cost = pq.top().first; //current node to s 's cost
        pq.pop();

        if(distance[node] < cost)
            continue;
                
        for (int i=0; i<fg[node].size(); i++) {
            int nnode = fg[node][i].first;
            int ncost = cost + fg[node][i].second;
            if(ncost < distance[nnode]){
                distance[nnode] = ncost;
                pq.push({ncost, nnode});
            }
        }
//        for(int i=1;i<=n;i++)
//            cout << distance[i]<<" ";
//        cout <<endl;
    }
    return distance;
}
vector<int> Dijkstra2(int s, int n){
    // 다음 방문할 최단거리인 노드를 빨리 찾기 위해 (cost, node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
    vector<int> distance(n+1, 0x7FFFFFFF); // 최단거리
    distance[s] = 0;
    // (cost, node)
    pq2.push({0,s}); // node s 자기 자신에게 가는 비용은 0
    while(!pq2.empty()){
        int node = pq2.top().second; //current node
        int cost = pq2.top().first; //current node to s 's cost
        pq2.pop();

        if(distance[node] < cost)
            continue;
                
        for (int i=0; i<bg[node].size(); i++) {
            int nnode = bg[node][i].first;
            int ncost = cost + bg[node][i].second;
            if(ncost < distance[nnode]){
                distance[nnode] = ncost;
                pq2.push({ncost, nnode});
            }
        }
//        for(int i=1;i<=n;i++)
//            cout << distance[i]<<" ";
//        cout <<endl;
    }
    return distance;
}
int main(){
    
    cin >> N >> M >> X;
    
    int x, y, c;
    for (int i=0; i<M; i++) {
        cin >> x >> y >> c;
        fg[x].push_back({y,c});
        bg[y].push_back({x,c});
    }
    //cout << "goHome\n";
    vector<int> goHome = Dijkstra1(X, N);
    //cout << "goParty\n";
    vector<int> goParty = Dijkstra2(X, N);
    int max = 0x80000000;
    
    for(int i=1;i<=N;i++){
        //cout << goHome[i] <<" "<<goParty[i]<<endl;
        int cost = goHome[i]+goParty[i];
        if(cost > max){
            max = cost;
        }
    }
    cout << max << endl;
    return 0;
}
