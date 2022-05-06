#include <iostream>

using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int arr[5];
    public:
        // Define constructor.
        Queue(){
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++){
                arr[i] = 0;
            }
        }
        bool isEmpty(){
            if ((front == -1) && (rear == -1)){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if (front == 4){
                return true;
            }
            else{
                return false;
            }
        }
        void enqueue(int val){
            if (isFull()){
                return;
            }
            else if (isEmpty()){
                rear = 0;
                front = 0;
                arr[rear] = val;
            }
            else{
                rear++;
                arr[rear] = val;
            }
        }
        int dequeue(){
            int x = 0;
            if (isEmpty()){
                return 0;
            }
            else if(front == rear){
                x = arr[front];
                arr[front] = 0;
                rear = -1;
                front = -1;
                return x;
            }
            else{
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }
        int count(){
            return (rear-front+1);
        }
        void display(){
            cout << "front" << " ";
            for (int i = 0; i < 5; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "rear";
            cout << endl;
        }
};

int main()
{
    int option, position, value;
    Queue q;
    do
    {
        cout << "Enter an option number you want to perform. Enter 0 to Exit the program!" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. clear screen" << endl;

        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            cout << "Enter a number to add to queue";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "dequeued value is " << q.dequeue() << endl;
            break;

        case 3:
            if (q.isEmpty()){
                cout << "Queue is Empty !!" << endl;
            }
            else{
                cout << "Queue is not Empty !" << endl;
            }
            break;

        case 4:
            if (q.isFull()){
                cout << "Queue is full !" << endl;
            }
            else{
                cout << "Queue is not full !" << endl;
            }
            break;

        case 5:
            cout << "Total number of elements in the Queue is " << q.count() << endl;
            break;

        case 6:
            cout << "Display operation is selected. " << endl;
            q.display();
            break;

        case 7:
            system("clear");
            break;

        default:
            break;
        }
    } while (option != 0);

    return 0;
}