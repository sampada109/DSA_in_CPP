// REVERSE LINKED LIST PROBLEM - REVERSING LINKED LIST **DATA**
// TO REVERSE A LINKED LIST ON THE BASICS OF DATA, ARRAY IS USED

#include<bits/stdc++.h>
using namespace std;

// NODE STRUCTURE
class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TRAVERSAL
void traverse(Node *&head){
    // IF LINKED IS EMPTY
    if(head == NULL){
        return;
    }
    Node *temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// INSERTION AT END
void insert_node(Node* &head, Node*&tail, int data){
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

// REVERSE A LINKED LIST
Node* reverse(Node* &head){
    // METHOD 1 USING ARRAY
    vector<int> ans;
    Node *temp = head;
    // storing data in array
    while(temp){
        ans.push_back(temp->data);
        temp = temp->next;
    }
    //
    int i = ans.size()-1;
    // now changing the value of original LL
    temp = head;
    while(temp){
        temp->data = ans[i];
        i--;
        temp = temp->next;
    }
    return head;
}

int main(){
    // INITIALISING AN ARRAY
    vector<int> arr = {1,2,3,4,5};
    
    // INITIALISING HEAD POINTER AND TAIL POINTER
    Node *head = NULL;
    Node *tail = NULL;
    
    // INSERT ARRAY ELEMENT IN LINKED LIST
    for(int i=0; i<arr.size(); i++){
        insert_node(head, tail, arr[i]);
    }
    
    traverse(head);
    
    reverse(head);
    
    traverse(head);
    
}
