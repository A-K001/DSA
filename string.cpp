#include <iostream>
using namespace std;

void reverseArray (char name[],int len){
    int s = 0;
    int e = len - 1;
    while (s<e){
        swap(name[s++],name[e--]);
    }
}
int getLength(char name[]){
    
    int i = 0;
    while (name[i] != '\0' ){
        i++;
    }
    return i;
}
int main() {
    char name[7];
    cout << "Enter your First name : " ;
    cin >> name;
    cout << "Your name is "<< name << endl;
    int len = getLength(name);
    cout << "Length of ur name is : " << len << endl ;
    reverseArray(name,len);
    cout << "Reversed name : " << name << endl;

    return 0;
}

