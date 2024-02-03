#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss "\n"
using namespace std;
class node{
      public:
      int data;
      node* next;

      node(int val)
      {
        data=val;
        next=NULL;
      }
};
//insert node at the head
void insertAtHead(node* &head,int val)
{
   node* n=new node(val);
   n->next=head;
   head=n;
}
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
//insert node at the random node
void insertNode(node* &head,int val,int pos)
{
    node* n=new node(val);
    node* temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;

}
//searching a node
bool searching(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return true;
        temp=temp->next;
    }
    return false;
}
//reverse full linked list in a iterative way
node* reverse(node* &head)
{
    node*  preptr=NULL;
    node*  curptr=head;
    node*  nextptr;
    while(curptr!=NULL)
    {
          nextptr=curptr->next;
          curptr->next=preptr;

          preptr=curptr;
          curptr=nextptr;

    }
    return preptr;
}
//reverse in recursive way
node* reverseRecursive(node* &head)
{
    if(head==NULL || head->next==NULL)
    return head;
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

//kth node reverse in recursive way
node* reversek(node* &head, int k)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int cnt=0;
    while(currptr!=NULL && cnt<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;

        cnt++;
    }
    if(nextptr!=NULL)
    {
        head->next=reversek(nextptr,k);
    }
    return prevptr;
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
    cout<<"NULL"<<endl;
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
   int k=2;
   node* newhead1=reversek(head,k);
   display(newhead1);
   //node* newhead2=reverseRecursive(head);
   //display(newhead2);
   
   
   
  
    return 0;
}
