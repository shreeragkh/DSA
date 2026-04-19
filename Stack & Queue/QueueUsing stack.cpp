#include <iostream>
#include <stack>
using namespace std;
class QueueUsingStack
{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        while (!s1.empty())
        {
           s2.push(s1.top());
           s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        if(!s1.empty()){
            cout<<"Popped element is:"<<s1.top()<<endl;
            s1.pop();
        }
        else{
            cout<<"Queue is empty"<<endl;
        }
    }
    void peek(){
        if(!s1.empty()){
            cout<<"Front element is :"<<s1.top()<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    bool empty(){
        return s1.empty();
    }
};
int main(){
    QueueUsingStack q;
    bool t=true;
    while(t){
        cout<<"1.push\n2.pop\n3.peek\n4.empty\n5.exit\n";
        int ch;
        cin>>ch;
        switch (ch)
        {
        case 1:
        int x;
        cout<<"Enter the element to push:";
        cin>>x;
        q.push(x);
        break;
        case 2:
        q.pop();
        break;
        case 3:
        q.peek();
        break;
        case 4:
        cout<<"Is queue empty: "<<q.empty()<<endl;
        break;
        case 5:
        t=false;
        break;
        
        default:
        cout<<"Invalid choice"<<endl;
            break;
        }
    }
}
