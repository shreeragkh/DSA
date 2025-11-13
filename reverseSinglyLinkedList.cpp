#include<iostream>
using namespace std;

 struct Node
    {
        int data;
        Node* next;
        Node(int val){
            this->data=val;
            this->next=nullptr;
        }
    };
class reverseSinglyLinkedList
{

public:

    
    Node* reverseSinglyll(Node* head){
        Node* prev=nullptr;
        Node* curr=head;
        Node* next=nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void display(Node* head){
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
    Node* createNode(Node* head, int data){
        Node* newNode=new Node(data);
        if (head==nullptr)
        {
            return newNode;
        }
        Node* temp=head;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
        }
        
        
        temp->next=newNode;
        return head;
    }
    
};
int main(){
    reverseSinglyLinkedList rll;
    Node* head=nullptr;
    while (true)
    {
        int val;
        cin>>val;
        if(val==-1){
            break;
        }
        head=rll.createNode(head,val);
    }
    cout<<"Original Linked List:"<<endl;
    rll.display(head);
    head=rll.reverseSinglyll(head);
    cout<<"Reversed Linked List:"<<endl;
    rll.display(head);
    return 0;
    
}

