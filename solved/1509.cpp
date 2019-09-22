#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 2500
using namespace std;
char str[MAX];
int dp[MAX][MAX];
int cnt[MAX];
int isPalindrome(int l, int r){
    if(l>=r) return 1;
    int& result = dp[l][r];
    if(result != -1) return result;
    if(str[l]!=str[r]) return 0;
    result = isPalindrome(l+1,r-1); 
    return result;
}
int main(){
    cin.tie(NULL);
    ios_base :: sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    memset(cnt, 9999999, sizeof(cnt));
    cin >> str;
    int n=strlen(str);
    
    //cnt[i]는 0~i 문자열에서 팰린드롬의 최소 분할 개수
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(isPalindrome(j,i)){
                if(j==0) 
                    cnt[i]=min(cnt[i],1);
                else 
                    cnt[i]=min(cnt[i],cnt[j-1]+1);
            }
        }
    }
    cout << cnt[n-1];
    return 0;
}