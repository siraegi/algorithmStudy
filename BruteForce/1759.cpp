/*
    BOJ 1759.cpp
    암호 만들기 - Brute Force Algorithm(recursion)
    https://www.acmicpc.net/problem/1759
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(string& pw){
    int vowel = 0;//모음
    int consonant = 0;//자음
    for(char x : pw){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            vowel++;
        } else {
            consonant++;
        }
    }
    return vowel>=1 && consonant>=2;
}
void solve(int n, vector<char>& alpha, int index, string pw){
    if(pw.length()==n){
        if(check(pw)){
            cout << pw << "\n";
        }
        return ;
    }
    if(index >= alpha.size()) return;
    solve(n, alpha, index+1, pw+alpha[index]);
    solve(n, alpha, index+1, pw);
}
int main(){
    int L, C;
    cin >> L >> C;
    vector<char> alpha(C);
    for(int i=0;i<C;i++)
        cin >> alpha[i];

    sort(alpha.begin(), alpha.end());
    solve(L, alpha, 0, "");
    return 0;
}