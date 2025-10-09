#include <queue>
#include <iostream>
using namespace std;

class Mystack
{
public:
    queue<int> q1;
    queue<int> q2;
    Mystack(){

    }
    void push(int x){ //o(n)
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
                
    }
    void pop(){ //o(1)
        if(!q1.empty()){
        cout<<"Popped element is:"<<q1.front()<<endl;
        q1.pop();
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    void top(){ //o(1)
        if(!q1.empty()){
            cout<<"Top element is:"<<q1.front()<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    bool empty(){ //o(1)
        return q1.empty();
    }
};
int main(){
    Mystack s;
    bool t=true;
    while (t)
    {
        cout<<"1.push\n2.pop\n3.top\n4.empty\n5.exit\n";
        int ch;
        cin>>ch;
        switch (ch)
        {
        case 1:
        int x;
        cout<<"Enter the element to push:";
        cin>>x;
        s.push(x);
        break;
        case 2:
        s.pop();
        break;
        case 3:
        s.top();
            break;
            case 4:
            cout<<"Is queue empty? "<<s.empty()<<endl;
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

