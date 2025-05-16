#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int l,r;
    int data;
    node* left, *right;
    node(int a, int b) : l(a), r(b), data(0), left(nullptr), right(nullptr) {};
    node(int a, int b, int c) : l(a), r(b), data(c), left(nullptr), right(nullptr) {};
};

node* construct(int arr[], int s, int e){
    if(e<s) return NULL;
    node* curr = new node(s,e);
    if(s==e){
        curr->data=arr[s];
        return curr;
    }
    curr->left = construct(arr,s,(s+e)/2);
    curr->right = construct(arr,(s+e)/2 +1, e);
    curr->data = curr->left->data+curr->right->data;
    return curr;
}

void print(node* c){
    if(c==nullptr) return;
    cout<<c->l<<" "<<c->data<<" "<<c->r<<endl;
    print(c->left);
    print(c->right);
}

void update(node* c, int p, int d, int arr[]){
    int l=c->l, r=c->r;
    if(p<=r && p>=l){
        c->data+=d-arr[p];
        if(l!=r){
            update(c->left,p,d,arr);
            update(c->right,p,d,arr);
        }else{
            arr[p]=d;
        }
    }
    return;
}

int retrieve(node* c, int s, int e){
    if(c==nullptr) return 0;
    if((s<c->l && e<c->l)||(s>c->r && e>c->r)) return 0;
    if(s<=c->l && e>=c->r){
        return c->data;
    }
    return retrieve(c->left,s,e) + retrieve(c->right,s,e);
}

int main()
{
    int n=8;
    int arr[n] = {3,8,7,6,-2,-8,4,9};
    node* root = construct(arr, 0, n-1);
    // print(root);
    cout<<retrieve(root, 0 , 3)<<endl;
    cout<<retrieve(root, 2 , 5)<<endl;
    update(root,3,14,arr);
    cout<<retrieve(root, 0 , 3)<<endl;
    cout<<retrieve(root, 2 , 5)<<endl;
    update(root,3,6,arr);
    cout<<retrieve(root, 0 , 3)<<endl;
    cout<<retrieve(root, 2 , 5)<<endl;
    return 0;
}