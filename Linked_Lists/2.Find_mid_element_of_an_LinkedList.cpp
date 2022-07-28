/*we increment slow ptr by 1 and fast ptr by 2, so if take a close look fast ptr will travel double than that of the slow pointer. 
So when the fast ptr will be at the end of Linked List, slow ptr would have covered half of Linked List till then. 
So slow ptr will be pointing towards the middle of Linked List.
*/

ListNode* middleNode(ListNode* head) {
    ListNode *fast=head,*slow=head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}