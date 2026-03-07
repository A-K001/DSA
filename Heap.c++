#include <iostream>
#include <queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1 ){
            int parent = index/2;
            
            if (arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteFromHeap(){
        if (size == 0){
            cout << "Heap Empty" << endl;
            return;
        }
        
        arr[1] = arr[size];
        size --;

        int i = 1;
        while(i < size){
            int left = i*2;
            int right = i*2 + 1;
            if (left <= size && arr[left] >= arr[right] && arr[i] < arr[left] ){  
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right <= size && arr[left] < arr[right] && arr[i] < arr[right] ){
                swap(arr[i], arr[right]);
                i = right;
            }
            else{
                return;
            }
        }
        return;
    }
    void print(){
        for (int i = 0 ; i <=size ; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest]) //! Note: left < n because we need to check if the left child exists or not
        largest = left;

    if(right <= n && arr[right] > arr[largest]) //! Note: right < n because we need to check if the right child exists or not
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while (size > 1){
        // step 1
        swap(arr[size], arr[1]);
        size --;
        // step 2
        heapify(arr , size , 1);
    }
}

int main(){
    
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);
    h.insert(70);
    h.print();
    
    h.deleteFromHeap();
    h.print();
    cout << endl;

    int arr[6] = {-1, 35, 30, 40, 10, 20};
    int n = 5;

    cout << "Printing the array " << endl;
    for (int i = 1; i <= n; i++ ){
        cout << arr[i] << " ";
    }cout << endl;

    for (int i = n/2 ; i > 0 ; i--){
        heapify(arr , n, i);
    } 

    cout << "Printing the heapified array " << endl;
    for (int i = 1; i <= n; i++ ){
        cout << arr[i] << " ";
    }cout << endl;

    heapSort(arr , n);
    cout << "Printing the sorted array " << endl;
    for (int i = 1; i <= n; i++ ){
        cout << arr[i] << " ";
    }cout << endl;
    
    cout << endl << "implementing heap using priority queue" << endl << endl;
    //  max heap
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);
    pq.push(25);
    pq.push(1);
    cout << "Top element of the max heap is " << pq.top() << endl; // 25   
    pq.pop();
    cout << "Top element of the max heap is " << pq.top() << endl; // 20
    pq.pop();
    cout << "Top element of the max heap is " << pq.top() << endl; // 15
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap; //! Note: we need to specify the type of the container and the comparison function to create a min heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(15);
    minHeap.push(25);
    minHeap.push(1);
    cout << "Top element of the min heap is " << minHeap.top() << endl; // 1
    minHeap.pop();
    cout << "Top element of the min heap is " << minHeap.top() << endl; // 5
    minHeap.pop();
    cout << "Top element of the min heap is " << minHeap.top() << endl; // 10

    return 0;
}