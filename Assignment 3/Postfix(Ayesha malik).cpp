#include <iostream>
#include <stack>

using namespace std;

int count = 0;
string expr;
string postfixExpr;

void E();
void Ed();
void T();
void Td();
void F();

int main() {
    cin >> expr;
    int l = expr.length();
    expr += "$";
    E();
    
    if (l == count)
        cout << "Accepted" << endl << "Postfix Expression: " << postfixExpr << endl;
    else
        cout << "Rejected" << endl;
}

void E() {
    T();
    Ed();
}

void Ed() {
    if (expr[count] == '+') {
        count++;
        T();
        Ed();
        postfixExpr += "+";
    }
    else if (expr[count] == '-') {
        count++;
        T();
        Ed();
        postfixExpr += "-";
    }
    else {
        // E'->null
    }
}

void T() {
    F();
    Td();
}

void Td() {
    if (expr[count] == '*') {
        count++;
        F();
        Td();
        postfixExpr += "*";
    }
    else if (expr[count] == '/') {
        count++;
        F();
        Td();
        postfixExpr += "/";
    }
    else {
        // T'->null
    }
}

void F() {
    if (isalpha(expr[count]) || isdigit(expr[count])) {
        postfixExpr += expr[count];
        count++;
    }
    else if (expr[count] == '(') {
        count++;
        E();
        if (expr[count] != ')') {
            cout << "Rejected" << endl;
            exit(0);
        }
        count++;
    }
    else {
        cout << "Rejected" << endl;
        exit(0);
    }
}
