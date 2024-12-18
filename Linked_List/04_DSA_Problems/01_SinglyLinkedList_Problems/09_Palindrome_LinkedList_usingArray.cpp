// PALINDROME LINKED LIST
// Time Complexity - O(n) ,for traversing the ll for converting to array and isPlaindrome traverse the array  
// Space Complexity - O(n), for using extra array to store ll values

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

// CONVERT LL INTO ARRAY
vector<int> to_array(Node* head){
    vector<int> arr;
    while(head != NULL){
        arr.push_back(head->data);
        head = head->next;
    }
    return arr;
}

// CHECK PALINDROME
bool isPalindrome(Node* &head){
    vector<int> arr = to_array(head);
    
    int i = 0;
    int j = arr.size()-1;
    
    while(i<j){
        if(arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
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
