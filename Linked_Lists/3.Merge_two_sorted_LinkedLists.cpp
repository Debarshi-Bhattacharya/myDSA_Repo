ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // when list1 is empty then our output will be same as list2
    if(list1==NULL)
        return list2;

    // when list2 is empty then our output will be same as list1
    if(list2==NULL)
        return list1;

    //here we will keep a notion every time that the smaller element will always be pointed by list1
    if(list1->val > list2->val)
    {
        swap(list1,list2);
    }
    ListNode* res=list1;//at first list1 will be pointing towards the smallest value among both the lists; so in final we have to return
    //that pointer as a head of the merged list
    
    while(list1 && list2)
    {
        ListNode* temp=NULL;
        while(list1!=NULL && list1->val <= list2->val)
        {
            temp=list1;//to keep track of the previous list1 pointer
            list1=list1->next;  
        } 
        //if the node value pointed by list1 gets larger than list2; then we have to cut-off the link between temp and list1, 
        //as in between then smaller node pointed by list2 should come. So we will make a connection between temp and list2.
        temp->next=list2;
        //Another we have to do here that;as first discussed the smaller node should always be pointed by list1. 
        //So, we have to swap the two pointers list1 & list2 here.
        swap(list1,list2);
    }
    return res;
    }