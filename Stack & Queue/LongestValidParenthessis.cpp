#include <string>
#include <stack>
#include <iostream>
using namespace std;
using std::string;

class LongestValidParenthessis
{
public:
    int findLongestValidParenthessis(string s){
        stack<int>st;
        int maxi=0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                    if(st.empty()){
                        st.push(i);
                    }else{
                        maxi=max(maxi,i-st.top());
                    }
                }
            }
        }
        return maxi;
    }
};
int main(){
    string str;
    int num1;
    cout<<"Enter a valid string:"<<endl;
    cin>>str;
    LongestValidParenthessis p;
    num1=p.findLongestValidParenthessis(str);
    cout<<"Longest valid parenthesis is "<<num1<<endl;
    return 0;
}
// This code defines a C++ program that finds the length of the longest valid parentheses substring in a given string. It uses a stack to keep track of indices of characters and calculates the maximum length of valid parentheses as it iterates through the string. The main function takes user input for the string and outputs the result.
// If the character is '(' it pushes the index value into stack, if charcaher is ')' it pops the index value from the stack before popping it checks if the stack is empty or not , if it is empty the the index value is added to the stack otherwise the maximum length is calculated by subtracting the current index with the top value of the stack. Finally, it returns the maximum length of valid parentheses found in the string.