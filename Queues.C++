#include<iostream>
#include<queue>
using namespace std;

// ? Queue implementation using STL in C++
// int main (){ 
//     queue<int> q;
//     q.push(1);  //! Enqueue elements into the queue
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);

//     cout<<"Size of queue: "<<q.size()<<endl;
//     cout<<"Front element: "<<q.front()<<endl;
//     cout<<"Back element: "<<q.back()<<endl;
//     q.push(6);
//     q.pop();    //! Dequeue an element from the queue
//     cout<<"After popping one element:"<<endl;
//     cout<<"Size of queue: "<<q.size()<<endl;
//     cout<<"Front element: "<<q.front()<<endl;
//     cout<<"Back element: "<<q.back()<<endl;

//     if (q.empty()){
//         cout<<"Queue is empty"<<endl;
//     } else {
//         cout<<"Queue is not empty"<<endl;
//     }
// }


// ? Double ended queue (deque) implementation using STL in C++
// int main() {
//     deque<int> d;
//     d.push_back(1);  //! Insert elements at the back of the deque
//     d.push_back(2);
//     d.push_back(3);
//     d.push_front(0); //! Insert an element at the front of the deque

//     cout<<"Size of deque: "<<d.size()<<endl;
//     cout<<"Front element: "<<d.front()<<endl;
//     cout<<"Back element: "<<d.back()<<endl;

//     d.pop_back();   //! Remove an element from the back of the deque
//     cout<<"After popping one element from the back:"<<endl;
//     cout<<"Size of deque: "<<d.size()<<endl;
//     cout<<"Front element: "<<d.front()<<endl;
//     cout<<"Back element: "<<d.back()<<endl;

//     d.pop_front();  //! Remove an element from the front of the deque
//     cout<<"After popping one element from the front:"<<endl;
//     cout<<"Size of deque: "<<d.size()<<endl;
//     cout<<"Front element: "<<d.front()<<endl;
//     cout<<"Back element: "<<d.back()<<endl;

//     if (d.empty()){
//         cout<<"Deque is empty"<<endl;
//     } else {
//         cout<<"Deque is not empty"<<endl;
//     }
// }

// ? Simple Queue using array
// class Queue{
//     public:
//         int *arr;
//         int size;
//         int front;
//         int rear;

//     Queue (int size){
//         this -> size = size;
//         front = rear = 0;
//         arr = new int[size];
//     }

//     void push(int data) {
//         if (rear == size){
//             cout << "Queue Overflow" << endl;
//         }
//         else{
//             arr[rear] = data;
//             rear++;
//         }
//     }

//     void pop(){
//         if (front == rear){
//             cout << "Underflow" << endl;
//         }
//         else{
//             arr[front] = -1; 
//             front ++;
//             if (front == rear){     //! Reset the queue when it becomes empty to reuse the array space
//                 front = rear = 0;
//             }
//         }
//     }
//     int qfront(){
//         if (front == rear){
//             cout << "No front element" << endl;
//             return -1;
//         }
//         else{
//             return arr[front];
//         }
//     }

// };
// int main (){
//     Queue q(5);
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     cout << "Front element: " << q.qfront() << endl;
//     q.pop();
//     cout << "Front element after popping: " << q.qfront() << endl;
// }

// ? implementing Deque using array 
class Deque{
    public:
        int size;
        int *arr;
        int front;
        int rear;

        Deque (int size){
            this -> size = size;
            front = rear = -1;
            arr = new int[size];
        }

        void push_front(int data){
            if (isFull()){
                cout << "Deque is full" << endl;
                return;
            }
            else if (front == -1){
                front = rear = 0;
            }
            else if (front == 0 && rear != size - 1){
                front = size - 1;
            }
            else{
                front -- ;
            } 
            arr[front] = data;
        }

        void push_rear(int data){
            if (isFull()){
                cout << "Deque is full" << endl;
                return;
            }
            else if (rear == -1){
                front = rear = 0;
            }
            else if (rear == size -1 && front != 0 ){
                rear = 0;
            }
            else{
                rear ++ ;
            } 
            arr[rear] = data;
        }     

        void pop_front(){
            if (isEmpty()){         // if deque is empty
                cout << "Deque is empty" << endl;
                return;
            }
            cout << arr[front] << " At front is popped" << endl;
            arr[front] = -1;
            if (front == rear){     // deque has only one element
                front = rear = -1;
            }
            else if (front == size -1){    // front is at size - 1 then put it at 0 to maintain cyclic nature 
                front = 0;
            }
            else{
                front++ ;
            }   
        }

        void pop_rear(){
            if (isEmpty()){ // if deque is empty
                cout << "Deque is empty" << endl;
                return;
            }
            
            cout << arr[rear] << " At rear is popped" << endl;
            arr[rear] = -1;
            if (rear == front){ // deque has only one element
                rear = front = -1;
            }
            else if (rear == 0){ // rear is at 0 then put it at size - 1 to maintain cyclic nature 
                rear = size - 1;
            }
            else{
                rear --;
            }
        }

        int get_front(){
            if (isEmpty()){
                cout << "Deque has no element" << endl; 
                return -1;
            }
            else{
                return arr[front];
            }
        }

        int get_rear(){
            if(isEmpty()){
                cout << "Deque has no element" << endl;
                return -1;
            }
            else{
                return arr[rear];
            }
        }

        bool isEmpty(){
            if (front == -1 && rear == -1){
                return true;
            }
            return false;
        }

        bool isFull(){  // ! condition for circular queue full
            // if ((front == 0 && rear == size -1) || (front != 0 && rear == (front - 1) % (size - 1) )){  //! this was not optimal
            if ((rear + 1) % size == front){ //! % size is used to check wrap around condition in circular queue or any circular data structure
                return true;
            }
            else{
                return false;
            }
        }
    };

int main(){
    Deque d(5);
    d.push_rear(10);
    d.push_rear(20);
    d.push_rear(30);
    d.push_front(9);
    cout << "Front element: " << d.get_front() << endl;
    cout << "Rear element: " << d.get_rear() << endl;
    d.pop_front();
    cout << "Front element after popping from front: " << d.get_front() << endl;
    d.pop_rear();
    cout << "Rear element after popping from rear: " << d.get_rear() << endl;
    cout << "Is deque empty? " << (d.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is deque full? " << (d.isFull() ? "Yes" : "No") << endl;
    d.push_front(8);
    d.push_rear(40);
    d.push_front(7);
    d.push_rear(50); // This will show that deque is full
    cout << d.get_rear() << endl; // 40
    d.push_rear(60); // This will show that deque is full
    cout << d.get_rear() << endl; // 40
    d.pop_front();
    d.pop_rear();
    d.pop_front();
    d.pop_rear();
    d.pop_front();
    d.pop_front(); // This will show that deque is empty

    cout << 1%5 << endl; // 1
    cout << 2%5 << endl; // 2
    cout << 3%5 << endl; // 3
    cout << 4%5 << endl; // 4
    cout << 5%5 << endl; // 0
    
}