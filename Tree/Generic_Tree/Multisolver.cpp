#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int s;
int Min;
int Max;
int h;
struct node{
    int data;
    vector<node*> children;

    node(int val){
        data=val;
        children={};
    }
};

node* createTree(vector<int> input){
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
    return root;
}


void multisolver(node* root,int d){

    s+=1;
    Min=min(Min,root->data);
    Max=max(Max,root->data);
    h=max(h,d);

    for(node* itr:root->children){
        multisolver(itr,d+1);
    }
}

node* pre;
node* suc;
int state;
// predecessor and successor
void preAndSuc(node* root,int d){
    if(state==0){
        if(root->data==d)
            state++;
        else
            pre=root;
    }
    else if(state==1){
        suc=root;
        state++;
    }
    for(node* itr:root->children){
        preAndSuc(itr,d);
    }
}

int floorData;
int ceilData;
void ceilDataAndfloorData(node* root, int d){
    if(root->data<d)
        floorData = max(floorData,root->data);
    else if(root->data>d)
        ceilData = min(ceilData,root->data);

    for(node* itr:root->children){
        ceilDataAndfloorData(itr,d);
    }
}

int kLargestElement(node* root, int k){
    floorData=INT_MIN;
    int t=INT_MAX;
    for(int i=0;i<k;i++){
        ceilDataAndfloorData(root,t);
        t=floorData;
        floorData=INT_MIN;
    }
    return t;
}

int subSum;
int maxSumSubTree (node* root){
    int totalSum=0;
    for(node* itr:root->children){
        int s=maxSumSubTree(itr);
        totalSum+=s;
    }
    totalSum+=root->data;
    if(subSum<totalSum)
        subSum=totalSum;
    return totalSum;
}
int main()
{

    // Code for creating a generic tree
    vector<int> input = {10,20,-50,-1,-60,-1,-1,30,-70,-1,80,-110,-1,120,-1,-1,90,-1,-1,40,-100,-1,-1,-1};
    node* root = createTree(input);

    // s=0;
    // Min=INT_MAX;
    // Max=INT_MIN;
    // h=0;

    // multisolver(root,0);

    // cout<<s<<endl;
    // cout<<Min<<endl;
    // cout<<Max<<endl;
    // cout<<h<<endl;

    // pre=NULL;
    // suc=NULL;
    // state=0;

    // preAndSuc(root,110);

    // if(pre)
    //     cout<<"p: "<<pre->data<<endl;
    // if(suc)
    //     cout<<"s: "<<suc->data<<endl;

    // floorData=INT_MIN;
    // ceilData=INT_MAX;

    // ceilDataAndfloorData(root,65);

    // cout<<"ceilData: "<<ceilData<<endl;
    // cout<<"floorData: "<<floorData<<endl;

    // cout<<kLargestElement(root,3)<<endl;

    subSum=INT_MIN;
    maxSumSubTree(root);
    cout<<subSum<<endl;

    return 0;
}