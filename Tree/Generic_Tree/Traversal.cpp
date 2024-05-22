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

void traversal(node* root){
    cout<<"Node pre "<<root->data<<endl;
    for(node* itr:root->children){
        cout<<"Edge Pre "<<root->data<<"--"<<itr->data<<endl;
        traversal(itr);
        cout<<"Edge Post "<<root->data<<"--"<<itr->data<<endl;
    }
    cout<<"Node Post "<<root->data<<endl;

}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(q.size()>0){
        cout<<q.front()->data<<" ";
        for(node* itr:q.front()->children){
            q.push(itr);
        }
        q.pop();
    }
}

void traversalWithLevel(node* root){
    queue<node*> mainQ;
    queue<node*> childQ;

    mainQ.push(root);

    while(!mainQ.empty()){
        cout<<mainQ.front()->data<<" ";
        for(node* itr:mainQ.front()->children){
            childQ.push(itr);
        }
        mainQ.pop();
        if(mainQ.empty()){
            cout<<endl;
            mainQ=childQ;
            childQ={};
        }
    }
}

void traversalWithLevelZigZag(node* root){
    stack<node*> ms;
    stack<node*> cs;
    int level=1;

    ms.push(root);

    while(!ms.empty()){
        cout<<ms.top()->data<<" ";
        if(level%2){
            for(node* itr:ms.top()->children){
                cs.push(itr);
            }
        }else{
            for(int i=ms.top()->children.size()-1;i>=0;i--){
                cs.push(ms.top()->children[i]);
            }
        }
        ms.pop();
        if(ms.empty()){
            cout<<endl;
            level++;
            // while(!cs.empty()){
            //     ms.push(cs.top());
            //     cs.pop();
            // }
            ms=cs;
            cs={};
        }
    }
}

int main()
{

    // Code for creating a generic tree
    vector<int> input = {10,20,-1,30,50,-1,60,-1,-1,40,-1};

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

    // traversal(root);
    // cout<<endl;
    // levelOrderTraversal(root);
    // cout<<endl;
    // traversalWithLevel(root);
    // cout<<endl;
    traversalWithLevelZigZag(root);
    cout<<endl;

    return 0;
}