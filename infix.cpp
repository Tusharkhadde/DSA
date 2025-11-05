#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyop(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // assume no divide by zero
    }
    return 0;
}

// Evaluate infix expression
int evaluate(string expr) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ')
            continue;

        // If digit, extract full number
        if (isdigit(expr[i])) {
            int val = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            values.push(val);
            i--; // step back one position
        }

        // If '(' push to operator stack
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }

        // If ')' solve entire bracket
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyop(val1, val2, op));
            }
            ops.pop(); // pop '('
        }

        // If operator, handle precedence
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                values.push(applyop(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    // Apply remaining operations
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        values.push(applyop(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter infix expression: ";
    getline(cin, expression);

    cout << "Result: " << evaluate(expression) << endl;
    return 0;
}
