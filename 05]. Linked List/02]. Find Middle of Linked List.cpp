Node *findMiddle(Node *head) {
    if(head == NULL || head -> next == NULL) return head;
    Node* slow = head, *fast = head;
    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}