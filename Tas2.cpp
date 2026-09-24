#include <iostream>
#include <string>
using namespace std;

class StringStack {
public:
    string* editor;
    int top;
    int capacity;

    StringStack(int capacity) {
        this->capacity = capacity;
        editor = new string[capacity];
        top = -1;
    }

    void push(string word) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        } else {
            editor[++top] = word;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        } else {
            top--;
        }
    }

    string const peek() {
        if (top == -1) {
            return "";
        } else {
            return editor[top];
        }
    }

    bool isempty() {
        return top == -1;
    }

    void clear() {
        top = -1;
    }

    ~StringStack() {
        delete[] editor;
    }
};

class WordEditor {
public:
    StringStack undoStack;
    StringStack redoStack;

    WordEditor() : undoStack(100), redoStack(100) {}

    void type(string x) {
        undoStack.push(x);
        redoStack.clear();
    }

    void undo() {
        if (!undoStack.isempty()) {
            redoStack.push(undoStack.peek());
            undoStack.pop();
        }
    }

    void redo() {
        if (!redoStack.isempty()) {
            undoStack.push(redoStack.peek());
            redoStack.pop();
        }
    }

    void print() {
        if (undoStack.isempty()) {
            cout << "[Empty Document]" << endl;
            return;
        }

        cout << "\"";
        for (int i = 0; i <= undoStack.top; i++) {
            cout << undoStack.editor[i];
            if (i < undoStack.top) {
                cout << " ";
            }
        }
        cout << "\"" << endl;
    }
};

int main() {
    WordEditor editor;

    cout << "type(\"Hello\"): ";
    editor.type("Hello");
    editor.print();

    cout << "type(\"World\"): ";
    editor.type("World");
    editor.print();

    cout << "undo(): ";
    editor.undo();
    editor.print();

    cout << "redo(): ";
    editor.redo();
    editor.print();

    cout << "undo(): ";
    editor.undo();
    editor.print();

    cout << "type(\"There\"): ";
    editor.type("There");
    editor.print();

    cout << "redo(): ";
    editor.redo();
    editor.print();

    return 0;
}