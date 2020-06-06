/*
    BOJ 1735.cpp
    분수 합 - Euclidean's Algorithm
    https://www.acmicpc.net/problem/1735
*/
#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(b>0){
        int c = a;
        a = b;
        b = c%b;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    int A1, B1, A2, B2;
    cin >> A1 >> B1 >> A2 >> B2;
    int B3 = B1*B2;
    int A3 = A1*B2 + A2*B1;
    int GCD = gcd(A3, B3);
    cout << A3/GCD << " " << B3/GCD;
    return 0;
}