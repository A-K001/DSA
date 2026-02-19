#include <iostream>
using namespace std;

// ? Linked List representation
// [ head ] ---> [ Node ]
//                 ├─ data = 10
//                 └─ next ---> [ Node ]
//                                ├─ data = 20
//                                └─ next ---> nullptr

// ? Singly Linked List
// class node {
//     public:
//         int data;
//         node *next;  // ! node type pointer to point to the next node

//         // ! Constructor
//         node(int val) {
//             data = val;
//             next = nullptr;
//         }

//         // ! Destructor
//         ~node (){
//             cout << "Memory is free for node with data : " << this -> data << endl;
//         }
// };
// void insertAtHead (node *&head , int d){
//     // ! Create a new node
//     node *temp = new node(d);
//     temp -> next = head;
//     head = temp;
// }

// void insertAtTail(node* &tail ,int d){
//     // ! Creating a new node
//     node *temp = new node(d);
//     tail -> next = temp;
//     tail = temp; 
// }

// void insertAtPosition (node *&head ,node *&tail , int d , int position){
//     // ! if the linked list is empty
//     if (position <= 0) {
//         cout << "Invalid position!" << endl;
//         return;
//     }

//     // ! inserting at start
//     if (position == 1){
//         insertAtHead(head , d);
//         return;
//     }
    
//     node *temp = head;
//     int cnt = 1;

//     while (cnt < position - 1 && temp != nullptr){
//         cnt++; 
//         temp = temp -> next;
//     }

//     // ! if position is greater than length of linked list
//     if (temp == nullptr) {
//         cout << "Position is greater than the length of the linked list!" << endl;
//         return;
//     }

//     // ! inserting at end
//     if(temp -> next == nullptr){
//         insertAtTail(tail , d);
//         return;
//     }
    
//     node *pos = new node (d);
//     pos -> next = temp -> next;
//     temp -> next = pos;
// }

// void deleteNode(node *&head , node *&tail , int position){
    
//     if (head == nullptr || position <= 0) {
//         cout << "Invalid position or empty list!" << endl;
//         return;
//     }

//     // ! Deleting from start
//     if (position == 1 ){
//         node *temp = head;
//         head = head -> next;
//         delete temp;
//         temp = nullptr; // ! remove dangling pointer
//     }

//     // ! Deleting and middle or last node
//     else {
//         node *curr = head;
//         node *prev = nullptr;
//         int cnt = 1;
//         while (cnt < position && curr != nullptr){
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         // ! if position is greater than length of linked list
//         if (curr == nullptr) {
//             cout << "Position is greater than the length of the linked list!" << endl;
//             return;
//         }

//         // ! so that the position of tail is correct after deletion
//         if (curr -> next == nullptr){
//             tail = prev;
//         }
//         prev -> next = curr -> next;
//         delete curr;
//         curr = nullptr; // ! remove dangling pointer
//     }
// }

// int getLength(node* head) {
//     int len = 0;
//     while (head != nullptr) {
//         len++;
//         head = head->next;
//     }
//     return len;
// }

// void print (node *&head){
//     node *temp = head;
//     while ( temp != nullptr){
//         cout << temp -> data << " -> ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// int main(){
//     int value , position;
//     node *head = nullptr;
//     node *tail = nullptr;
//     cout << "1. Insert at head" << endl;
//     cout << "2. Insert at tail" << endl;
//     cout << "3. Insert at position" << endl;
//     cout << "4. Delete node" << endl;
//     cout << "5. Print linked list and its length" << endl;
//     cout << "6. Print head and tail" << endl;
//     cout << "7. Exit" << endl;
//     while(true){
//         cout << "Enter your choice (1/2/3/4/5/6/7) : ";
//         int choice;
//         cin >> choice;

