#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
    public:
        int Value;
        Node* Next;
};

void PrintList(Node* n){    //不會改變head的值
    if(n == NULL) {
        cout << "The linked list is empty" << endl;
    }
    while(n != NULL){
        cout << n->Value << endl;
        n = n -> Next;
    }
}

void PushFront(Node** head, int NewValue){ //會改變head
    //1.Prepare a newNode
    Node* newNode = new Node;
    newNode -> Value = NewValue;
    //2.Put it in front of current head
    newNode -> Next = *head;
    //3.Move head of the list to point to the newNode
    *head = newNode;
}

void PushBack(Node** head, int NewValue){
    //1.Prepare a newNode
    Node* newNode = new Node;
    newNode -> Value = NewValue;
    newNode -> Next = NULL;
    //2.If Linked list is empty, newNode will be a head node
    if(*head == NULL){
        *head = newNode;
        return;
    }
    //3.Find the last node
    Node* last = *head;
    while(last -> Next != NULL){
        last = last -> Next;
    }
    //4.Insert newNode after last node (at the end)
    last -> Next = newNode;
}

void insertAfter(Node* previous, int NewValue){
    //1.Check if previous node is NULL
    if(previous == NULL){
        cout << "Previous can not be NULL." << endl;
        return;
    }
    //2.Prepare a newNode
    Node* newNode = new Node;
    newNode -> Value = NewValue;
    //3.Insert newNode after previous
    newNode -> Next = previous -> Next;
    previous -> Next = newNode;
}

int main(){
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head -> Value = 1;
    head -> Next = second;
    second -> Value = 20;
    second -> Next = third;
    third -> Value = 300;
    third -> Next = NULL;

    PushFront(&head, -1);
    PushBack(&head, 99);
    insertAfter(second, 25);
    PrintList(head);

}






/* Struct
struct Node {
    int data;
    Node *next;
};

void PrintLinkedList(Node *head) {
    Node *current = head;
    cout << "Linked List : \n";
    if(current == NULL) {
        cout << "Linked list is empty" << endl;
    }
    while(current != NULL) {
        cout << current -> data << endl;
        current = current -> next;
    }
}

void DeleteNode(Node * &head, int target) {
    Node *temp, *follow;
    temp = head;

    if(head -> data == target) {
        head = head -> next;
        delete temp;
    }
    
    while(temp != NULL && temp -> data != target) {
        follow = temp;
        temp = temp -> next;
    }
    if(temp == NULL) {
        cout << "Not found " << target << " in the linked list." << endl;
    }
    else{
        follow -> next = temp -> next;
        delete temp;
    }
}

void PushFront(Node * &head, int NewData) {   //function call by reference
    Node *newNode = new Node;
    newNode -> data = NewData;
    newNode -> next = head;
    head = newNode;
}

void PushBack(Node *head, int NewData) {
    Node *current = head;
    Node *newNode = new Node;
    newNode -> data = NewData;
    newNode -> next = NULL;

    while(current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;  
}

void ReverseLinkedList(Node * &head) {
    Node *precede, *previous = NULL;
    while(head -> next != NULL) {
        precede = head -> next;
        head -> next = previous;
        previous = head;
        head = precede;     
    }
    head -> next = previous;
}

void ClearLinkedList(Node *head) {
    Node *follow = head;
    while(head -> next != NULL) {
        follow = head;
        head = head -> next;
        delete follow;
    }
    delete follow;
}

int main(){
    Node *head = new Node();
    head -> data = 11;  //(*head).data = 11;
    head -> next = NULL;

    Node *Current = head;
    for(int i = 0; i < 5; ++i) {
        Current -> next = new Node();
        Current = Current -> next;
        Current -> data = 11 * (i+2);
        Current -> next = NULL;
    }

    PrintLinkedList(head);  // 11, 22, 33, 44, 55, 66
    DeleteNode(head, 33);
    PushFront(head, 100);
    PushBack(head, -1000);
    PushBack(head, 99);
    DeleteNode(head, -1000);
    PrintLinkedList(head);  // 100, 11, 22, 44, 55, 66, 99

    ReverseLinkedList(head);
    PrintLinkedList(head);  // 99, 66, 55, 44, 22, 11, 100

    //ClearLinkedList(head);
    DeleteNode(head, 99);
    PrintLinkedList(head);


}
*/