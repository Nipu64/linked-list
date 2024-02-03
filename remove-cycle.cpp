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

//make a cycle
void makecycle(node* &head,int pos)
{
    node* temp=head;
    node* startnode;
     int cnt=1;
    while(temp->next!=NULL)
    {
         if(cnt==pos)
         {
            startnode=temp;
         }
         temp=temp->next;
         cnt++;
    }
    temp->next=startnode;
}
//detect cycle
bool detectcycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
//remove cycle
void removeCycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=slow)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=head;
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
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
   
   
   makecycle(head,3);
   removeCycle(head);
   cout<<detectcycle(head);
   
   
   
   
  
    return 0;
}
