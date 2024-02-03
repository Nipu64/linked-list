#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss "\n"
using namespace std;
class node{
      public:
      int data;
      node* next;
      
      //constructor
      node(int val)
      {
        data=val;
        next=NULL;
      }
};
//insert node at the tail
void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
//delete at the Head
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}
//Deletion
void deletion(node* &head,int val)
{
    if(head==NULL)
    {
        cout<<"There is no Node.That's why no deletion will be ocurred."<<"\n";
        return;
    }
    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }

    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
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
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    deletion(head,3);
    display(head);
    return 0;
}
