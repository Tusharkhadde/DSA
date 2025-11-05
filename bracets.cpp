#include <iostream>
#include <stack>
using namespace std;

int minReversals(string expr) {
    int len = expr.length();
    if(len%2!=0) return -1;
    stack<char>s;
    for(char ch : expr){
        if(ch=='(') s.push(ch);
        else {
            if(!s.empty() && s.top()=='(') s.pop();
            else s.push(ch);
        }
    }
    int open = 0,close =0;
    while(!s.empty()){
        if(s.top()=='(') open++;
        else close++;
        s.pop();
    }
    return (open+1)/2 + (close+1)/2;
}

int main() {
    string expr;
    cout << "Enter bracket expression: ";
    cin >> expr;

    int result = minReversals(expr);
    if (result == -1)
        cout << "Not possible to balance\n";
    else
        cout << "Minimum reversals needed: " << result << endl;
    return 0;
}