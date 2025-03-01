#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> TopView(Node* root){
    if(!root) return  {};
    Node* t = NULL;
    queue<pair<Node* , int>> q;
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
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = TopView(root);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}