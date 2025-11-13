#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};

class removeDuplicatefromLinkedlist
{

public:
     Node* createList(Node* head, int data){
        Node* newNode=new Node(data);
        if(head==nullptr){
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
     void display(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
     }
     //  It is for unsorted LinkedList
     Node* removeDuplicateUnsorted(Node* head){
        Node* curr=head;
        while (curr!=nullptr && curr->next!=nullptr)
        {
            if(curr->val==curr->next->val){
                Node* deleteNode=curr->next;
                curr->next=curr->next->next;
                delete deleteNode;
            } else {
                curr = curr->next;
            }
        }
        return head;
     }
};
int main(){
    removeDuplicatefromLinkedlist rdl;
    Node* head=nullptr;
    while (true)
    {
        int val;
        cin>>val;
        if (val==-1)
        {
            break;
        }
        head=rdl.createList(head,val);
    }
    cout<<"Original List: ";
    rdl.display(head);
    // head=rdl.removeDuplicateUnsorted(head);
    // cout<<"List after removing duplicates: ";
    while (true)
    {
        int choice;
        cout<<"1. Remove Duplicates from Sorted Linked List"<<endl;
        cout<<"2. Remove Duplicates from Unsorted Linked List"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;
        if(choice==1){
            head=rdl.removeDuplicateUnsorted(head);
            cout<<"List after removing duplicates: ";
            rdl.display(head);
            break;
        } else if (choice==2){
            // For Unsorted linked list 
            Node* curr=head;
            while (curr!=nullptr)
            {
                Node*temp=curr;
                while (temp->next!=nullptr)
                {
                    if(temp->next->val==curr->val){
                        Node* deletNode=temp->next;
                        temp->next=temp->next->next;
                        delete deletNode;
                    }
                    else
                    {
                        temp=temp->next;
                    }
                }
                curr=curr->next;
            }
            cout<<"List after removing duplicates: ";
            rdl.display(head);
            break;
        } else if (choice==3){
                exit(0);
        } else {
            cout<<"Invalid Choice! Please try again."<<endl;
        }
    }
    return 0;
}

