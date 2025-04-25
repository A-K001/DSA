#include <iostream>
using namespace std;


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
    cout << "Length of ur name is : " << getLength(name) << endl ;
    
    return 0;
}