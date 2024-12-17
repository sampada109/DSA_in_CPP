// ROTATE LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TRAVERSAL OF LIST
void traverse(Node* head){
    // IF LL IS EMPTY
    if(head == NULL){
        return;
    }
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// INSERTION OF NODE
void insert_node(Node* &head, int data){
    Node *newNode = new Node(data);
    // IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        return;
    }
    //
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// FINDING LENGTH OF LINKED LIST
int getLength(Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

// ROTATE LIST
Node* remove_nth(Node* &head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node *cur = head;
    Node *curHead = NULL;
    
    int len = getLength(head);
    k = k%len;
    int pos = (len - k)-1;
    
    if(k==0){
        return head;
    }
    
    while(pos--){
        cur = cur->next;
    }
    curHead = cur->next;
    cur->next = NULL;
    
    Node* temp = curHead;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = curHead;
    
    
    return head;
}

int main(){
    // HEAD POINTER
    Node *head = NULL;
    
    vector<int> arr = {1,2,3,4,5};
    
    // INSERTING VALUES IN LL
    for(int i=0; i<arr.size(); i++){
        insert_node(head, arr[i]);
    }
    
    // 
    traverse(head);
    
    // remove nth node
    Node *ans = remove_nth(head, 2);
    
    // 
    traverse(ans);
}
