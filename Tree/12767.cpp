/*
    BOJ 12767.cpp
    Ceiling Function - Binary Search Tree
    https://www.acmicpc.net/problem/12767
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
struct node{
    node* left;
    int data;
    node* right;
    node(){
        left = NULL;
        data = 0;
        right = NULL;
    }
};
string preorder(node* root){
    string ret = "";
    ret += "V";
    if(root->left){
        ret += "L";
        ret += preorder(root->left);
        ret += "l";
    }
    if(root->right){
        ret += "R";
        ret += preorder(root->right);
        ret += "r";
    }
    ret += "v";
    return ret;
}
int main(){
    int n, k;
    cin >> n >> k;
    set<string> s;
    for(int i=0;i<n;i++){
        node* root = new node();
        int x;
        cin >> x;
        root->data = x;
        for(int j=1;j<k;j++){
            cin >> x;
            node* cur = root;
            while(true){
                if(x<cur->data){
                    if(cur->left == NULL){
                        cur->left = new node();
                        cur->left->data = x;
                        break;
                    } else {
                        cur = cur->left;
                    }
                } else {
                    if(cur->right == NULL){
                        cur->right = new node();
                        cur->right->data = x;
                        break;
                    } else {
                        cur = cur->right;
                    }
                }
            }
        }
        s.insert(preorder(root));
    }
    cout << s.size();
    return 0;
}