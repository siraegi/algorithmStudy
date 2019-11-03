//
//  1260.cpp
//  Algorithm
//
//  Created by ShiHaYeon on 02/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int>& g, int n){
    
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
    dfs(g,N);
    
//    for(int i=1;i<=N;i++){
//        cout << i << " : ";
//        for(int j=0;j<g[i].size();j++){
//            cout << g[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    return 0;
}
