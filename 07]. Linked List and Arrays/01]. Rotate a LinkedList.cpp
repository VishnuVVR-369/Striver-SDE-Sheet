Node *rotate(Node *head, int k) {
    if(head == NULL || head -> next == NULL || k == 0) return head;
    int len = 1;
    Node* curr = head;
    while(curr -> next != NULL) {
        len++;
        curr = curr -> next;
    }
    curr -> next = head;
    k %= len;
    int end = len - k;
    while(end--) curr = curr -> next;
    head = curr -> next;
    curr -> next = NULL;
    return head;
}