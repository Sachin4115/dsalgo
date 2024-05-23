#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    vector<node*> children;

    node(int val){
        data=val;
        children={};
    }

};

bool search(node* root, int key){
    if(root->data==key){
        return true;
    }
    for(node* itr:root->children){
        if(search(itr,key))
            return true;
    }
    return false;
}

vector<int> nodeToRootPath(node* root,int key){
    if(root->data==key){
        vector<int> ans;
        ans.push_back(key);
        return ans;
    }
    for(node* itr:root->children){
        vector<int> pathTillChild = nodeToRootPath(itr,key);
        if(pathTillChild.size()>0){
            pathTillChild.push_back(root->data);
            return pathTillChild;
        }
    }
    return {};
}

int lowestCommonAncestors(node* root,int k1,int k2){
    vector<int> v1 = nodeToRootPath(root,k1);
    vector<int> v2 = nodeToRootPath(root,k2);

    int i=1;
    while(i<=v1.size() && i<=v2.size()){
        if(v1[v1.size()-i]==v2[v2.size()-i]){
            i++;
        }else{
            break;
        }
    }
    return v1[v1.size()-i+1];
}

int distanceBetweenNodes(node* root,int k1,int k2){
    vector<int> v1 = nodeToRootPath(root,k1);
    vector<int> v2 = nodeToRootPath(root,k2);

    int i=1;
    while(i<=v1.size() && i<=v2.size()){
        if(v1[v1.size()-i]==v2[v2.size()-i]){
            i++;
        }else{
            break;
        }
    }
    i=i-1;
    int ans=v1.size()-i+v2.size()-i;
    return ans;

}

int main()
{

    // Code for creating a generic tree
    vector<int> input = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

    stack<node*> st;
    node* root = NULL;
    for(int i=0;i<input.size();i++){
        if(input[i]==-1)
            st.pop();
        else {
            node *t = new node(input[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }

    // cout<<search(root,10)<<endl;
    // cout<<search(root,100)<<endl;
    // cout<<search(root,110)<<endl;
    // cout<<search(root,1000)<<endl;

    // vector <int> v = nodeToRootPath(root,30);
    // for(int i:v){
    //     cout<<i<<" ";
    // }

    // cout<<lowestCommonAncestors(root,110,90);

    // cout<<distanceBetweenNodes(root,110,70);

    return 0;
}