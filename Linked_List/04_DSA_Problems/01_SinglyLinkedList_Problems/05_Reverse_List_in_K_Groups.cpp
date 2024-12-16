// REVERSE LINKED LIST IN K GROUPS USING RECURRSION

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

// FINDING LENGTH OF LINKED LIST
int getLength(Node* head){
    int len = 0;
    while(head){
        head = head->next;
        len++;
    }
    return len;
}

// REVERSE LINKED LIST WITH K GROUPS
Node * kReverse(Node* &head, int k){
    if(head == NULL){
        return NULL;
    }
    
    // for k nodes
    Node *prevNode =NULL;
    Node *curNode = head;
    Node *nextNode = NULL;
    int cnt = 0;
    
    while(curNode != NULL && cnt<k){
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        cnt++;
    }
    
    // recursion call for next k nodes
    // linking the next n nodes with the last node of current k group
    if(curNode!=NULL && getLength(curNode)>=k){
        head->next = kReverse(curNode, k);
    }
    else{
        head->next = curNode;
    }
    
    // this will point to the node which will be prevNode first time
    return prevNode;
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
    Node *ans = kReverse(head,4);
    traverse(ans);
  
}
