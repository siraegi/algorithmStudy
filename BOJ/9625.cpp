/*
    https://www.acmicpc.net/problem/9625
*/
#include <iostream>
using namespace std;
int main(){
    int A = 1;
    int B = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a = A;
        int b = B;
        B += a;
        A += b;
        A += a*(-1);
    }
    cout << A <<" "<<B;
    return 0;
}