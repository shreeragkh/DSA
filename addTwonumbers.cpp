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
Node* insert(Node* head, int data){
    Node* newNode= new Node(data);
    if(head==nullptr) return newNode;
    Node* temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void print(Node* head){
    if(head==nullptr){
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
Node* addNumber(Node* l1,Node* l2){
    Node* dummy=new Node(0);
    Node* current=dummy;
    int carry=0;
    while(l1!=nullptr || l2!=nullptr ||carry!=0){
        int val1=l1 ? l1->data: 0;
        int val2=l2 ? l2->data: 0;
        int sum=val1+val2+carry;
        carry=sum/10;
        int digit=sum%10;
        current->next=new Node(digit);
        current=current->next;
        if (l1!=nullptr)
        {
            l1=l1->next;
        }
        if (l2!=nullptr)
        {
            l2=l2->next;
        }
    }
    Node* result=dummy->next;
    return result;
}
int main(){
    Node* l1=nullptr;
    Node* l2=nullptr;
    int value;
    cout<<"Enter the numbers for list1 (input -1 to exit):"<<endl;
    while (true)
    {
        cin>>value;
        if(value==-1){
            break;
        }
        l1=insert(l1,value);
    }
    cout<<"Enter the numbers for list2 (input -1 to exit):"<<endl;
    while (true)
    {
        cin>>value;
        if(value==-1){
            break;
        }
        l2=insert(l2,value);
    }
    cout<<"List1:"<<endl;
    print(l1);
    cout<<"List2:"<<endl;
    print(l2);
    Node* result=addNumber(l1,l2);
    cout<<"Result:"<<endl;
    print(result);
    return 0;
}

