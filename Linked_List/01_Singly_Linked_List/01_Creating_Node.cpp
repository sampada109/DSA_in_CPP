// CREATING A LINKED LIST NODE

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;    //pointer of type Node (pointer pointing to node)
    
    //CONSTRUCTOR
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    
    //CREATING NEW NODE USING DYNAMIC ALLOCATION
    Node *newNode = new Node(4);
    
    cout << "Data - " << newNode->data << endl;
    cout << "Next - " << newNode->next << endl;
    
}
