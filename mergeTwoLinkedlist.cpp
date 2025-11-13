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


class mergeTwoLinkedlist
{

public:
    Node* createNode(Node* head,int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
            return newNode;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;        
        }
        temp->next=newNode;
        return head;
    }

    void display(Node* head){
        Node* temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }

    Node* merge(Node* head1,Node* head2){
        if(head1==nullptr || head2==nullptr){
            return head1==nullptr ? head2 : head1;
        }
        if(head1->val <= head2->val){
            head1->next=merge(head1->next,head2);
            return head1;
        }
        else{
            head2->next=merge(head1,head2->next);
            return head2;
        }
    }
    
};
int main(){
    Node* head1=nullptr;
    Node* head2=nullptr;
    mergeTwoLinkedlist mll;
    while (true)
    {
        int val;
        cin>>val;
        if (val==-1)
        {
            break;
        }
        head1=mll.createNode(head1,val);
    }
    cout<<"First linked list:"<<endl;
    mll.display(head1);
     while (true)
    {
        int val;
        cin>>val;
        if (val==-1)
        {
            break;
        }
        head2=mll.createNode(head2,val);
    }
    cout<<"Second linked list:"<<endl;
    mll.display(head2);
    Node* mergeHead=mll.merge(head1,head2);
    cout<<"Merged linked list:"<<endl;
    mll.display(mergeHead);
    return 0;
    
}
