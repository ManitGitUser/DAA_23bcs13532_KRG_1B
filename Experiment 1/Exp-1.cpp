#include <iostream>
using namespace std;

class Stack {
    int *arr; 
    int top; 
    int capacity;

    public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow! Stack is empty.\n";
            return;
        }
        cout << "Popped " << arr[top--] << " from stack.\n";
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        else {
            cout << "Stack is empty.\n";
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    return 0;
}