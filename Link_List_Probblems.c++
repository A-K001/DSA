#include <iostream>
using namespace std;    

// ? reverse linked list
// ? find middle of linked list
class node {
    public:
        int data;
        node *next;  // ! node type pointer to point to the next node

        // ! Constructor
        node(int val) {
            data = val;
            next = nullptr;
        }

        // ! Destructor
        ~node (){
            cout << "Memory is free for node with data : " << this -> data << endl;
        }
};

void insertAtHead (node *&head , int d){
    // ! Create a new node
    node *temp = new node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(node* &tail ,int d){
    // ! Creating a new node
    node *temp = new node(d);
    tail -> next = temp;
    tail = temp; 
}

void insertAtPosition (node *&head ,node *&tail , int d , int position){
    // ! if the linked list is empty
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // ! inserting at start
    if (position == 1){
        insertAtHead(head , d);
        return;
    }
    
    node *temp = head;
    int cnt = 1;
    
    while (cnt < position - 1 && temp != nullptr){
        cnt++; 
        temp = temp -> next;
    }
    
    // ! if position is greater than length of linked list
    if (temp == nullptr) {
        cout << "Position is greater than the length of the linked list!" << endl;
        return;
    }
    
    // ! inserting at end
    if(temp -> next == nullptr){
        insertAtTail(tail , d);
        return;
    }
    
    node *pos = new node (d);
    pos -> next = temp -> next;
    temp -> next = pos;
}

void deleteNode(node *&head , node *&tail , int position){
    
    if (head == nullptr || position <= 0) {
        cout << "Invalid position or empty list!" << endl;
        return;
    }

    // ! Deleting from start
    if (position == 1 ){
        if (head == tail) {
            // ! Only one node and for updation of tail
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        node *temp = head;
        head = head -> next;
        delete temp;
        temp = nullptr; // ! remove dangling pointer
    }
    
    // ! Deleting and middle or last node
    else {
        node *curr = head;
        node *prev = nullptr;
        int cnt = 1;
        while (cnt < position && curr != nullptr){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        
        // ! if position is greater than length of linked list
        if (curr == nullptr) {
            cout << "Position is greater than the length of the linked list!" << endl;
            return;
        }
        
        // ! so that the position of tail is correct after deletion
        if (curr -> next == nullptr){
            tail = prev;
        }
        prev -> next = curr -> next;
        delete curr;
        curr = nullptr; // ! remove dangling pointer
    }
}

int getLength(node* head) {
    int len = 0;
    while (head != nullptr) {
        len++;
        head = head->next;
    }
    return len;
}

void print (node *&head){
    node *temp = head;
    while ( temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

// ! Reversing the linked list
node* reverseLinkList(node *&head , node *&tail){
    if (head == nullptr || head -> next == nullptr){
        cout << "List is empty or has only one node!" << endl;
        return head; // ! empty list or single node
    }  

    tail = head; // ! update tail to the current head
    node *prev = nullptr;
    node *curr = head;
    node *forward = nullptr;
    while (curr != nullptr){
        forward = curr -> next; // ! store the next node
        curr -> next = prev; // ! reverse the link
        prev = curr;
        curr = forward; // ! move to the next node 
    }
    return prev; // ! new head
}

// ! Finding the middle of the linked list
node* middleOfLinkList(node *&head){
    if (head == nullptr){
        cout << "List is empty" << endl;
        return head; // ! empty list o
    }
    if (head -> next == nullptr){
        return head; // ! single node
    }

    node *slow = head;
    node *fast = head -> next;
    while (fast != nullptr){
        slow = slow -> next;
        fast = fast -> next;
        if (fast != nullptr){
            fast = fast -> next;
        }
    }
    return slow; // ! middle node
}

int main(){
    int value , position;
    node *head = nullptr;
    node *tail = nullptr;
    cout << "1. Insert at head" << endl;
    cout << "2. Insert at tail" << endl;
    cout << "3. Insert at position" << endl;
    cout << "4. Delete node" << endl;
    cout << "5. Print linked list and its length" << endl;
    cout << "6. Reverse and print linked list" << endl;
    cout << "7. Print head, tail and middle of the linked list" << endl;
    cout << "8. Exit" << endl;

    while(true){
        cout << "Enter your choice (1/2/3/4/5/6/7/8) : ";
        int choice;
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(head , value);
                if (tail == nullptr) {
                    // ! First node
                    tail = head;
                }
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                    if (head == nullptr) {
                        // ! First node
                        head = new node(value);
                        tail = head;
                    } 
                    else {
                        insertAtTail(tail , value);
                    }
                    break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> value >> position;    
                insertAtPosition(head , tail , value , position);
                break;
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteNode(head , tail , position);
                break;
            case 5:
                cout << "Linked List: ";
                print(head);
                cout << "Length of Linked List: " << getLength(head) << endl;
                break;
            case 6:
                cout << "Reversed Linked List: ";
                head = reverseLinkList(head , tail);
                print(head);
                cout << "Length of Linked List: " << getLength(head) << endl;
                break;
            case 7:
                if (head) cout << "head : " << head -> data << endl;
                else cout << "head : NULL" << endl;
                if (tail) cout << "tail : " << tail -> data << endl;
                else cout << "tail : NULL" << endl;
                if (node *m = middleOfLinkList(head)) cout << "Middle of Linked List: " << m -> data << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                // Free memory
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





