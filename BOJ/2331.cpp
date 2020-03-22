#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int p;
int visit[300000];
void dfs(int n){
    visit[n]++;
    // 3번째로 그 수를 방문해야 완전히 반복수열이 전부 다 반복된것으로 인식됨. 
    // ex) [1 2 3]이 반복된다고 하면
    // 4 1 2 3 1 2 3 1 => 세번째로 등장한 1이 반복수열이 완전히 반복된 것을 알려줌. 반복수열은 visit을 2로 만들어둬야 visit == 1 검사할 때 안걸림
    if(visit[n]>2)
        return;
    int sum = 0;
    while(n){
        sum += (floor)(pow((n%10),p));
        n/=10;
    };
    dfs(sum);
}
int main(){
    int a;
    cin >> a >> p;
    dfs(a);
    int cnt=0;
    for(int i=0;i<300000;i++){
        if(visit[i] == 1){
            cnt++;
        }
    }
    cout << cnt <<endl;
    return 0;
}