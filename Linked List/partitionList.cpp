#include<iostream>
using namespace std;
class Node
{
public:
int data;
Node* next;
Node(int data){
    this->data=data;
    this->next=nullptr;
}   
};
Node* insert(Node* head,int data){
    Node* newNode=new Node(data);
    if(head==nullptr) return newNode;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void printHead(Node* head){
    if(head==nullptr) {
        cout<<"List is empty"<<endl; 
        return;
    }
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
Node* partitionList(Node* head, int x){
    Node* lessHead= new Node(0);
    Node* greaterEqualtoHead= new Node(0);
    Node* lessTail=lessHead;
    Node* greaterEqualtotail=greaterEqualtoHead;
    Node* current=head;
    while (current!=nullptr)
    {
        if(current->data<x){
            lessTail->next=current;
            lessTail=lessTail->next;
        }
        else{
            greaterEqualtotail->next=current;
            greaterEqualtotail=greaterEqualtotail->next;
        }
        current=current->next;
    } 
    greaterEqualtotail->next=nullptr;
    lessTail->next=greaterEqualtoHead->next;
    Node* newhead=lessHead->next;
    delete lessHead;
    delete greaterEqualtoHead;
    return newhead;
}
int main(){
    Node* head=nullptr;
    int value,x;
    cout<<"Enter the elements for the linkedlist (press -1 to exit):"<<endl;
    while (true)
    {
        cin>>value;
        if(value==-1){
            break;
        }
        head=insert(head,value);
    }
    cout<<"Original linkedlist:"<<endl;
    printHead(head);
    cout<<"Enter the key for partition:"<<endl;
    cin>>x;
    head=partitionList(head,x);
    cout<<"After partition:"<<endl;
    printHead(head);
}

