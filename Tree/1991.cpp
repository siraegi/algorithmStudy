/*
    BOJ 1991.cpp
    트리 순회
    https://www.acmicpc.net/problem/1991
    A = 0, B = 1, C = 2...
*/
#include <iostream>
using namespace std;
struct node {
    int left = -1;
    int right = -1;
};
node tree[26];
void preOrder(int node){
    cout << (char)(node + 'A');
    if(tree[node].left != -1)
        preOrder(tree[node].left);
    if(tree[node].right != -1)
        preOrder(tree[node].right);
}
void inOrder(int node){
    if(tree[node].left != -1)
        inOrder(tree[node].left);
    cout << (char)(node + 'A');
    if(tree[node].right != -1)
        inOrder(tree[node].right);
}
void postOrder(int node){
    if(tree[node].left != -1)
        postOrder(tree[node].left);
    if(tree[node].right != -1)
        postOrder(tree[node].right);
    cout << (char)(node + 'A');
}
int main(){
    int n;
    char data, lnode, rnode;
    cin >> n;
    for(int i=0;i<n;i++){
        node tmp;
        cin >> data >> lnode >> rnode;
        if(lnode != '.')
            tmp.left = lnode - 'A';
        if(rnode != '.')
            tmp.right = rnode - 'A';
        tree[data-'A'] = tmp;
    }
    // for(int i=0;i<n;i++){
    //     cout << char(i+'A') << " "<<(char)(tree[i].left+'A')<<" "<<(char)(tree[i].right+'A')<<"\n";
    // }    
    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";
    return 0;
}