//         switch(choice){
//             case 1:
//                 cout << "Enter value to insert at head: ";
//                 cin >> value;
//                 insertAtHead(head , value);
//                 if (tail == nullptr) {
//                     // ! First node
//                     tail = head;
//                 }
//                 break;
//             case 2:
//                 cout << "Enter value to insert at tail: ";
//                 cin >> value;
//                     if (head == nullptr) {
//                         // ! First node
//                         head = new node(value);
//                         tail = head;
//                     } 
//                     else {
//                         insertAtTail(tail , value);
//                     }
//                     break;
//             case 3:
//                 cout << "Enter value and position to insert: ";
//                 cin >> value >> position;    
//                 insertAtPosition(head , tail , value , position);
//                 break;
//             case 4:
//                 cout << "Enter position to delete: ";
//                 cin >> position;
//                 deleteNode(head , tail , position);
//                 break;
//             case 5:
//                 cout << "Linked List: ";
//                 print(head);
//                 cout << "Length of Linked List: " << getLength(head) << endl;
//                 break;
//             case 6:
//                 if (head) cout << "head : " << head -> data << endl;
//                 else cout << "head : NULL" << endl;
//                 if (tail) cout << "tail : " << tail -> data << endl;
//                 else cout << "tail : NULL" << endl;
//                 break;
//             case 7:
//                 cout << "Exiting..." << endl;
//                 // Free memory
//                 while (head != nullptr) {
//                     node *temp = head;
//                     head = head->next;
//                     delete temp;
//                 }
//                 exit(0);
//             default:
//                 cout << "Invalid choice!" << endl;
//         }
//     }        
// }


// ? Doubly Linked List
// class node {
//     public:
//         int data;
//         node *next;  // ! node type pointer to point to the next node
//         node *prev;  // ! node type pointer to point to the previous node

//         // ! Constructor
//         node(int val) {
//             data = val;
//             next = nullptr;
//             prev = nullptr;
//         }

//         // ! Destructor
//         ~node (){
//             cout << "Memory is free for node with data : " << this -> data << endl;
//         }
// };

// void insertAtHead ( node *&head , int d){
//     // ! Create a new node
//     node *temp = new node(d);
//     temp -> next = head;
//     if (head != nullptr) {
//         head -> prev = temp;
//     }
//     head = temp; 
// }

// void insertAtTail(node *&tail , node *&head , int d){
//     if (tail == nullptr){
//         // ! First node
//         head = new node(d);
//         tail = head;
//         return; 
//     }
//     // ! Creating a new node
//     node *temp = new node(d);
//     tail -> next = temp;
//     temp -> prev = tail;
//     tail = temp;
// }

// void insertAtPosition (node *&head , node *&tail , int d , int position){
//     if (position <= 0 ){
//         cout << "Invalid position!" << endl;
//         return;
//     }
//     if (position == 1){
//         insertAtHead(head , d);
//         return;
//     }

//     node *temp = head;
//     int cnt = 1;
    
//     while (cnt < position - 1 && temp != nullptr){
//         cnt++;
//         temp = temp -> next;
//     }

//     // ! if position is greater than length of linked list
//     if (temp == nullptr) {
//         cout << "Position is greater than the length of the linked list!" << endl;
//         return;
//     }

//     // ! inserting at end
//     if(temp -> next == nullptr){
//         insertAtTail(tail , head , d);
//         return;
//     }

//     node * pos = new node (d);
//     temp -> next -> prev = pos;
//     pos -> next = temp->next;
//     pos -> prev = temp;
//     temp -> next = pos;  
// }

// void deleteNode(node *&head , node *&tail , int position) {
//     if (head == nullptr || position <= 0) {
//         cout << "Invalid position or empty list!" << endl;
//         return;
//     }

//     // ! Deleting from start
//     if (position == 1 ){
//         node *temp = head;
//         head = head -> next;
//         // ! SAFELY CHECK BEFORE ACCESSING head->prev
//         if (head != nullptr) {
//             head -> prev = nullptr;
//         } 
//         else {
//             // ! If head is nullptr, list is empty now — also reset tail
//             tail = nullptr;
//         }
//         delete temp;
//         temp = nullptr; // ! remove dangling pointer         
//     }

