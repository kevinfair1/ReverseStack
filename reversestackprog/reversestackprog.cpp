#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

template<class Type>
class stackType
{
    Type stack[10];
    int top, n;

public:
    stackType()
    {
        top = -1;
        n = 50;
    }

    stackType(int size)
    {
        top = -1;
        n = size;
    }

    void push(Type value)
    {
        if (top < n - 1)
            stack[++top] = value;
        else
            cout << "\n\tstack is full.Can't insert " << value << endl;
    }

    void pop()
    {
        if (top < 0)
            cout << "\n\tstack is empty.\n";
        else
            cout << "\n\tPopped value : " << stack[top--];
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    void reverseStack(stackType<Type>& otherStack) {
        //Destroy content of other stack by making top to -1
        otherStack.top = -1;
        //Iterate the current stack and push the elements to other stack
        for (int i = top; i >= 0; i--) {
            otherStack.push(stack[i]);
        }
    }
};

int main()
{
    stackType<int> stack1;

    stack1.push(50);
    stack1.push(100);
    stack1.push(150);
    stack1.push(200);

    cout << "Stack1 content: \n";
    stack1.display();
    cout << endl;

    stackType<int> stack2;
    stack1.reverseStack(stack2);

    cout << "Stack2 content: \n";
    stack2.display();
    return 0;
}