// REMOVE EVERY KTH NODE FROM LIST

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


// REMOVE EVERY KTH NODE
Node* remove_nth(Node* &head, int k){
    Node *temp = head;
    Node *prev = NULL;
    
    // MEANS REMOVING EVERY NODE
    if(k==1){
        return NULL;
    }
    
    int count = 1;
    
    while(temp){
        if(count == k){
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
            count = 1;
        }
        else{
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
    
    return head;
}

int main(){
    // HEAD POINTER
    Node *head = NULL;
    
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    
    // INSERTING VALUES IN LL
    for(int i=0; i<arr.size(); i++){
        insert_node(head, arr[i]);
    }
    
    // 
    traverse(head);
    
    // remove nth node
    Node *ans = remove_nth(head, 3);
    
    // 
    traverse(ans);
}
