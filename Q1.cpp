#include <iostream>
using namespace std;
#include <string>

//A text editor stores the last 8 editing operations in a stack. Each operation is represented by
//an integer code. The editor receives the following operations:
//12, 25, 17, 31, 44, 19
//The user then presses Undo three times, performs a new operation 52, and presses Undo
//twice again. Implement the system using an array-based stack. After every operation, display
//the current top operation. At the end, display the operations that remain in the stack from top
//to bottom.
//Your program should also handle an Undo request when the stack is empty.




class Stack{
	public:
	int *array;
	int size;
	int top;

	Stack(int size){
		this->size = size;
		array = new int[size];
		top = -1;
	}

	void push(int x){
		if(top == size-1){
			cout<<"Stack Overflow"<<endl;
		}

		else{
		array[++top] = x; 	
		}
	}

	void pop(){
		if(top == -1){
			cout<<"Stack Underflow"<<endl;
		}

		else{
			top--;
		}

	}

	int const peek(){

		if(top==-1){
			cout<<"The Stack is empty"<<endl;
			return -1;
		}
		return array[top];
	}

	void display(){
		if(top == -1){
			cout<<"stack Empty"<<endl;
			return;
		}
		cout<<endl;
		cout<<"The Stack Values Top To Bottom: "<<endl;
		for(int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
}	

~Stack(){
	delete[] array;
}

};


int main(){
		Stack operation(8);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(12);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(25);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(17);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(31);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(44);
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.push(19);
		cout<<"The Top is now at: "<<operation.peek()<<endl;

		operation.pop();
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.pop();
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.pop();
		cout<<"The Top is now at: "<<operation.peek()<<endl;

		operation.push(52);
		cout<<"The Top is now at: "<<operation.peek()<<endl;

		operation.pop();
		cout<<"The Top is now at: "<<operation.peek()<<endl;
		operation.pop();
		cout<<"The Top is now at: "<<operation.peek()<<endl;

		operation.display();

}





