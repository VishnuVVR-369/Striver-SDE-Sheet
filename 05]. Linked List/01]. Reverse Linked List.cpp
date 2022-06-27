LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)  {
    if(head == NULL || head -> next == NULL) return head;
    LinkedListNode<int> *curr = head, *prev = NULL, *next = NULL;
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}