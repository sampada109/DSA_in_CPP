// REMOVE DUPLICATES FROM SORTED LINKED LIST INPLACE
// TAKING 2 POINTER TO SOLVE THE PROBLEM INPLACE
// TAKING NO EXTRA SPACE

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

// REMOVE DUPLICATES USNIG TWO POINTERS
Node* remove_duplicate(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    // taking 2 pointers
    Node* prev = head;
    Node* cur = head->next;
    
    while(cur){
        if(prev->data == cur->data){
            prev->next = cur->next;
            cur->next = NULL;
            delete cur;
            cur = prev->next;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
    
    return head;
}

int main(){
    vector<int> arr= {1,1,2,3,3,4,5,5,5};
    
    // HEAD POINTER
    Node *head = NULL;
    
    // inserting array elements in doubly linked list
    for(int i=0; i<arr.size(); i++){
        insert_node(head, arr[i]);
    }
    
    // 
    traverse(head);
    
    // 
    Node* ans = remove_duplicate(head);
    
    traverse(ans);
    
}
