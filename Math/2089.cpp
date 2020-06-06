/*
    BOJ 2089.cpp
    -2진수 - 진법 변환 응용
    https://www.acmicpc.net/problem/2089
*/
#include <iostream>
using namespace std;
void solve(long long n){
    if(n==0) return;
    if(n%(-2) == 0){
        cout << "*"<< n/(-2) << "\n";
        solve(n/(-2));
        cout << "0";
    } else{
        cout << (n-1)/(-2)<<"\n";
        solve((n-1)/(-2));
        cout << "1";
    }
    return;
}
int main(){
    long long n;
    cin >> n;
    
    if(n==0){
        cout << "0";
        return 0;
    }
    solve(n);
    return 0;
}