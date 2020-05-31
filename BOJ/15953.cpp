/*
    https://www.acmicpc.net/problem/15953
*/
#include <iostream>
using namespace std;
int F2017(int n){
    int ans = 0;
    if(n!=0 && n<22){
        if (n == 1) ans = 5000000;
		else if (n == 2 || n == 3) ans = 3000000;
		else if (n > 3 && n < 7) ans = 2000000;
		else if (n > 6 && n < 11) ans = 500000;
		else if (n > 10 && n < 16) ans = 300000;
		else ans = 100000;
    }
    return ans;
}
int F2018(int n){
    int ans = 0;
    if(n!=0 && n<32){
        if (n == 1) ans = 5120000;
		else if (n == 2 || n == 3) ans = 2560000;
		else if (n > 3 && n < 8) ans = 1280000;
		else if (n > 7 && n < 16) ans = 640000;
		else ans = 320000;
    }
    return ans;
}
int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << F2017(a) + F2018(b) << "\n";
    }
    return 0;
}