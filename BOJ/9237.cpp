/*
    BOJ 9237.cpp
    이장님 초대
    https://www.acmicpc.net/problem/9237
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool desc(int a, int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    int tree[n+1];
    for(int i=0;i<n;i++){
        cin >> tree[i];
    }
    sort(tree, tree+n, desc);
    int day = 0;
    int cur = 0;
    for(int i=0;i<n;i++){
        cur++;
        int tmp = tree[i] + 1;
        if(cur+tmp>day) {
            day = cur + tmp;
        }
    }
    cout << day;
    return 0;
}