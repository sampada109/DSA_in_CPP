// DELETION OF NODE COVERING ALL CASES IN DOUBLY LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;          // pointer of type Node, pointing to the previous node
    Node *next;          // pointer of type Node, pointing to the next node
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// DELETION ALL CASES
void deleteNode(Node*&head, Node*&tail, int position){
    // LL IS EMPTY
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
    
    // IF ONLY ONE NODE EXISTS
    if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    
    // NOW MORE THAN ONE NODE EXISTS IN LL
    
    // IF STARTING POSITION
    if(position == 1){
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    
    // OTHER THAN STARTING POSITION
    Node *cur = head;
    Node *prv = NULL;
    int cnt = 1;
    while(cur != NULL && cnt<position){
        prv = cur;
        cur = cur->next;
        cnt++;
    }
    
    // IF POSITION IS OUT OF RANGE
    if(cur == NULL){
        cout << "Position out of Range" << endl;
        return;
    }
    
    // IF LAST POSITION
    if(cur->next == NULL){
        prv->next = NULL;
        tail = prv;
    }
    else{  // IF IT IS ANY MIDDLE POSITION
        Node *curNext = cur->next;
        prv->next = cur->next;
        curNext->prev = cur->prev;
    }
    
    // CLEAN UP THE CURRENT NODE
    cur->next = NULL;
    cur->prev = NULL;
    delete cur;

}
