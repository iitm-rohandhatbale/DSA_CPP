#include <iostream>

using namespace std;

class Stacks
{
    private:
        int arr[5];
        int top;
    
    public:
        Stacks(){
            top = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i] = 0; 
            }
        }

        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull()
        {
            if (top == 5)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void push(int val)
        {
            if (isFull())
            {
                cout << "Stack overflow !" << endl;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }

        int pop()
        {
            if (isEmpty())
            {
                cout << "Stack underflow !" << endl;
                return 0;
            }
            else
            {
                int popvalue = arr[top];
                arr[top] = 0;
                top--;
                return popvalue;
            }
        }

        int count()
        {
            return top+1;
        }

        int peek(int pos)
        {
            if ((pos >= 5) || (pos < 0))
            {
                cout << "Invalid position value." << endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void change(int pos, int val)
        {
            if ((pos >= 5) || (pos < 0))
            {
                cout << "Invalid position value." << endl;
            }
            else
            {
                arr[pos] = val;
            }
        }

        void display()
        {
            for (int i = 4; i >= 0; i--)
            {
                cout << arr[i] << " " ;
            }
            cout << endl;
        }
};

int main()
{
    int option, position, value;
    Stacks s;
    do
    {
        cout << "Enter an option number you want to perform. Enter 0 to Exit the program!" << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. clear screen" << endl;

        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            cout << "Enter a number to add(push) to stack ";
            cin >> value;
            s.push(value);
            break;
        
        case 2:
            cout << "popped value is "  << s.pop() << endl;
            break;
        
        case 3:
            if (s.isEmpty())
            {
                cout << "Stack is Empty !!" << endl;
            }
            else
            {
                cout << "Stack is not Empty !" << endl;
            }
            break;
        
        case 4:
            if (s.isFull())
            {
                cout << "Stack is full !" << endl;
            }
            else
            {
                cout << "Stack is not full !" << endl;
            }
            break;
        
        case 5:
            cout << "peek option is called ! Enter the position [0, 4] " ;
            cin >> position;
            cout << "Integer at a position " << position << " is " << s.peek(position) << endl;
            break;
        
        case 6:
            cout << "Total number of elements in the stak is " << s.count() << endl;
            break;
        
        case 7:
            cout << "change operation is called. Enter position [0, 4] and value ";
            cin >> position >> value;
            cout << "Changed !!!" << endl;
            break;
        
        case 8:
            cout << "Display operation is selected. " << endl;
            s.display();
            break;
        
        case 9:
            system("clear");
            break;
            
        
        default:
            break;
        }
    } while (option !=0);
    
    return 0;
}
