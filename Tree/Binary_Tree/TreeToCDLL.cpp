#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* construct(vector <int> &arr){
    stack<pair<node* , int>>st;
    node* root = new node(arr[0]);
    pair <node* , int> p = {root,1};
    st.push(p);
    int i=1;
    while(!st.empty()){
        if(st.top().second==1){
            st.top().second++;
            if(arr[i]==-1){
                i++;
                continue;
            }else{
                node* newnode = new node(arr[i]);
                st.top().first->left=newnode;
                st.push({newnode,1});
                i++;
            }
        }
        else if(st.top().second==2){
            st.top().second++;
            if(arr[i]==-1){
                i++;
                continue;
            }else{
                node* newnode = new node(arr[i]);
                st.top().first->right=newnode;
                st.push({newnode,1});
                i++;
            }
        }
        else{
            st.pop();
        }
    }
    return root;
}

void displayCList(node *head)
{
    node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    head = itr;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<endl;
}

node *bTreeToCList(node *root)
    {
        if(!root->left && !root->right){
            root->left=root;root->right=root;
        }else if(!root->left){
            node* r = bTreeToCList(root->right);
            root->right=r;
            r->left=root;
            node* k = r;
            while(r->right!=k) r=r->right;
            r->right=root;
            root->left=r;
        }else if(!root->right){
            node* l = bTreeToCList(root->left);
            node* t=l;
            root->right=l;
            l->left=root;
            node* k =l;
            while(l->right!=k) l=l->right;
            root->left=l;
            l->right=root;
            root=t;
        }else{
            node* l = bTreeToCList(root->left);
            node* r = bTreeToCList(root->right);
            node* t=l;
            while(l->right!=t) l=l->right;
            root->right=r;
            root->left=l;
            r->left=root;
            l->right=root;
            node* k=r;
            while(r->right!=k) r=r->right;
            r->right=t;
            t->left=r;
            root=t;
        }
        return root;
    }


int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    node* ans = bTreeToCList(root);
    displayCList(ans);
    return 0;
}