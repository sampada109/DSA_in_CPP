// CIRCULAR LINKED LIST

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


int main(){
    
    Node *newNode = new Node(4);
    newNode->next = newNode;    //next will point itself only for Circular Linked List
    
    cout << "DATA - " << newNode->data  << endl;
    cout << "NEXT - " << newNode->next << endl;
    cout << "NewNode Value - " << newNode << endl;
    
}
