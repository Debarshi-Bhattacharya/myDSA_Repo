ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //res for the linked list with calculated sum
    ListNode* res=new ListNode();
    ListNode* temp=res;// copying to temp variable for traversal
    int carry=0;
    while((l1 || l2) || carry)
    {
        int sum=0;
        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        ListNode* newNode=new ListNode(sum%10);
        temp->next=newNode;
        temp=temp->next;  
    }
    return res->next;   
}

//Time Complexiety: O(max(m,n)); m,n: size of the both list respectively