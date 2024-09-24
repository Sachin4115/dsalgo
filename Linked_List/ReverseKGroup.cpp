#include <iostream>
using namespace std;

class ListNode{

    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=NULL;
    }
};

ListNode* reverseKGroup(ListNode* h, int k) {
    if(!h || !h->next)
        return h;
    ListNode* t = h;
    for(int i=0;i<k;i++){
        if(!t) return h;
        t=t->next;
    }

    ListNode *p=NULL,*n=NULL;
    t=h;
    int  i=0;

    while(i<k){
        n=t->next;
        t->next=p;
        p=t;
        t=n;
        i++;
    }

    h->next=reverseKGroup(n,k);
    return p;

}

void printLL(ListNode* h){
    ListNode* t = h;
    while(t){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    ListNode* h = new ListNode(arr[0]);
    ListNode* p = h;
    for(int i=1;i<5;i++){
        p->next = new ListNode(arr[i]);
        p=p->next;
    }
    printLL(h);
    h=reverseKGroup(h,2);
    printLL(h);
    return 0;
}