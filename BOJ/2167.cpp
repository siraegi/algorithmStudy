#include <iostream>
using namespace std;
int arr[304][304];
int dp[304][304];
int n,m;
int main(){
    cin.tie(NULL);
    ios_base :: sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i][j-1] + arr[i][j];
        }
    }
    int testcase;
    cin >> testcase;
    int x1,y1,x2,y2;
    int ret;
    for(int t=0;t<testcase;t++){
        cin >> x1 >> y1 >> x2 >> y2;
        ret = 0;
        for(;x1<=x2;x1++){
            ret += dp[x1][y2] - dp[x1][y1-1];
        }
        cout << ret << "\n";
    }
    return 0;
}