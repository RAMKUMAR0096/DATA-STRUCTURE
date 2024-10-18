#include <iostream.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(int);
int pop();
int isEmpty();  
void inToPost();
int space(char);
void print();
int pre(char);
int post_eval();

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
	result *= base;
    }
    return result;
}

int main()
{
    clrscr();
    int result;
    cout << "Enter the infix expression: ";
    cin.getline(infix, MAX);  // Use old-style cin.getline()
    inToPost();
    result = post_eval();
    print();
    cout<<"evaluation:";


    cout << result << endl;
    getch();
    return 0;
}

void inToPost() {
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infix); i++) {
	symbol = infix[i];
	if (!space(symbol)) {
	    switch (symbol) {
		case '(':
		    push(symbol);
		    break;
		case ')':
		    while ((next = pop()) != '(')
			postfix[j++] = next;
		    break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		    while (!isEmpty() && pre(stack[top]) >= pre(symbol))
			postfix[j++] = pop();
		    push(symbol);
		    break;
		default:
		    postfix[j++] = symbol;
	    }
	}
    }
    while (!isEmpty())
	postfix[j++] = pop();
    postfix[j] = '\0';
}

int space(char c) {
    return (c == ' ' || c == '\t');
}

int pre(char symbol) {
    switch (symbol) {
	case '^':
	    return 3;
	case '/':
	case '*':
	    return 2;
	case '+':
	case '-':
	    return 1;
	default:
	    return 0;
    }
}

void print() {
    int i = 0;
    cout << "The equivalent postfix expression is: ";
    while (postfix[i]) {
	cout << postfix[i++];
    }
    cout << endl;
}

void push(int val) {
    if (top == MAX - 1) {
	cout << "Stack overflow" << endl;
	return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    if (top == -1) {
	cout << "Stack underflow" << endl;
	exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}

int post_eval() {
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++) {
	if (postfix[i] >= '0' && postfix[i] <= '9') {
	    push(postfix[i] - '0');
	} else {
	    a = pop();
	    b = pop();
	    switch (postfix[i]) {
		case '+':
		    push(b + a);
		    break;
		case '-':
		    push(b - a);
		    break;
		case '*':
		    push(b * a);
		    break;
		case '/':
		    push(b / a);
		    break;
		case '^':
		    push(power(b, a));  // Use custom power function
		    break;
	    }
	}
    }
    return pop();
}
