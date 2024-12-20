// MERGE TWO SORTED LINKED LIST INPLACE
// other method can be of taking an extra list and storing the values in it after comparing from both lists
// it will take extra space
// this code use method of pointer and solving problem inplace

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

// TRAVERSING DOUBLY LINKED LIST
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

// INSERTING DATA IN DOUBLY LINKED LIST
void insert_node(Node* &head, int data){
    Node *newNode = new Node(data);
    // if list is empty
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// MERGE TWO SORTED LIST INPLACE
Node* merge_list(Node* &head1, Node* &head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    Node* head = new Node(0);
    Node* tail = head;
    
    while(head1 && head2){
        if(head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
            tail = tail->next;
            tail->next = NULL;
        }
        else{
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = NULL;
        }
    }
    
    if(head1){
        tail->next = head1;
    }
    
    if(head2){
        tail->next = head2;
    }
    
    cout << head->data << endl;
    head = head->next;
    cout << head->data << endl;
    return head;
}

int main(){
    vector<int> arr1= {1,2,4};
    vector<int> arr2= {1,3,4};
    
    // HEAD POINTER
    Node *head1 = NULL;
    Node *head2 = NULL;
    
    // inserting array elements in doubly linked list
    for(int i=0; i<arr1.size(); i++){
        insert_node(head1, arr1[i]);
    }
    
    for(int i=0; i<arr2.size(); i++){
        insert_node(head2, arr2[i]);
    }
    
    // 
    traverse(head1);
    traverse(head2);
    
    // 
    Node* ans = merge_list(head1, head2);
    
    traverse(ans);
    
}
