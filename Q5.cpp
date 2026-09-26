#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
public:
    Node* topNode;

    Stack() {
        topNode = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    int top() {
        if (empty()) {
            return -1;
        }
        return topNode->data;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

class MyQueue {
private:
    Stack incoming;
    Stack outgoing;

public:
    void enqueue(int item) {
        incoming.push(item);
    }

    int dequeue() {
        if (outgoing.empty()) {
            while (!incoming.empty()) {
                outgoing.push(incoming.pop());
            }
        }
        
        if (outgoing.empty()) {
            return -1; 
        }
        
        return outgoing.pop();
    }
};

int main() {
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << (char)q.dequeue() << endl;

    q.enqueue('C');

    cout << (char)q.dequeue() << endl;
    cout << (char)q.dequeue() << endl;

    return 0;
}