Node *firstNode(Node *head) {
    if(head == NULL || head -> next == NULL) return NULL;
    Node* slow = head, *fast = head;
    do {
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(fast != NULL && fast -> next != NULL && fast != slow);
    if(fast == NULL || fast -> next == NULL) return NULL;
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}