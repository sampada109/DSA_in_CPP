// FINDING THE MIDDLE OF THE LINKED LIST
// APPROCH 1 - finding length of linked list and then calculating the middle

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

// FINDING LENGTH OF LL
int getLength(Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

// MIDDLE 
Node * middle_node(Node* &head){
    // finding length of LL
    int len = getLength(head)/2;
    //
    // int cnt = 1;
    Node *temp = head;
    while(len--){
        temp = temp->next;
        // cnt++;
    }
    return temp;
}

int main(){
    
    // INITIALISING AN ARRAY
    vector<int> arr = {1,2,3,4,5};
    
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
    
    cout << ans->data << endl;
}
