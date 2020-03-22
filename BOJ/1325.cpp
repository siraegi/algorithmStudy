//
//  1325.cpp
//  DFS
//
//  Created by ShiHaYeon on 15/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
bool visit[10001];
vector<int> g[10001];
int N, M;
int DFS(int cnt, int start){ // cnt: s와 연결된 컴퓨터의 개수, s: start root node
    if(cnt==N) return cnt;
    visit[start] = true;
    for(int i=0;i<g[start].size();i++){
        int next = g[start][i];
        if(!visit[next]){
            //cout << next<<" ";
            //visit[next] = true;
            cnt=cnt+1;
            cnt = DFS(cnt, next);
        }
    }
    return cnt;
}
int main(){
    
    cin >> N >> M;

    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        g[y].push_back(x);
    }

    vector<pair<int,int>> computers(N+1);
    for(int i=1;i<=N;i++){
        memset(visit, false, sizeof(visit));
        int value = DFS(0,i);
        computers[i]=make_pair(value,i);
        //cout << computers[i].first<<endl;
    }
    sort(computers.begin(), computers.end());
    int max = computers[N].first;
    vector<int> ans;
    for(int i=N;i>0;i--){
        //cout << computers[i].first<<" ";
        if(computers[i].first<max)
            break;
        ans.push_back(computers[i].second);
    }
    sort(ans.begin(),ans.end());
    cout << ans[0];
    for(int i=1;i<ans.size();i++){
        cout << " "<< ans[i];
    }
    return 0;
}
