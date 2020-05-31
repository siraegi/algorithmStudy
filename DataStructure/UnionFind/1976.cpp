/*
    BOJ 1976.cpp
    여행가자 - Disjoint Set(Union Find)
    https://www.acmicpc.net/problem/1976
    왜 마을 인덱스가 1부터라는 것을 말해주지 않는 것이야
*/
#include <iostream>
using namespace std;
int parent[201];
int Find(int x){
    if(x == parent[x])
        return x;
    else {
        return parent[x] = Find(parent[x]);
    }
}
void Union(int x, int y){
    int a = Find(x);
    int b = Find(y);
    parent[b] = a;
}
int main(){
    int N, M, x;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
        parent[i] = i;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> x;
            if(x==1){
                Union(i,j);
            }
        }
    }
    
    cin >> x;
    int start = Find(x);
    string ans = "YES";
    for(int i=1;i<M;i++){
        cin >> x;
        if(Find(x)!=start){
            ans = "NO";
            break;
        }
    }
    cout << ans;
    return 0;
}