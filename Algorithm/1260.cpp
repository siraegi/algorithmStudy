//
//  1260.cpp
//  Algorithm
//
//  Created by ShiHaYeon on 02/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visit[1001];
void dfs(vector<vector<int>>& g, int n){
    if(visit[n]) return;
    cout << n << " ";
    visit[n]=true;
    for(int i=0;i<g[n].size();i++)
        dfs(g, g[n][i]);
}
void bfs(vector<vector<int>>& g, int n){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        n = q.front();
        q.pop();
        visit[n]=true;
        cout << n << " ";
        for(int i=0;i<g[n].size();i++){
            if(!visit[g[n][i]]){
                q.push(g[n][i]);
                visit[g[n][i]]=true;
            }
        }
    }
}
int main(){
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> g(M+1);
    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(g,V);
    fill_n(visit,1001,false);
    cout << endl;
    bfs(g,V);
    
    //    for(int i=1;i<=N;i++){
    //        cout << i << " : ";
    //        for(int j=0;j<g[i].size();j++){
    //            cout << g[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    
    return 0;
}
