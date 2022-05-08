#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        // '*n' is pointer to store the address of Node 'n'
        // head and n both are pointerof class 'Node'
        head = n;
    }
    /* This method checks whether node is present for given key 'k' and returns the Node is it is present. */

    /* Start by declaring Node pointer 'ptr' = head andn create one Node pointer temp which will store the 'ptr'. Now, while 'ptr' is not NULL; traverse through the list till ptr->key = k is found. Once found assign 'ptr' to Node pointer 'temp', else reassign ptr to current pointer ptr->next
     */
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // Append Node at the end of Linked List
    void appendNode(Node* n){
        // check whether node with key 'k' exist or not
        if (nodeExist(n->key)!=NULL){
            cout << "Node already exist with a key " << n->key << "." << endl;
        }
        else {
            // if no node in the list (i.e., head == NULL), then append new npde 'n' to head.
            if (head == NULL){
                head = n;
                cout << "Node appended !" << endl;
            }
            // else, traverse through the list till find end (ptr->next == NULL), and append new node after last node
            else{
                Node *ptr = head;
                while (ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended !" <<endl;
            } 
        }
    }
    // prepend node -> attach node at the start
    void prependNode(Node* n){

        // check whether node with key 'k' exist or not
        if (nodeExist((n->key)!=NULL)){
            cout << "Node already exist with a key " << n->key << "." << endl;
        }
        // If not exist, assign address of node 'n' in with head and change head pointer to address of node 'n'.
        else{
            n->next = head;
            head = n;
            cout << "Node Prepended !" << endl;
        }
    } 
    // Insert a node after a particular node in the list.
    void insertNode(int k, Node* n){
        // get the pointer of concerned node
        Node* ptr = nodeExist(k);

        // check if node exist or not
        if (ptr == NULL){
            cout << "No node with key " << k << " is present." << endl;
        }
        else{
            // check whether node to be inserted already exist or not
            if (nodeExist((n->key)!=NULL)){
                cout << "Node with key " << n->key << " already exist." << endl;
            }
            else{
                // assign 'next' of new node with 'next' of node with key 'k'
                n->next = ptr->next;
                // Now, change 'next' of node with key 'k' to address of new node.
                ptr->next = n;
                cout << "Node Inserted." << endl;
            }
        }
    }
    // Delete node by key
    void deleteNode(int k){
        // get the pointer of concerned node
        Node* ptr = nodeExist(k);

        // check if node exist or not
        if (ptr==NULL){
            cout << "No node with key " << k << " is present." << endl;
        }
        // if exist
        else{
            // instantiate a node and assign it a head value so that we can traverse the list from head
            Node* prvnode = head;
            
            // if node at k is head node
            if (ptr == head){
                // change head with head pointer.
                head = prvnode->next;
                cout << "head Unlinked !!!" << endl;
            }

            // delete any node other than head
            else{
                //traverse through the list till find the pointer of concerned node
                while (prvnode->next != ptr){
                    prvnode = prvnode->next;
                }
                // change the 'next' of previous node with 'nect' of concerned pointer.
                prvnode->next = ptr->next;
                cout << "Node with key " << k << " is unlinked !" << endl;
            }
        }
    }
    // Update node by key
    void updateNodeByKey(int k, int d){
        // get the pointer of concerned node
        Node* ptr = nodeExist(k);

        // Check whether node exist or not
        if (ptr==NULL){
            cout << "Node with key " << k << " does not exist. " << endl;
        }
        else{
            // change the data of concerned pointer with updated data
            ptr->data = d;
            cout << "Node updated successfully. " << endl;
        }
    }

    //Display fuction

    void display(){
        Node* ptr = head;
        while((ptr->next)!=NULL){
            cout << "(" << ptr->key << ", " << ptr->data << ", " << ptr->next << ") -->";
            ptr = ptr->next; 
        }
        cout << "(" << ptr->key << ", " << ptr->data << ", " << ptr->next << ")";
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNode()" << endl;
        cout << "4. deleteNode()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            // cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.insertNode(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.deleteNode(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);

            break;
        case 6:
            s.display();

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
