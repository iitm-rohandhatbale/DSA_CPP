# Data Structures and Algorithms in _C++_

> Credit to : [Simple Snippets](https://www.youtube.com/channel/UCRIWTSgd7hGtZhx4RYoASEg) Youtube channel. 


## Abstract Data Type
- ADTs are entities that are definitions of data and operations but do not have implementation details. i.e. ADTs can be a mathematical model or logic but do not have a fixed implementation.  
- The implementation might differ based on what programming language is being used to define it.  
- e.g., a particular data structure in C can be defined using the concept of _structures_ but the same data structure in C++ or JAVA can be defined by _OOPs_ . 

![ADTs example snippet](snippets/ADTs_example_snippet.png)


## Stack Data Structure

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

[Stacks Code](DSAbySimpleSnippets/DSA_stacks.cpp)


## Queue Data Structure

- Queue is a linear data structure which operates in **FIFO(First In First Out)** or **LILO (Last In Last Out) pattern**.
- It exactly behaves as the real world queue in which whoever enters first will be out first. 
- Similar to **Stack**, **Queue** is also a very simple abstract data type with a bounded capacity.
- Queues can be used in CPU Scheduling, Disk Scheduling, handling of errors in real time.
- In real life, call center phone systems will use queues to hold call in order. 

#### Working of a Queue
- Elements are always added at _rear end_, which is called **Enqueue**.
- And, elements are removed from _front/head end_, which is called **Dequeue**.

![Working of Queue snippet](snippets/queue_working_snippet.png)

#### Standard Queue Operations

1. ```enqueue()```: Element is added from the _rear/back end_. 
2. ```dequeue()```: Element is removed from _fron/head end_.
3. ```isEmpty()```: Check is queue is empty.
4. ```isFull()```: Check if queue is full.
5. ```count()```: count of total items on the queue. 

#### Example Code

[Queue Code](DSAbySimpleSnippets/DSA_queue.cpp)

## Circular Queue Data Structure
- This is very similar to Que data structure with minor changes to address the major disadvantage of Queue data structure. 
- So, in Queue DS, when dequeue operation is performed, the element that is dequeued is replaced by 0 in the queue. In that case even after removing the element, that vacant memory block of array (occupied by 0) becomes useless untill all the elements of the queue is dequeued.
- To overcome this disadvantage, **Circular Queue Data Structure** is used. Once the element is dequeued from the head and queue is full otherwise, then the next enqueued number is stored in place of dequeued numeber but at the same time head _rear/back_ is shifted one place forward so that the enqued element becomes last. 

![Circular Queue snippet](snippets/circular_queue_snippet.png)

#### Standard Queue Operations

1. ```enqueue()```: Element is added from the _rear/back end_. 
2. ```dequeue()```: Element is removed from _fron/head end_.
3. ```isEmpty()```: Check is queue is empty.
4. ```isFull()```: Check if queue is full.
5. ```count()```: count of total items on the queue. 

#### Example Code

[Circular Queue Code](DSAbySimpleSnippets/DSA_circular_queue.cpp)