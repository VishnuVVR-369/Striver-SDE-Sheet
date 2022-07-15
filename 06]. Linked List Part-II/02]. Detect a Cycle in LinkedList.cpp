bool detectCycle(Node *head) {
    if(head == NULL || head -> next == NULL) return false;
    Node *slow = head, *fast = head;
    do {
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(fast != NULL && fast -> next != NULL && fast != slow);
    if(fast == NULL || fast -> next == NULL) return false;
    return true;
}