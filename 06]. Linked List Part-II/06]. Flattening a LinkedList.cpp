Node* mergeTwoLinkedLists(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(head1 && head2) {
        if(head1 -> data < head2 -> data) {
            curr -> child = head1;
            head1 = head1 -> child;
        }
        else {
            curr -> child = head2;
            head2 = head2 -> child;
        }
        curr = curr -> child;
    }
    if(head1) curr -> child = head1;
    if(head2) curr -> child = head2;
    return dummy -> child;
}


Node* flattenLinkedList(Node* head) {
    if(head == NULL || head -> next == NULL) return head;
    return mergeTwoLinkedLists(head, flattenLinkedList(head -> next));
}