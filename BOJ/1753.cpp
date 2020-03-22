//
//  1753.cpp
//  Shortest Path - Dijkstra Algorithm
//
//  Created by ShiHaYeon on 15/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int V, E, S;
    cin >> V >> E >> S;
    // {cost, node}
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<pair<int, int>> g[V+1];
    vector<int> path(V+1,0x7FFFFFFF); //shortest path initialized with INF
    path[S]=0;
    int x, y, c;
    for(int i=0;i<E;i++){
        cin >> x >> y >> c;
        g[x].push_back({y,c});
        //g[y].push_back({x,c});
    }
    
    q.push({0, S});
    while(!q.empty()){
        int cost = q.top().first;
        int node = q.top().second;
        q.pop();
        for(int i=0;i<g[node].size();i++){
            int ncost = g[node][i].second + cost;
            int nnode = g[node][i].first;
            if(ncost < path[nnode]){
                path[nnode] = ncost;
                q.push({ncost, nnode});
            }
        }
    }
    
    
    for(int i=1;i<=V;i++){
        if(path[i]==0x7FFFFFFF)
            cout << "INF"<<"\n";
        else cout << path[i]<<"\n";
    }
    
    return 0;
}
