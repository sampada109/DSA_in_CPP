#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};

void insertAtStart(Node* &head, Node*&tail, int data){
    Node *newNode = new Node(data);
    //if LL is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}


int main(){
  //CREATING HEAD AND TAIL POINTERS
  // HEAD will point to 1st node and TAIL will point to the last node
    Node *head = NULL;
    Node *tail = NULL;
    
  //insertion operation
  insertAtStart(head, tail, 20);         //at start
  insertAtStart(head, tail, 17);         //at start
  insertAtStart(head, tail, 3);         //at start
  insertAtStart(head, tail, 4);         //at start
  
}
