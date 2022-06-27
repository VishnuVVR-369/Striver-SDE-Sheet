#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2) {
    Node* ans = NULL, *last = NULL;
    int carry = 0;
    while(head1 != NULL && head2 != NULL) {
        int val = head1 -> data + head2 -> data + carry;
        Node* newNode = new Node(val % 10);
        carry = val / 10;
        if(ans == NULL) {
            ans = last = newNode;
        }
        else {
            last -> next = newNode;
            last = last -> next;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1 != NULL) {
        int val = head1 -> data + carry;
        Node *newNode = new Node(val % 10);
        last -> next = newNode;
        last = last -> next;
        head1 = head1 -> next;
        carry = val / 10;
    }
    while(head2 != NULL) {
        int val = head2 -> data + carry;
        Node *newNode = new Node(val % 10);
        last -> next = newNode;
        last = last -> next;
        head2 = head2 -> next;
        carry = val / 10;
    }
    if(carry) {
        Node *newNode = new Node(carry);
        last -> next = newNode;
        last = last -> next;
    }
    return ans;
}