LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
    LinkedListNode<int> *curr = head, *next = head;
    while(curr != NULL) {
        next = curr -> next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(curr -> data);
        copy -> next = curr -> next;
        curr -> next = copy;
        curr = next;
    }
    curr = head;
    while(curr != NULL) {
        // if(curr -> random != NULL) {
        //     curr -> next -> random = curr -> random -> next;
        // }
        curr -> next -> random = curr -> random;
        curr = curr -> next -> next;
    }
    curr = head;
    LinkedListNode<int> *copyHead = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = copyHead;
    while(curr != NULL) {
        copy -> next = curr -> next;
        copy = copy -> next;
        curr -> next = curr -> next -> next;
        curr = curr -> next;
    }
    return copyHead -> next;
}