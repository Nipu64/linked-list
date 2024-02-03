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
//add node at the tail
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
//add value int the head
void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}
//add the value random node
void add(node* &head,int val,int pos)
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
// print
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
//searching value
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
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,5);
    display(head);
    cout<<searching(head,6)<<endl;
    add(head,4,1);
    display(head);
    
    return 0;
}
