/*Let last be the first
Send Feedback
Write a function that moves last element to front in a given singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
You just need to return the head of new linked list, don't print the elements.
Input format :
Line 1 : Linked list elements of length n (separated by space and terminated by -1)
Output format :
Updated list elements (separated by space)
Constraints :
1 <= n <= 10^4
Sample Input :
 1 2 3 4 5 6 -1
Note : -1 at the end of input is just a terminator representing the end of linked list. This -1 is not part of the linked list. Size of given linked list is 6.
Sample Output :
 6 1 2 3 4 5*/
 
 typedef Node<int> node;

Node<int>* moveToFront(Node<int> *head) {
	// Write your code here
    if(head ==NULL) return head;
    if(head->next==NULL) return head;
    node* cur=head->next->next;
    node* prev=head;
    
    while(cur!=NULL && prev->next!=NULL){
        prev=prev->next;
        cur=cur->next;
    }
    //cout<<prev->data<<endl;
    //return prev;
    node* tail=prev->next;
    prev->next=NULL;
    tail->next=head;
    return tail;
}
