//
//  6118.cpp
//  Dijkstra Algorithm
//
//  Created by ShiHaYeon on 09/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    // 다음 방문할 최단거리인 노드를 빨리 찾기 위해
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> g[N+1];
    int distance[N+1]; // 최단거리
    
    int x, y;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=2;i<=N;i++)
        distance[i] = 0x7FFFFFFF;
    
    // (cost, node)
    pq.push({0,1}); // node 1 자기 자신에게 가는 비용은 0
    distance[1] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second; //current node
        int cost = pq.top().first; //current node to 1 's cost
        pq.pop();
        
        if(distance[node] < cost)
            continue;
        
        for (int i=0; i<g[node].size(); i++) {
            int nnode = g[node][i];
            int ncost = cost + 1;
            if(ncost < distance[nnode]){
                distance[nnode] = ncost;
                pq.push({ncost, nnode});
            }
        }
//        for(int i=1;i<=N;i++)
//            cout << distance[i]<<" ";
//        cout <<endl;
    }
    
    int cnt = 1;
    int ans = 1;
    for(int i=2;i<=N;i++){
        if(distance[i]>distance[ans]){
            cnt = 1;
            ans = i;
        }
        else if(distance[i]==distance[ans])
            cnt++;
    }
    cout << ans << " "<< distance[ans] << " "<< cnt<<endl;
    return 0;
}
