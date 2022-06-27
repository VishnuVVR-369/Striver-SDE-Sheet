Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* curr = dummy;
    while(first && second) {
        if(first -> data < second -> data) {
            curr -> next = first;
            first = first -> next;
        }
        else {
            curr -> next = second;
            second = second -> next;
        }
        curr = curr -> next;
    }
    if(first) curr -> next = first;
    if(second) curr -> next = second;
    return dummy -> next;
}