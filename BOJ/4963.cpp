#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool visit[51][51]; // 방문 여부 지도
int arr[51][51]; // 지도
int dx[8]={ 0,1,1,1,0,-1,-1,-1};
int dy[8]={ -1,-1,0,1,1,1,0,-1};
int w, h;
void dfs(int y, int x){
    if(!arr[y][x] || visit[y][x]) return;
    visit[y][x] = true;
    for(int i=0;i<8;i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>-1 && X<w && Y>-1 && Y<h){
            dfs(Y,X);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base :: sync_with_stdio(false);
    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;
        memset(visit, false, sizeof(visit));
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++)
                cin >> arr[i][j];
        }
        int cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visit[i][j] && arr[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}