/*
    BOJ 3780.cpp
    네트워크 연결 - Disjoint Set(Union Find)
    https://www.acmicpc.net/problem/3780
*/
#include <iostream>
#include <math.h>
using namespace std;
int parent[20001];
int dist[20001];
int Find(int x){
    if(x == parent[x])
        return x;
    else {
        int y = Find(parent[x]);
        dist[x] += dist[parent[x]];
        return parent[x] = y;
    }
}
void Union(int x, int y){
    parent[x] = y;
    dist[x] = abs(x-y)%1000;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1;i<=N;i++){
            parent[i] = i;
            dist[i] = 0;
        }        
        char cmd;
        int i,j;
        while(true){
            cin >> cmd;
            if(cmd=='O') break;
            switch(cmd){
            case 'E':
                cin >> i;
                Find(i);
                cout << dist[i] << "\n";
                break;
            case 'I':
                cin >> i >> j;
                Union(i, j);
                break;
            }
        }
    }
    return 0;
}