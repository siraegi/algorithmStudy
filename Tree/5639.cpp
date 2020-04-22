/*
    BOJ 5639.cpp
    이진 검색 트리 - Binary Search Tree
    https://www.acmicpc.net/problem/5639
*/
#include <iostream>
using namespace std;
struct node {
    node* left;
    int val;
    node* right;
    node(){
        left = NULL;
        val = 0;
        right = NULL;
    }
};

node* tree;

void build_BST(int data){
    node* now = new node();
    now->val = data;
    if(tree == NULL){
        tree = now;
        return;
    }
    node* cur = tree;
    while(true){
        if(data < cur->val){
            if(cur->left == NULL){
                cur->left = now;
                break;
            } else {
                cur = cur->left;
            }
        } else {
            if(cur->right == NULL){
                cur->right = now;
                break;
            } else {
                cur = cur->right;
            }
        }
    }
}
void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "\n";
}
int main(){
    int data;
    while(cin >> data){
        build_BST(data);
    }
    postorder(tree);
    return 0;
}