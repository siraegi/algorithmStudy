/*
    BOJ 3665.cpp
    최종 순위 - Topological Sort
    https://www.acmicpc.net/problem/3665
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
bool g[501][501];
int ind[501];
queue<int> q;
int ranking[501];
int order[501];
vector<int> ans;
void clear(std::queue<int> &q){
   std::queue<int> empty;
   std::swap( q, empty );
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        memset(ind, 0, sizeof(ind));
        memset(g, false, sizeof(g));
        memset(ranking, 0, sizeof(ranking));
        memset(order, 0, sizeof(order));
        clear(q);
        ans.clear();
        int N, M;
        cin >> N;
        int r;
        for(int i=1;i<=N;i++){
            cin >> r;
            order[i] = r;
            ranking[r] = i;
        }

        for(int i=1;i<=N;i++){
            for(int j=i+1;j<=N;j++){
                g[order[i]][order[j]] = true;
                ind[order[j]]++;
            }
        }
        cin >> M;
        int x, y;
        for(int i=0;i<M;i++){
            cin >> x >> y;
            if(ranking[x] < ranking[y]){
                g[y][x] = true;
                g[x][y] = false;
                ind[x]++;
                ind[y]--;
            }
            else {
                g[x][y] = true;
                g[y][x] = false;
                ind[y]++;
                ind[x]--;
            }
        }

        // for(int i=1;i<=N;i++){
        //     for(int j=1;j<=N;j++){
        //         cout << g[i][j] << " ";
        //     }
        //     cout << " : "<<ind[i]<<endl;
        // }

        for(int i=1;i<=N;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        bool lotsOfCase = false;

        while (!q.empty()){
            if (q.size() > 1) {
                lotsOfCase = true;
                break;
            }
            int now = q.front();
            ans.push_back(now);
            q.pop();
            for (int i = 1; i <= N; i++){
                if(g[now][i]){
                    ind[i]--;
                    if(ind[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        if(lotsOfCase){
            cout << "?";
        }
        else if(ans.size() == N){
            for(int i=0;i<N;i++){
                cout << ans[i]<<" ";
            }
        }
        else{
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
    
    return 0;
}