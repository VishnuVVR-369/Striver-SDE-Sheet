LinkedListNode<int> *reverse(LinkedListNode<int>* head) {
    LinkedListNode<int> *prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
LinkedListNode<int> *getMiddleNode(LinkedListNode<int>* head) {
    LinkedListNode<int> *slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head -> next == NULL) return true;
    LinkedListNode<int> *mid = getMiddleNode(head);
    LinkedListNode<int> *revHead = reverse(mid);
    while(head != NULL && revHead != NULL) {
        if(head -> data != revHead -> data) return false;
        head = head -> next;
        revHead = revHead -> next;
     }
     return true;
}