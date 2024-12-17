// REMOVE NTH NODE FROM END OF LIST

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

// LIST TRAVERSAL
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

// INSERTION OF A NODE
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

// FINDING LENGTH OF LIST
int getLength(Node *head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

// REMOVING NTH NODE FROM END
Node* remove_nth(Node* &head, int n){
    if(n==0){
        return head;
    }
    // IF LL IS EMPTY
    if(head == NULL || head->next == NULL && n==1){
        return NULL;
    }
    
    int len = getLength(head);
    int pos = len - n;
    
    Node *temp = head;
    Node *prev = NULL;

  // MEANS 1 POSITION
    if(pos == 0){
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    
    while(pos--){
        prev = temp;
        temp = temp->next;
    }
  
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    
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
