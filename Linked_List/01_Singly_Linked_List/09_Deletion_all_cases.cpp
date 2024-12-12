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

// DELETION COVERING ALL CASES
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
}
