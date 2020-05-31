/*
    BOJ 1717.cpp
    집합의 표현 - Disjoint Set(Union Find)
    https://www.acmicpc.net/problem/1717
*/
#include <iostream>
using namespace std;
int Find(int* parent, int x){
    if(x == parent[x]){
        return x;
    } else {
        int y = Find(parent, parent[x]);
        parent[x] = y;
        return y;
    }
}
void Union(int* parent, int a, int b){
    int x = Find(parent, a);
    int y = Find(parent, b);
    parent[y] = x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cmd, a, b;
    cin >> n >> m;
    int parent[n+1];
    // 각각 다른 집합으로 초기화
    for(int i=0;i<=n;i++)
        parent[i] = i;
    
    while(m--){
        cin >> cmd >> a >> b;
        if(cmd==0){ // union
            Union(parent, a, b);
        } else { // find
            int x = Find(parent, a);
            int y = Find(parent, b);
            x==y ? cout << "YES\n" : cout << "NO\n";
        }
    }
    return 0;
}