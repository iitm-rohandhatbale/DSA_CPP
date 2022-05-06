# Data Structures and Algorithms in _C++_

> Credit to : [Simple Snippets](https://www.youtube.com/channel/UCRIWTSgd7hGtZhx4RYoASEg) Youtube channel. 


## Abstract Data Type
- ADTs are entities that are definitions of data and operations but do not have implementation details. i.e. ADTs can be a mathematical model or logic but do not have a fixed implementation.  
- The implementation might differ based on what programming language is being used to define it.  
- e.g., a particular data structure in C can be defined using the concept of _structures_ but the same data structure in C++ or JAVA can be defined by _OOPs_ . 

![ADTs example snippet](snippets/ADTs_example_snippet.png)


# Stack Data Structure

- Stack is a linear data structure which operates in a **LIFO(Last IN First Out)** or **FILO(First In Last Out)** pattern. 
- It is named as stack as it behaves like real world stack of objects.
- Very simple and linear data structure that allows adding or removing elements in a particular order (LIFO or FILO)
- In stack, items/elements are added and removed from the top of the stack. (PUSH and POP operation respectively).


![Standard Stack Operations](snippets/standard_stack_operation.png)

#### Application of stack data structure.
1. balacing of symbols while writing a program in any IDE.
2. undo-redo features.
3. browing forward and backward pages. 
4. used in algorithms like Tower of hanoi or tree traversals etc. 

#### Example Code:

```cpp

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


```










