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

// INSERTION AT BEGINNING/START/HEAD
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

// INSERTION AT LAST/END/TAIL
void insertAtEnd(Node*&head, Node*&tail, int data){
    Node *newNode = new Node(data);
    //if LL is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// INSERTION AT MIDDLE (positions can be start, last, mid)
void inserAtMiddle(Node*&head, Node*&tail, int data, int position){
    Node *newNode = new Node(data);
    //if position 1;
    if(position == 1){
        insertAtStart(head, tail, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt < position){
        temp = temp->next;
        cnt++;
    }
    //if position is last
    if(temp == NULL){
        insertAtEnd(head, tail, data);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// TRAVERSAL IN LINKED LIST
void traverse(Node*&head){
    //if LL is empty
    if(head == NULL){
        cout << "Linked List is empty" << endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// DELETION OF NODE FROM END
void deleteNode(Node *&head, Node*&tail, int position){
    // LL not empty
    if(head != NULL){
        // only one node exist
        if(head->next == NULL){
            delete head;   //free memory
            head = NULL;
            tail = NULL;
        }
        else{
            Node *cur = head;
            Node *prv = NULL;
            int cnt = 1;
            while(cnt < position){
                prv = cur;
                cur = cur->next;
                cnt++;
            }
            delete cur;
            prv->next = NULL;
            tail = prv;
          }
    }
}

int main(){
    
    // //CREATING NEW NODE USING DYNAMIC ALLOCATION
    // Node *newNode = new Node(4);
    Node *head = NULL;
    Node *tail = NULL;
    
    //insertion operation
    insertAtStart(head, tail, 20);         //at start
    traverse(head);
    inserAtMiddle(head, tail, 3, 1);       //at middle
    traverse(head);
    inserAtMiddle(head, tail, 13, 3);      //at middle
    traverse(head);
    insertAtEnd(head, tail, 7);            //at end
    traverse(head);
    insertAtEnd(head, tail, 44);           //at end
    traverse(head);
    inserAtMiddle(head, tail, 67, 2);      //at middle
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    //deletion operation
    deleteNode(head,tail, 6);                  //from end
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 5);                 //from end
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 4);                 //from end
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    
}
