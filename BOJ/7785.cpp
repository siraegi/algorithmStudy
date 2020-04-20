/*
    BOJ 7785.cpp
    회사에 있는 사람
    https://www.acmicpc.net/problem/7785
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    set<string> cur;
    string name;
    string status;
    for(int i=0;i<n;i++){
        cin >> name >> status;
        if(status=="enter"){
            cur.insert(name);
        } else{
            cur.erase(name);
        }
    }
    for(auto iter = cur.rbegin(); iter != cur.rend(); iter++){
        cout << *iter << "\n";
    }
    return 0;
}