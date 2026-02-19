#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

// ? stack using STL
// int main() {
//     stack<int> s;

//     // Push elements onto the stack
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     // Display the top element
//     cout << "Top element: " << s.top() << endl; // Output: 30

//     // Pop an element from the stack
//     s.pop();
//     cout << "Top element after pop: " << s.top() << endl; // Output: 20

//     // Check if the stack is empty
//     if (!s.empty()) {
//         cout << "Stack is not empty." << endl;
//     }

//     // Display the size of the stack
//     cout << "Stack size: " << s.size() << endl; // Output: 2

//     return 0;
// }

// ? stack using array
// class Stack {
//     public:
//         int *arr;
//         int top;  
//         int size;
    
//     Stack(int size) {
//         this->size = size;
//         arr = new int[size]; // ! dynamic memory allocation for array
//         top = -1;
//     }

//     void push(int data) {
//         if (top == size -1) {
//             cout << "Stack Overflow" << endl;
//             return;
//         }
//         else{
//             top++;
//             arr[top] = data;
//         }
//         return;
//     }
    
//     void pop(){
//         if(top < 0) {
//             cout << "Stack Underflow" << endl;
//             return;
//         }
//         else{
//             top--;
//         }
//         return;
//     }

//     int peek(){
//         if(top < 0){
//             cout << "No top element" << endl;
//             return -1;
//         }
//         else{
//             return arr[top];
//         }
//     }

//     bool isEmpty(){
//         if(top < 0 ){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };

// int main() {
//     Stack s1(5);
    


//     s1.push(5);
//     s1.push(4);
//     s1.push(3);
//     s1.push(2);
//     s1.push(1);
//     s1.push(0); // Stack Overflow
//     cout << "Top element is: " << s1.peek() << endl; // 1
//     s1.pop();
//     cout << "Top element is: " << s1.peek() << endl; // 2
//     s1.pop();
//     s1.pop();

//     if(s1.isEmpty()){
//         cout << "Stack is empty" << endl;
//     }
//     else{
//         cout << "Stack is not empty" << endl;
//     }

//     cout << "Top element is: " << s1.peek() << endl; // 4
//     s1.pop();
//     s1.pop();
//     s1.pop(); // Stack Underflow

//     if(s1.isEmpty()){
//         cout << "Stack is empty" << endl;
//     }
//     else{
//         cout << "Stack is not empty" << endl;
//     }
//     return 0;
// }

// ? stack using linked list
class node {
    public:
        int data;
        node *next;

        node(int data) {
            this -> data = data;
            this -> next = nullptr;
        }

        ~node() {
            int value = this -> data;
            if(this -> next != nullptr) {   // ! recursive deletion of next nodes
                delete next;                // ! free memory of next node
                this -> next = nullptr;     // ! break the link to avoid recursive deletion
            }
            cout << "Memory is free for node with data : " << value << endl;
        }
};

void push (node* &head , int data) {    // ! push at head / starting of the linked list 
    node* temp = new node (data);
    temp -> next = head;    
    head = temp;            
}

void pop (node* &head) {
    if (head == nullptr){
        cout << "Stack Underflow" << endl;
        return;
    }
    node* temp = head;
    head = head -> next;    // ! update head to the next node its actually nullptr since its the last node in the stack but we still do it to keep the code consistent and clean
    temp -> next = nullptr; // ! break the link to avoid recursive deletion
    delete temp;
    temp = nullptr; // ! remove dangling pointer
}

int top (node* &head) {
    if (head == nullptr){
        cout << "No top element" << endl;
        return -1;
    } 
    return head -> data;
}

bool isEmpty (node* &head) {
    return head == nullptr;
}

int main() {
    node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(head, value);
                break;
            case 2:
                pop(head);
                break;
            case 3:
                cout << "Top element: " << top(head) << endl;
                break;
            case 4:
                if (isEmpty(head)) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                // Free all nodes before exiting
                while (head != nullptr) {
                    node *temp = head;
                    head = head->next;
                    delete temp;
                }
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

