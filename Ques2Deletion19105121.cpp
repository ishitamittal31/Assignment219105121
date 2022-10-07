// b) Create a doubly linked list. Perform Deletion of an element (given by the user at run time)

// //19105121 - ISHITA MITTAL

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;//create node class with prev and next 
    Node(int data){
        this->data = data;//parameterised constructor
        this->prev = NULL;
        this->next = NULL;
    }
};
 



void deletion(Node *head, int data){//data to be deleted

    if(head == NULL){
        return;
    }
    if(head->data == data){
        Node *temp = head->prev;
        temp->next = head->next;// connect two nodes
        if(head->next) head->next->prev = temp;// if case for last node
        return;
    }
    deletion(head->next, data);

}

Node *insert(){

    Node* prev = NULL;
    Node* head = NULL;
  
    int data;
    cin>>data;
    while(data!= -1){

        Node * nn = new Node(data);//new node
        if(head == NULL){//for first node
            nn->prev = NULL;
            nn->next = NULL;
            head = nn;
            prev = nn;
        }
        else{
            prev->next = nn; //update the references
            nn->prev = prev;
            prev = nn;
        }
        
        cin>>data;

    }
    return head;//return head

}


void print(Node* node)//for printing the node
{
    while (node != NULL)//print till the node is null
    {
        cout << node->data << " ";
        node = node->next;
    }
}
 

int main()
{

    // Node* head = NULL;
    
    cout<<"Please enter the node data for the linked list";
    
    Node* head = insert();
    cout<<"Enter the node to be deleted";
    int data;
    cin>>data; // the number which needs to be deleted
    if(head!=NULL && head->data==data) head=head->next;
    else deletion(head, data);

    cout << "Modified Linked list ";
    print(head);
 
    return 0;
}

