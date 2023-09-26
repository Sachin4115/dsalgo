// Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the
// nodes in the list so that the new formed list is: L0 -> Ln -> L1 ->
// Ln-1 -> L2 -> Ln-2.

#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


Node *inPlace(Node *root);

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *res = inPlace(head);
		print(res);
		cout<<endl;
	}
	return 0;
}
Node *inPlace(Node *root)
{
    Node*slow=root;
    Node*fast=root;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*h1=root;
    Node*h2=slow->next;
    slow->next=NULL;
    Node*temp=h2;
    Node*prev=NULL;
    while(temp){
        Node*t2=temp->next;
        temp->next=prev;
        prev=temp;
        temp=t2;
    }
    h2=prev;
    while(h2){
        Node*t2=h2->next;
        Node*t3=h1->next;
        h1->next=h2;
        h2->next=t3;
        h1=t3;
        h2=t2;
    }
    return root;
}
