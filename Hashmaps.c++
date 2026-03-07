#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // ? Creation
    unordered_map<string, int> um; // if we use map instead of unordered_map, it will be ordered based on sequence in which the keys were inserted, and it uses a balanced binary search tree internally, while unordered_map uses a hash table and does not maintain any order of keys.
    
    //? insertion
    um["apple"] = 1;

    pair <string, int> p("banana", 2);
    um.insert(p);

    pair<string, int> p2 = make_pair("orange", 3);
    um.insert(p2);

    um.insert({"grape", 4});
    um.insert({{"melon", 5}, {"kiwi", 6}});
    um["apple"] = 10; // update value

    // ? Searching
    cout << "Value of apple: " << um["apple"] << endl; // 10
    cout << "Value of banana: " << um.at("banana") << endl; // 2
    // ! cout << "Accesssing non-existing key: " << um.at("Unknown fruit") << endl; // gives error
    cout << "Accesssing non-existing key using um['unknown fruit'] : " << um["Unknown fruit"] << endl; // 0, creates new key with default value 0
    cout << "Accesssing non-existing key using um.at() after um['unknown fruit']: " << um.at("Unknown fruit") << endl; // now this will also give 0
    
    // to solve the above problem, and not to create a new key when searching for a non-existing key, we can use find() method with if condition
    if(um.find("grape") != um.end()){ // find() returns an iterator to the element if found, otherwise it returns um.end()
        cout << "Grape found with value: " << um["grape"] << endl; // 4
    } else {
        cout << "Grape not found" << endl;
    }

    cout << "Size of unordered_map: " << um.size() << endl; // 6
    cout << "Is unordered_map empty? " << (um.empty() ? "Yes" : "No") << endl; // No
    cout << "Count of 'apple' in unordered_map: " << um.count("apple") << endl; // 1 of not found then 0
    cout << endl;
    
    cout << "Iterating over unordered_map using auto in for loop :" << endl;
    for(auto it = um.begin(); it != um.end(); it++){
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }
    cout << endl;
    
    cout << "Iterating over unordered_map using range-based for loop :" << endl;
    for(const auto& pair : um){
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
    cout << endl;

    cout << "Iterating over unordered_map using iterator :" << endl;
    unordered_map<string, int>::iterator it = um.begin();
    while(it != um.end()){
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        it++;
    }
    cout << endl;
    
    // ? Deletion
    cout << "Deleting key 'banana' from unordered_map" << endl;
    um.erase("banana"); // removes the key "banana" and its value
    if(um.find("banana") != um.end()){
        cout << "Banana found with value: " << um["banana"] << endl; 
    } else {
        cout << "Banana not found" << endl; // Banana not found
    }
    um.clear(); // removes all key-value pairs from the unordered_map
    cout << "Size of unordered_map after clear: " << um.size() << endl;


}