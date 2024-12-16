// FINDING THE MIDDLE OF THE LINKED LIST
// APPROCH 2 - 2 Pointer, Fast and Slow Pointer
// Fast will move 2 steps and slow will move 1 step
// if fast covers N steps then slow will cover N/2 steps
// so, if length of linked list is N, then mid be will N/2, means slow will always points to middle element

#include<bits/stdc++.h>
using namespace std;

// NODE STRUCTURE
class Node{
    public:
    int data;
    Node *next;
    
    // CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TRAVERSAL
void traverse(Node* head){
    if(head == NULL){
        return;
    }
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// INSERTION 
void insert_node(Node* &head, Node* &tail, int data){
    Node *newNode = new Node(data);
    // IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// FIND MIDDLE NODE
Node * middle_node(Node* &head){
    // IF ZERO OR ONE NODE EXIST
    if(head == NULL || head->next == NULL){
        return head;
    }
    // IF ONLY 2 NODE EXISTS
    if(head->next->next == NULL){
        return head->next;
    }
    
    Node *slow = head;
    Node *fast = head->next;
    
    while(fast){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    
    return slow;
}

int main(){
    
    // INITIALISING AN ARRAY
    vector<int> arr = {1,2,3,4,5,6};
    
    // HEAD and TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // // INSERTING VALUES IN LINKED LIST
    for(int i=0; i<arr.size(); i++){
        insert_node(head, tail, arr[i]);
    }
    
    // // TRAVERSING
    traverse(head);
    
    // FINDING MIDDLE OF LINKED LIST
    Node *ans = middle_node(head);
    
    cout << "MIDDLE - " << ans->data << endl;
}
