/*
    BOJ 2606.cpp
    바이러스 - Disjoint Set(Union Find)
    https://www.acmicpc.net/problem/2606
*/
#include <iostream>
using namespace std;
int parent[101];
int Find(int x){
    if(x == parent[x])
        return x;
    else 
        return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    int a = Find(x);
    int b = Find(y);
    parent[b] = a;
}
int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        parent[i] = i;

    while(m--){
        cin >> a >> b;
        Union(a, b);
    }
    int one = Find(1);
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(Find(i) == one)
            cnt++;
    }
    cout << cnt;
    return 0;
}