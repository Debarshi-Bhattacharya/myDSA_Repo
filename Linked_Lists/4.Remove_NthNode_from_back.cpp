ListNode* removeNthFromEnd(ListNode* &head, int n) {
    if(head->next==NULL)
        return NULL;
    //taking a temporary pointer which will act as first node of the given list;
    //so that at the time of deleting the first node,i.e,the last node from back; the pointer1 doesn't get exhausted and atleast points
    //to the last node. so that we can carry the operation with pointer2.
    ListNode* temp=new ListNode();
    temp->next=head;
    ListNode* p1=temp;
    ListNode* p2=temp;
    
    for(int i=1;i<=n;i++)
        p1=p1->next;
    while(p1->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    //p2 will point to the previous node of that very node we want to delete.
    //so we will connect the previos and next node of that particular node
    p2->next=p2->next->next;
    return temp->next;
    }