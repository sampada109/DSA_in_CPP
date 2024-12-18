// PALINDROME LINKED LIST 
// BY DIVIDING THE LIST AND REVERSING 2ND LIST AND THEN COMPARING BOTH
// Time Complexity - O(n) , Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;

// STRUCTURE OF NODE
class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// TRAVERSE LINKED LIST
void traverse(Node* head){
    if(head == NULL){
        return;
    }
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// INSERTION OF NODE IN LINKED LIST
void insert_node(Node* &head, int data){
    Node* newNode = new Node(data);
    // IF LL IS EMPTY
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// FINDING LENGTH OF LINKED LIST
int getLength(Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

// REVERSING THE LINKED LIST
Node* reverse(Node* &head){
    Node* prevNode = NULL;
    Node* curNode = head;
    Node* nextNode = NULL;
    
    while(curNode){
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
  
    return prevNode;
}

// COMPARING BOTH LINKED LIST
bool checkPalindrome(Node* &head, Node* &nextHead){
    while(head != NULL && nextHead != NULL){
        if(head->data != nextHead->data){
            return false;
        }
        head = head->next;
        nextHead = nextHead->next;
    }
    return true;
}

// CHECK PALINDROME
bool isPalindrome(Node* &head){
    int len = getLength(head);
    
    if(len == 0 || len == 1){
        return true;
    }
    
    int mid = (len/2) - 1;
    
    Node *temp = head;
    while(mid--){
        temp = temp->next;
    }
    
    Node *tempHead = temp->next;
    temp->next = NULL;
    
    Node* nextHead = reverse(tempHead);
    
    bool ans = checkPalindrome(head, nextHead);
    
    return ans;
}


int main(){
    // HEAD POINTER
    Node* head = NULL;
    
    vector<int> arr = {1,2,3,3,2,1};
    for(int i=0; i<arr.size(); i++){
        insert_node(head, arr[i]);
    }
    
    traverse(head);
    
    bool ans = isPalindrome(head);
    
    if(ans) cout << "true" << endl;
    else cout << "false" << endl;

}
