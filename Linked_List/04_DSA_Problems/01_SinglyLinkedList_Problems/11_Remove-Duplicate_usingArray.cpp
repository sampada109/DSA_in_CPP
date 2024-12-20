// REVOME DUPLICATES FROM SORTED LINKED LIST
// extra space for using array to store unique elements

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

// TRAVERSING DOUBLY LINKED LIST
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

// INSERTING DATA IN DOUBLY LINKED LIST
void insert_node(Node* &head, int data){
    Node *newNode = new Node(data);
    // if list is empty
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// REMOVE DUPLICATES USING ARRAY
Node* remove_duplicate(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    // taking array
    vector<int> ans;
    ans.push_back(head->data);

    // first store all unique elements in array
    Node* cur = head->next;
    while(cur){
        if(ans[ans.size()-1] != cur->data){
            ans.push_back(cur->data);
        }
        cur = cur->next;
    }
    cur = head;

    // then update list with the unique data
    for(int i=0; i<ans.size(); i++){
        cur->data = ans[i];
        cur = cur->next;
    }
    cur = head;

    // at last break list 
    int size = ans.size()-1;
    while(size--){
        cur = cur->next;
    }
    cur->next = NULL;
    
    return head;
}

int main(){
    vector<int> arr= {1,1,2,3,3};
    
    // HEAD POINTER
    Node *head = NULL;
    
    // inserting array elements in doubly linked list
    for(int i=0; i<arr.size(); i++){
        insert_node(head, arr[i]);
    }
    
    // 
    traverse(head);
    
    // 
    Node* ans = remove_duplicate(head);
    
    traverse(ans);
    
}
