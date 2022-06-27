LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K) {
    if(K == 0) return head;
    if(head == NULL) return head;
    LinkedListNode<int> *start = new LinkedListNode<int>(0);
    LinkedListNode<int> *slow = start, *fast = start;
    slow -> next = head;
    for(int i = 1; i <= K + 1; i++) {
        fast = fast -> next;
    }
    while(fast != NULL) {
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = slow -> next -> next;
    return start -> next;
}