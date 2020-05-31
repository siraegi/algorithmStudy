/*
    BOJ 4195.cpp
    친구 네트워크 - Disjoint set(Union Find)
    https://www.acmicpc.net/problem/4195
*/
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
int parent[200001];
int network[200001]; // 루트 인덱스에 네트워크에 있는 사람 수 저장
int Find(int x){
    if(parent[x]==0){
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}
void Union(int a, int b){
    parent[b] = a;
    network[a] += network[b];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        map<string, int> friendsID;
        string a,b;
        memset(network, 0, sizeof(network));
        memset(parent, 0, sizeof(parent));
        cin >> n;
        int id = 1;
        while(n--){
            cin >> a >> b;
            if(friendsID.count(a)==0){
                friendsID[a] = id;
                network[id++] = 1;
            }
            if(friendsID.count(b)==0){
                friendsID[b] = id;
                network[id++] = 1;
            }
            int x = Find(friendsID[a]);
            int y = Find(friendsID[b]);
            //cout << x <<" "<<y<<"\n";
            if(x!=y)
                Union(x, y); // x에 y 합치기
            //cout << Find(friendsID[a]) <<" "<<Find(friendsID[b])<<"\n";
            cout << network[x]<<"\n";
        }
    }
    return 0;
}