#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[201][201];
vector<int> ans;
int A,B,C;
struct Water{
    int a,b,c;
};
void bfs(){
    queue <Water> q;
    q.push({0,0,C});
    while(!q.empty()){
        Water w = q.front();
        q.pop();
        if(!visit[w.a][w.b]){
            visit[w.a][w.b]=true;
            if(w.a==0)
                ans.push_back(w.c);
            // A->B
            if(w.a+w.b>B)
                q.push({w.a+w.b-B,B,w.c});
            else
                q.push({0,w.a+w.b,w.c});

            // A->C
            if(w.a+w.c>C)
                q.push({w.a+w.c-C,w.b,C});
            else
                q.push({0,w.b,w.a+w.c});

            // B->A
            if(w.a+w.b>A)
                q.push({A,w.a+w.b-A,w.c});
            else
                q.push({w.a+w.b,0,w.c});
            
            // B->C
            if(w.b+w.c>C)
                q.push({w.a,w.b+w.c-B,C});
            else
                q.push({w.a,0,w.b+w.c});

            // C->A
            if(w.a+w.c>A)
                q.push({A,w.b,w.a+w.c-A});
            else
                q.push({w.a+w.c,w.b,0});
            
            // C->B
            if(w.b+w.c>B)
                q.push({w.a,B,w.b+w.c-B});
            else
                q.push({w.a,w.b+w.c,0});
            
        }
    }
}
int main(){
    cin >> A >> B >> C;
    bfs();

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";

    return 0;
}