#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> TopView(node* root){
    if(!root) return  {};
    node* t = NULL;
    queue<pair<node* , int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        t = q.front().first;
        int d = q.front().second;
        q.pop();
        if(mp.find(d)==mp.end()) mp[d]=t->data;
        if(t->left) q.push({t->left,d-1});
        if(t->right) q.push({t->right,d+1});
    }
    vector<int>a;
    for(auto i:mp){
        a.push_back(i.second);
    }
    return a;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> result = TopView(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}