//     // ! Deleting and middle or last node
//     else {
//         node *curr = head;
//         node *previous = nullptr;
//         int cnt = 1;
//         while (cnt < position && curr != nullptr){
//             previous = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         // ! if position is greater than length of linked list
//         if (curr == nullptr) {
//             cout << "Position is greater than the length of the linked list!" << endl;
//             return;
//         }

//         // ! so that the position of tail is correct after deletion
//         if (curr -> next == nullptr){
//             tail = previous;
//         }
//         previous -> next = curr -> next;
//         if (curr -> next != nullptr){
//             curr -> next -> prev = previous;
//         }
//         delete curr;
//         curr = nullptr; // ! remove dangling pointer        
//     }
// }

// int getLength(node* head){
//     int len = 0;
//     while (head != nullptr) {
//         len++;
//         head = head->next;
//     }
//     return len;
// }

// void printBackward(node *&tail){
//     node *temp = tail;
//     while ( temp != nullptr){
//         cout << temp -> data << " <-> ";
//         temp = temp -> prev;
//     }
//     cout << endl;
// }

// void printForward (node *&head){
//     node *temp = head;
//     while ( temp != nullptr){
//         cout << temp -> data << " <-> ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// int main () {
//     int value , position;
//     node *head = nullptr;
//     node *tail = nullptr;

//     cout << "1. Insert at head" << endl;
//     cout << "2. Insert at tail" << endl;
//     cout << "3. Insert at position" << endl;
//     cout << "4. Delete node" << endl;
//     cout << "5. Print linked list and its length" << endl;
//     cout << "6. Print linked list backward and its length" << endl;
//     cout << "7. Print head and tail" << endl;
//     cout << "8. Exit" << endl;
    
//     while(true){
//         cout << "Enter your choice (1/2/3/4/5/6/7/8) : ";
//         int choice;
//         cin >> choice;

//         switch(choice){
//             case 1:
//                 cout << "Enter value to insert at head: ";
//                 cin >> value;
//                 insertAtHead(head , value);
//                 if (tail == nullptr) {
//                     // ! First node
//                     tail = head;
//                 }
//                 break;
//             case 2:
//                 cout << "Enter value to insert at tail: ";
//                 cin >> value;
//                 insertAtTail(tail , head , value);
//                 break;
//             case 3:
//                 cout << "Enter value and position to insert: ";
//                 cin >> value >> position;    
//                 insertAtPosition(head , tail , value , position);
//                 break;
//             case 4:
//                 cout << "Enter position to delete: ";
//                 cin >> position;
//                 deleteNode(head , tail , position);
//                 break;
//             case 5:
//                 cout << "Linked List forward: ";
//                 printForward(head);
//                 cout << "Length of Linked List: " << getLength(head) << endl;
//                 break;
//             case 6:
//                 cout << "Linked List backward: ";
//                 printBackward(tail);
//                 cout << "Length of Linked List: " << getLength(head) << endl;
//                 break;
//             case 7:
//                 if (head) cout << "head : " << head -> data << endl;
//                 else cout << "head : NULL" << endl;
//                 if (tail) cout << "tail : " << tail -> data << endl;
//                 else cout << "tail : NULL" << endl;
//                 break;
//             case 8:
//                 cout << "Exiting..." << endl;
//                 // Free memory
//                 while (head != nullptr) {
//                     node *temp = head;
//                     head = head->next;
//                     delete temp;
//                 }
//                 exit(0);
//             default:
//                 cout << "Invalid choice!" << endl;
//         }
//     }        
// }


// ? Circular Linked List
class Node {
    public:
        int data;
        Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   
    deleteNode(tail, 5);
    print(tail);

    return 0;
}