#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
int arr[2001];
int dp[2001][2001];
int isPalindrome(int l, int r){
    if(l>=r) return 1;
    int& result = dp[l][r];
    if(result != -1) return result;
    if(arr[l]!=arr[r]) return 0;
    result = isPalindrome(l+1,r-1); 
    return result;
}
int main(){
    cin.tie(NULL);
    ios_base :: sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int question, l, r;
    cin >> question;
    for(int i=0;i<question;i++){
        cin >> l >> r;
        if(isPalindrome(l-1,r-1)) cout << 1 <<"\n";
        else cout << 0 <<"\n";
    }
    return 0;
}