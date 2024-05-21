#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct node{
    int data;
    vector<node*>children;

    node(int val){
        data=val;
        children={};
    }
};

void display(node* root){
    string str = to_string(root->data) + "->";
    for(node* child: root->children){
        str+=to_string(child->data)+", ";
    }
    str+=".";
    cout<<str<<endl;
    for(node* child: root->children){
        display(child);
    }
}

int size(node* root){
    int s=0;
    for(node* itr:root->children){
        int cs=size(itr);
        s+=cs;
    }
    s+=1;
    return s;
}

int max(node* root){
    int m1=root->data;
    for(node* itr:root->children){
        int m = max(itr);
        m1=m1>m?m1:m;
    }
    return m1;
}

int height(node* root){
    int h=-1;
    for(node* itr:root->children){
        int ch = height(itr);
        h=ch>h?ch:h;
    }
    return h+1;
}

int main()
{
    vector<int> input = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,150,-1};

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

    display(root);
    cout<<size(root)<<endl;
    cout<<max(root)<<endl;
    cout<<height(root)<<endl;

    return 0;
}