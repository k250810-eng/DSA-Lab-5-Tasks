#include <iostream>
using namespace std;
#include <string>

class CQueue{
    public:
    int Front;
    int Rear;
    int capacity;
    int *data;

    CQueue(){
        Front = -1;
        Rear = -1;
        capacity = 6;
        data = new int[capacity];
        
    }


    void Equeue(int x){
        if(Front == -1 && Rear == -1){
            Front++;
            Rear++;
            data[Front] = x;  
            return;
        }

        if(!isfull()){
            Rear = (Rear+1)%6;
            data[Rear] = x;
        }

        else{
            cout<<"Queue Is Full Please Wait"<<endl;
        }
    }


    void Dequeue(){
        if(Front == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        if(Front == Rear){
            Front = -1;
            Rear =-1;
            return;
        }

        else{
            Front = (Front + 1)%6;
        }
    }

    void display(){
        if(Front == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        
        int i = Front;
        cout<<"Current Queue: ";
        while(i!=Rear){
            cout<<data[i]<<",";
            i = (i+1)%6;
        }
        cout<<data[Rear];
        cout<<endl;
    }
        

    bool isfull(){
        if((Rear+1)%6 == Front){
            return true;
        }

        else{
            return false;
        }
    }

};


int main() {
    CQueue gate;

    gate.Equeue(101);
    gate.Equeue(102);
    gate.Equeue(103);
    gate.Equeue(104);
    gate.Equeue(105);
    gate.Equeue(106);

    gate.Dequeue();
    gate.Dequeue();
    gate.Dequeue();

    gate.Equeue(107);
    gate.Equeue(108);
    gate.Equeue(109);

    gate.Dequeue();
    gate.Dequeue();

    gate.Equeue(110);

    gate.Dequeue();

    gate.Equeue(111);
    gate.Equeue(112);

    gate.display();

    cout << "Final Front Position: " << gate.Front << endl;
    cout << "Final Rear Position: " << gate.Rear << endl;

    return 0;
}