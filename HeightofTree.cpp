#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
};
Node* bulitTree(){
    int val;
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    Node* root=new Node(val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        int leftval,rightval;
        cin>>leftval>>rightval;
        if(leftval!=-1){
            temp->left=new Node(leftval);
            q.push(temp->left);
        }
        if(rightval!=-1){
            temp->right=new Node(rightval);
            q.push(temp->right);
        }
    }
    return root;
}
int height(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return  max(leftHeight,rightHeight)+1;
}
int main(){
    Node* root=bulitTree();
    cout<<"Height of the tree is:"<<height(root)<<endl;
    return 0;
}