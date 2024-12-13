// CREATING A DOUBLY LINKED LIST NODE

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;        // pointer of type Node, pointing to the previous node
    Node *next;       // pointer of type Node, pointing to the next node
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

int main(){
  
    //CREATING NEW NODE USING DYNAMIC ALLOCATION
    Node *newNode = new Node(10);
    
    cout << "PREVIOUS - " << newNode->prev << endl;
    cout << "DATA - " << newNode->data << endl;
    cout << "NEXT - " << newNode->next << endl;
        
}
