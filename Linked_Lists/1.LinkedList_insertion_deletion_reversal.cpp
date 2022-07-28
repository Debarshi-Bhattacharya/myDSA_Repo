#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
        int data;
        ListNode* next;

        ListNode()
        {
            data=0;
            next=NULL;
        }
        ListNode(int val)
        {
            data=val;
            next=NULL;
        }
        ListNode(int val, ListNode* next)
        {
            data=val;
            next=next;
        }
};


int length(ListNode* head)
{
    ListNode* temp=head;
    int c=0;
    while(temp)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
void insertAtHead(ListNode* &head,int val)
{
    ListNode* n=new ListNode(val);
    if(head==NULL)
        head=n;
    n->next=head;
    head=n;
}

void insertAtTail(ListNode* &head,int val)
{
    ListNode* n=new ListNode(val);
    ListNode* temp=head;
    while(temp->next)// to go the last node of the list
        temp=temp->next;
    temp->next=n;
}

void insertAtMiddle(ListNode* &head,int val,int pos)
{
    // if the list is empty or the position of insertion is 1; have to insert at Head
    if(head==NULL || pos==1)
        insertAtHead(head,val);

    //if the position of insertion is greater than that of length of current list(note: not more than by 1,otherwise invalid postion)
    //we have to insert at tail
    else if(length(head)+1==pos)
        insertAtTail(head,val);
    
    else if(length(head)+1<pos)
        cout<<"invalid postion; List size is: "<<length(head)<<endl;

    else
    {
        ListNode* temp=head;
        ListNode* n=new ListNode(val);
        for(int i=1;i<=pos-2;i++)
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
    
}

void deleteNode(ListNode* &head,int key)
{
    ListNode* temp=head;
    if(temp->data==key)//key is element pointed by head
    {
        head=temp->next;
        delete temp;
    }
    else
    {
        ListNode* prev;
        while(temp)
        {
            if(temp->data==key)
                break;
            prev=temp;
            temp=temp->next;
        }
        if(temp)
        {
            prev->next=temp->next;
            delete temp;
        }
        else
        {
            cout<<"key not found"<<endl;
        }
    }
}

//reversing Linked List; Iterative Aprroach1
ListNode* reverseList1(ListNode* head) {
    ListNode* prev_p=NULL;
    ListNode* curr_p=head;
    ListNode* next_p;
    
    while(curr_p)
    {
        next_p=curr_p->next;
        curr_p->next=prev_p;
        
        prev_p=curr_p;
        curr_p=next_p;
    }
    
    head=prev_p;
    return head;
        
}

//reversing Linked List; Iterative Aprroach2
ListNode* reverseList2(ListNode* head) {
    ListNode* newHead=NULL;
    ListNode* next_p;
    while(head!=NULL)
    {
        next_p=head->next;
        head->next=newHead;
        newHead=head;
        head=next_p;
    }
    return newHead;  
}

//reversing Linked List recursive aprroach

void print(ListNode* head)
{
    ListNode* temp=head;
    while(temp)
    {
        if (!temp->next)//for the last node
            cout<<temp->data;
        else
            cout<<temp->data<<"->";

        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *head=new ListNode(10);
    insertAtHead(head,7);
    insertAtHead(head,8);
    insertAtHead(head,5);
    insertAtHead(head,9);
    print(head);
    insertAtMiddle(head,2,1);
    print(head);
    insertAtMiddle(head,3,3);
    print(head);
    insertAtMiddle(head,4,8);
    print(head);
    insertAtMiddle(head,6,8);
    print(head);
    deleteNode(head,7);
    print(head);
    deleteNode(head,5);
    print(head);
    deleteNode(head,6);
    print(head);
    deleteNode(head,2);
    print(head);
    print(reverseList(head));
    return 0;
}