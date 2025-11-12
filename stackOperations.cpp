#include<iostream>
using namespace std;
class stackOperations
{
     int* stack;
     int size,top;
public:
    stackOperations( int size){
        top=-1;
        this->size=size;
        stack=new int[size];
    }
    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            stack[top]=val;
        }
    }
    int pop(){
        if(top<0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            int temp=stack[top];
            top--;
            return temp;
        }
    }
    void display(){
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<"->";
    }
    cout<<"NULL"<<endl;
}
    void peek(){
        if(top<0){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<stack[top]<<endl;
        }
    }
    stackOperations(){
        delete[] stack;
    }
};
int main(){
    cout<<"Enter the size of stack:"<<endl;
    int size;
    cin>>size;
    stackOperations st(size);
    while (true)
    {
        cout<<"1.Push \n2.Pop \n3.Display \n4.Peek \n5.Exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            int val;
            cout<<"Enter the value to be pushed:"<<endl;
            cin>>val;
            st.push(val);
            break;
        case 2:
            cout<<"Popped value is "<<st.pop()<<endl;
            break;
        case 3:
            st.display();
            break;
        case 4:
            st.peek();
            break;
        case 5:
            exit(0);
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    
}

