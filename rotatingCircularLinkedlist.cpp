#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int data){
        this->val=data;
        this->next=nullptr;
    }
};


class rotatingCircularLinkedlist
{
public:
Node* head;
Node* tail;
    rotatingCircularLinkedlist(){
        head=nullptr;
        tail=nullptr;
    }       
    void insertAthead(int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
            tail->next=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
            tail->next=newNode;
        }
    }
    void insertAttail(int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
            tail->next=newNode;
        }
        else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }

    }
    void display(Node* head){
        // Node* temp=head->next;
        if(head==NULL) return;
        cout<<head->val<<"->";
        Node* temp=head->next;
        while (temp!=head)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        // cout<<"HEAD"<<endl;
        cout<<temp->val<<endl;
    }
};
int main(){
    rotatingCircularLinkedlist rcll;
    rcll.insertAthead(10);
    rcll.insertAthead(20);
    rcll.insertAttail(5);
    rcll.display(rcll.head);
    return 0;
}

