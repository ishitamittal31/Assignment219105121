// a) Create a singly linked list. Perform Insertion of an element after a Specified Value
// (given by the user at run time)

//19105121 - ISHITA MITTAL

#include <bits/stdc++.h>
using namespace std;

class Node{ // class made for linked list for type INT
    public:
        int data;//two members data of type int
        Node* next;// and next to store next node's position 
        Node(int data){
            this->data = data;
            this-> next = NULL;
        }
};

Node *takeInput(){
    int data;
    cin>>data; // we take the input from user till the user enters -1
    Node* head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *nextNode = new Node(data);
        if(head == NULL){
            head = nextNode;
            tail = nextNode;

        }
        else{
            tail->next = nextNode;// we insert the node at the end of the tail and update the tail
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){ // print the node till temp is not null
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* insertNodeInPosition(Node* head, int i, int data){// solution to insert the node
    Node* newNode = new Node(data); // make new node using the data entered by the user
    if(i==0){
        newNode->next = head; //if i is 0 then it is the first node so update the head and return
        return newNode;
    }
    if(!head){return head;}//corner case for head being null
   head->next = insertNodeInPosition(head->next, i-1, data); // call the function
}

int main(){
    Node* head = takeInput(); // make LL from user
    int position;//ask user specified position
    int data;//ask user data
    cin>>position>>data;
    head = insertNodeInPosition(head, position, data); //Solution
    print(head);
}