#include <iostream>
#include <stdlib.h>

using namespace std;

int count = 0;
string expr;

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
        cout << "Accepted" << endl;
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
        cout << "+";
    }
    else if (expr[count] == '-') {
        count++;
        T();
        Ed();
        cout << "-";
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
        cout << "*";
        F();
        Td();
    }
    else if (expr[count] == '/') {
        count++;
        cout << "/";
        F();
        Td();
    }
    else {
        // T'->null
    }
}

void F() {
    if (isalpha(expr[count])) {
        cout << expr[count];
        count++;
    }
    else if (isdigit(expr[count])) {
        cout << expr[count];
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
