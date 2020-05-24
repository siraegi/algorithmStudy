/*
    BOJ 9095.cpp
    1,2,3 더하기 - Brute Force Algorithm(recursion), DP
    https://www.acmicpc.net/problem/9095
*/
#include <iostream>
using namespace std;
int solve(int num, int sum){
    if(num==sum) return 1;
    if(num<sum) return 0;
    int now=0;
    for(int i=1;i<=3;i++){
        now += solve(num, sum+i);
    }
    return now;
}
int main(){
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        cout << solve(n, 0)<<"\n";
    }
    return 0;
}