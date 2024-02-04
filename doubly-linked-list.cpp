#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* prev;
        node* next;

    node(int val)
    {
       data=val;
       prev=NULL;
       next=NULL;
    }


};
//insert at the head
void insertAthead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }

    head=n;
}
//insert node at the tail
void insertAttail(node* &head,int val)
{
    
    if(head==NULL)
    {
        insertAthead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
//print
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
int main()
{
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);
    display(head);
    return 0;
}