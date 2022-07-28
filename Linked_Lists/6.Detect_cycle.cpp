bool hasCycle(ListNode *head) {
        // using HashTable
        unordered_set<ListNode*>table;
        while(head)
        {
            if(table.find(head)!=table.end()) return true;
            table.insert(head);
            head=head->next;   
        }
        return false;
        
        //using fast and slow pointer
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                return true;
        }
        return false;
    }