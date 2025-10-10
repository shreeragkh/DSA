#include <stack>
#include <utility>
#include <algorithm>
#include<iostream>
using namespace std;
class getMinvalue
{
    stack<pair<int, int>> s;
    int minValue;
public:
    void push(int x){
        if(s.empty()){
            s.push({x,x});
            minValue=x;
        }
        else{
            minValue = min(x, s.top().second);
            s.push({x, minValue});
        }
    }
    void pop(){
        if(s.empty()){
            cout<<"Stack is empty!"<<endl;
        }
        else{
           int val = s.top().first;
           s.pop();
           cout<<"Popped values is "<<val<<endl;
        }
    }
    int top(){
        int val=s.top().first;
        return val;
    }
    int getMin(){
        return s.top().second;
    }
};

int main(){
    int x,ch;
    bool t=true;
    getMinvalue v;
    while (t)
    {
        cout<<"1.Push\n2.Pop\n3.top\n4.getMin\n5.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the number to push:";
            cin>>x;
            v.push(x);
            break;
        case 2:
        v.pop();
        break;
        case 3:
        cout<<"Top value is "<<v.top()<<endl;
        break;
        case 4:
        cout<<"Minimum value is "<<v.getMin()<<endl;
        break;
        
        default:
        cout<<"Invalid choice"<<endl;
            break;
            case 5:
            t=false;
            break;
        }
    }
    return 0;
    
}