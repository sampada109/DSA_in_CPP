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

void deleteNode(Node *&head, Node*&tail, int position){
    // LL not empty
    if(head != NULL){
        
        // only one node exist
        if(head->next == NULL){
            delete head;   //free memory
            head = NULL;
            tail = NULL;
        }
        // if there exist a LL with more than one Node
        else{
            //if first node
            if(position == 1){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            //if it is mid or last position
            else{
                Node *cur = head;
                Node *prv = NULL;
                int cnt = 1;
                while(cur!=NULL && cnt < position){
                    prv = cur;
                    cur = cur->next;
                    cnt++;
                }
                // Check if cur is NULL (position out of bounds)
                if (cur == NULL) {
                    cout << "Position out of bounds." << endl;
                    return;
                }
                //if last node
                if(cur->next == NULL){
                    delete cur;
                    prv->next = NULL;
                    tail = prv;
                }
                else{
                    prv->next = cur->next;
                    cur->next = NULL;
                    delete cur;
                }
            }
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
    deleteNode(head,tail, 1);                  //from start
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 5);                 //from end
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 3);                 //from middle
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 3);                 //from end
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 3);                 //out of range
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 1);                 //from start
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    deleteNode(head,tail, 1);                 //from start
    traverse(head);
    cout << "HEAD - " << head->data << endl;
    cout << "TAIL - " << tail->data << endl;
    
    
}
