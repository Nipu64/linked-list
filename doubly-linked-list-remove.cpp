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
//delete node at the head
void deleteAthead(node* &head)
{
    node* todelete=head;
    head=head->next;

    head->prev=NULL;
     delete todelete;
}
//remove a node
void removeNode(node* &head,int pos)
{
    if(pos==1)
    {
        deleteAthead(head);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(temp!=NULL && cnt!=pos)
    {
        temp=temp->next;
        cnt++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    { 
        temp->next->prev=temp->prev;
    }
    delete temp;
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
    removeNode(head,3);
    display(head);
    return 0;
}