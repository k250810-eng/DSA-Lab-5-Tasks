#include <iostream>
using namespace std;
#include <string>


class Node{
    public:
    string jobs;
    Node *next;

    Node(){
        next = nullptr;
    }

    Node(string jobs){
        this->jobs = jobs;
    }
};

class Queue{
    public:
    Node* Front;
    Node* Back;

    Queue(){
        Front = nullptr;
        Back = nullptr;
    }
    
    void equeue(string data){
        Node *newnode = new Node(data);
          if(Front == nullptr){
            Front = newnode;
            Back = newnode;
            return;
          }

          Back->next = newnode;
          Back = newnode;

    }

    string deque(){
        Node *tobedeleted = Front;
        string temp;
        if(Front == nullptr){
            cout<<"Queue Is empty"<<endl;
            return "";
          }


        if(Front->next == nullptr){
            temp = Front->jobs;
            Front = nullptr;
            Back = nullptr;
            delete tobedeleted;
            return temp;
        }

          temp = Front->jobs;
          Front = Front->next;
          delete tobedeleted;
          return temp;
    }


    bool checkempty(){
        if(Front == nullptr){
            return true;
    }

        else{
            return false;
        }
  }

    int checksize(){
        Node *temp = Front;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }

        return count;
    }    
};

class Stack{
    public:
    Node* Top;

    Stack(){
        Top = nullptr;
    }

    string pop(){
        Node *nodetobedeleted = Top;
        string temp;
        if(Top == nullptr){
            cout<<"Stack Is Empty"<<endl;
            return "";
        }

        if(Top->next == nullptr){
            temp = Top->jobs;
            Top = nullptr;
            delete nodetobedeleted;
            return temp;          
        }

        temp = Top->jobs;
        Top = Top->next;
        delete nodetobedeleted;
        return temp;
    }

    bool Empty(){
        if(Top == nullptr){
            return true;
        }

        else{
            return false;
        }

    }

    void push(string k){
        Node * newnode = new Node(k);

        if(Top == nullptr){
            Top = newnode;
            return;
        }

        newnode->next = Top;
        Top = newnode;
    }

    string peek(){
        return Top->jobs;
    }
};                  ///  front --> k1 k2 k3 k4 k5 k6 k7 // nothing 
                    ///  front --> k3 k2 k1    // k4 k5 k6 k7
                    ///            k4 k5 k6 k7 k3 k2 k1     
                    ///            K3 K2 K1 K4 K5 K6 K7


    void reverseFirstK(Queue &q, int k){
        int size = q.checksize();
    
        if(q.checkempty() || size < k ){
            cout<<"Queue is Empty"<<endl;    
            return;
        }

        if(k<=0){
            cout<<"Invalide value Of K"<<endl;
            return;
        }

        Stack qstack;

        for(int i=0; i<k; i++){
            string data  = q.deque();
            qstack.push(data);
        }

        while(!qstack.Empty()){
            q.equeue(qstack.pop());
        }

        for(int i =0 ; i< size-k; i++){
            q.equeue(q.deque());
        }
        }

int main() {
    Queue q;
    
    
    q.equeue("J1");
    q.equeue("J2");
    q.equeue("J3");
    q.equeue("J4");
    q.equeue("J5");
    q.equeue("J6");
    q.equeue("J7");

    cout << "Original Queue: J1 J2 J3 J4 J5 J6 J7" << endl;

    
    reverseFirstK(q, 3);

   
    cout << "Reversed Queue: ";
    Node* temp = q.Front;
    while (temp != nullptr) {
        cout << temp->jobs << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

