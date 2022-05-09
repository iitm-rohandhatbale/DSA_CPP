#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *previous;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        previous = NULL;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    Node *nodeExist(int k)
    {
        Node* ptr = NULL;
        Node* temp = head;
        if (temp == NULL)
        {
            cout << "No node present in the list." << endl;
        }
        else{
            while (temp != NULL){
                if (temp->key == k){
                    ptr = temp;
                }
                temp = temp->next;
            }
        }
        return ptr;
    }

    // Append Node at the end of the list.
    void appendNode(Node *n)
    {
        // Check whether node with same key present or not
        if (nodeExist(n->key)!=NULL)
        {
            // if present
            cout << "Node with key " << n->key << " already present." << endl;
        }
        else
        {
            if (head == NULL){
                // if no nodes present then append new node at head. Change head pointer to new node.
                head = n;
                cout << "Node appended at head!" << endl;
            }
            else{
                // if not present traverse at the end of the list starting from the head and append the node.
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                // Once found the end node change 'next' of the last found node with address of new node
                //  And 'previous' of new node with address of last found node.

                ptr->next = n;
                n->previous = ptr;
                cout << "Node appended at end!" << endl;
            }
        }
    }
    
    // prepend node at the head
    void prependNode(Node* n){
        // Check whether node with same key present or not
        if (nodeExist(n->key) != NULL){
            // if present
            cout << "Node with key " << n->key << " already present." << endl;
        }
        else{
            if (head == NULL){
                // if no nodes present then append new node at head. Change head pointer to new node.
                head = n;
                cout << "Node appended at head!" << endl;
            }
            else{
                // change 'previous' of head to new node; 
                // change 'next' of new node to head;
                // change head to new pointer;
                head->previous = n;
                n->next = head;
                head = n;
                cout << "Node prepended. " << endl;
            }
        }
    }
    
    //insert node after particular key in thbe list
    void insertNode(int k, Node* n){
        // Check whether node with same key present or not
        if (nodeExist(n->key) != NULL){
            // if present
            cout << "Node with key " << n->key << " already present." << endl;
        }
        else{
            // check whether node with key 'k' present or not
            if (nodeExist(k)==NULL){
                cout << "Node with key " << k << " not present." << endl;
            }
            else{
                // traverse to the node with key 'k'
                Node* temp = NULL; // temperory node to store node with key k
                Node *nextptr = NULL; // temporary node to store node next to temp node.
                Node *ptr = nodeExist(k);
                
                nextptr = ptr->next;
                
                n->next = nextptr;
                n->previous = ptr;
                ptr->next = n;
                if (nextptr != NULL){
                    nextptr->previous = n;
                }
                cout << "Node inserted after node with key " << k << endl;
            }
        }
    }
    
    // Delete node by key
    void deleteNode(int k){
        Node* ptr = nodeExist(k);
        // Check whether node with same key present or not
        if (ptr == NULL){
            // if not present
            cout << "Node with key " << k << " not present." << endl;
        }
        else{
            Node* nextptr = NULL;
            Node* prvptr = NULL;
            // check for head node and only node
            if (head == ptr){
                // delete head node (head == NULL)
                head = NULL;
            }
            // check for head node which is not the only node.
            else if (ptr->previous == NULL){
                // update 'next' of the previous node and 'previous' of the next node
                // change head to next node.
                nextptr = ptr->next;
                nextptr->previous = NULL;
                head = nextptr;
                cout << "Node deleted !!!" << endl;
            }
            // check for last node
            else if (ptr->next == NULL){
                // update 'next' of the previous node with 'NULL'
                prvptr = ptr->previous;
                prvptr->next = NULL;
                cout << "Node deleted !!!" << endl;
            }
            // for all other nodes
            else{
                // update 'next' of the previous node and 'previous' of the next node
                prvptr  = ptr->previous;
                nextptr = ptr->next;
                prvptr->next = nextptr;
                nextptr->previous = prvptr;
                cout << "Node deleted !!!" << endl;
            }
        }
    }
    
    // Update node by key
    void updateNodeByKey(int k, int d){
        // get teh concerned node
        Node* ptr = nodeExist(k);
        
        // check if node is present or not
        if (ptr == NULL){
            // if not --> break
            cout << "No node with key " << k << " present." << endl;
        }
        else{
            // if present update the data
            ptr->data = d;
            cout << "data updated" << endl;
        }
    }

    // display list
    void display()
    {
        Node *ptr = head;
        if (ptr == NULL)
        {
            cout << "No node present !!!" << endl;
        }
        else{
            while (ptr->next != NULL)
            {
                cout << "(" << ptr->previous << ", " << ptr->key << ", " << ptr->data << ", " << ptr->next << ") <--> ";
                ptr = ptr->next;
            }
            cout << "(" << ptr->previous << ", " << ptr->key << ", " << ptr->data << ", " << ptr->next << ")" << endl;
        }
    }
};

int main_debug(){
    Node n1(1, 12);
    Node n2(2, 24);
    Node n3(3, 36);

    DoublyLinkedList d(&n1);
    d.display();

    d.deleteNode(1);
    d.display();

    return 0;
}

int main1()
{
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        // Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.appendNode(n1);
            // cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;

            obj.insertNode(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.deleteNode(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);

            break;
        case 6:
            obj.display();

            break;
        case 7:
            system("clear");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
