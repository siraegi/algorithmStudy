/*
    11403. 경로 찾기
    플로이드 와샬 알고리즘(그래프의 모든 정점 탐색 시 유용)
*/
#include <iostream>
#include <chrono>
using namespace std;using namespace chrono;
int g[101][101];
int n;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> g[i][j];
    }
    // 정점 k를 지나며 i에서 j로 가는 경로가 있는지 탐색해서 i-j로 직접 가지 않더라도 k를 거쳐갈 수 있는 방법이 있다면 경로가 있다고 판단
    //chrono::system_clock::time_point I_start = chrono::system_clock::now();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][k] && g[k][j]){
                    g[i][j]=1;
                }
            }
        }
    }
    //chrono::system_clock::time_point I_end = chrono::system_clock::now();
    //chrono::nanoseconds I_time = I_end - I_start;
	//	cout << I_time.count()<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}