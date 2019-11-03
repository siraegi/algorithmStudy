#include <iostream>
#include <algorithm>
using namespace std;
bool visit[26][26]; // 방문 여부 지도
int arr[26][26]; // 지도
int num[350]; // 단지 개수
int cnt=0;
int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y){
    visit[x][y] = true;
    num[cnt]++;
    for(int i=0;i<4;i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>-1 && X<n && Y>-1 && Y<n){
            if(!visit[X][Y] && arr[X][Y]) dfs(X,Y);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%1d", &arr[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j] && arr[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    sort(num, num+cnt);
    for(int i=0;i<cnt;i++)
        cout << num[i] << endl;

    return 0;
}