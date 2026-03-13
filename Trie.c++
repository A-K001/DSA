#include <iostream>
using namespace std;

class Trienode {
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;

        Trienode (char ch){
            data = ch;
            for (int i = 0 ; i <= 26 ; i++){
                children[i] = nullptr;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        Trienode* root;

        Trie (){
            root = new Trienode('\0');
        }

        // insert a word in trie
        void insertUtil(Trienode* root , string word){
            // base case
            if(word.length() == 0){
                root -> isTerminal = true;
                return;
            }

            // assumption : word will be in uppercase
            int index = word[0] - 'A';
            Trienode* child;

            // present
            if (root -> children[index] != nullptr){
                child = root -> children[index];
            }
            else {
                // not present
                child = new Trienode(word[0]);
                root -> children[index] = child;
            }

            // recursion
            insertUtil(child , word.substr(1));
        }

        // search a word in trie
        bool searchUtil(Trienode* root , string word){
            // base case
            if(word.length() == 0){
                return root -> isTerminal;
            }

            int index = word[0] - 'A';
            Trienode* child;

            // present
            if (root -> children[index] != nullptr){
                child = root -> children[index];
            }
            else {
                // not present
                return false;
            }

            // recursion
            return searchUtil(child , word.substr(1));
        }

        // delete a word from trie by removing the terminal node 
        void deleteUtil(Trienode* root , string word){
            // base case
            if(word.length() == 0){
                root -> isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            Trienode* child;

            // present
            if (root -> children[index] != nullptr){
                child = root -> children[index];
            }
            else {
                // not present
                return;
            }

            // recursion
            return deleteUtil(child , word.substr(1));
        }

        // // delete a word from trie by removing the nodes of the word
        // bool deleteUtil2(Trienode* root , string word){  // TODO : understand this function properly then try to implement it on your own
        //     // base case
        //     if(word.length() == 0){
        //         root -> isTerminal = false;
        //         for (int i = 0 ; i < 26 ; i++){
        //             if (root -> children[i] != nullptr){
        //                 return false;
        //             }
        //         }
        //         return true;
        //     }

        //     int index = word[0] - 'A';
        //     Trienode* child;

        //     // present
        //     if (root -> children[index] != nullptr){
        //         child = root -> children[index];
        //     }
        //     else {
        //         // not present
        //         return false;
        //     }

        //     // recursion
        //     bool shouldDeleteCurrentNode = deleteUtil2(child , word.substr(1));

        //     if (shouldDeleteCurrentNode){
        //         delete child;
        //         root -> children[index] = nullptr;

        //         for (int i = 0 ; i < 26 ; i++){
        //             if (root -> children[i] != nullptr || root -> isTerminal == true){
        //                 return false;
        //             }
        //         }
        //         return true;
        //     }
        //     return false;
        // }

        // prefix search in trie
        bool prefixUtil(Trienode* root , string word){
            // base case
            if(word.length() == 0){
                return true;
            }

            int index = word[0] - 'A';
            Trienode* child;

            // present
            if (root -> children[index] != nullptr){
                child = root -> children[index];
            }
            else {
                // not present
                return false;
            }

            // recursion
            return prefixUtil(child , word.substr(1));
        }
};


int main (){
    Trie* t = new Trie();
    t -> insertUtil(t -> root , "ARM");
    t -> insertUtil(t -> root , "ARMS");
    t -> insertUtil(t -> root , "DO");
    t -> insertUtil(t -> root , "TIME");
    cout << t -> searchUtil(t -> root , "ARM") << endl;
    cout << t -> searchUtil(t -> root , "DOw") << endl;
    cout << t -> searchUtil(t -> root , "TIM") << endl;
    t -> deleteUtil(t -> root , "ARM");
    cout << "After deleting the terminal node of ARM" << endl;
    cout << t -> searchUtil(t -> root , "ARM") << endl;
    cout << t -> prefixUtil(t -> root , "ARM") << endl; //! So even after deleting the terminal node of ARM , it is still present as a prefix in trie
    
    //TODO : understand the deleteUtil2 function properly then try to implement it on your own and then uncomment the below code to test it
    // cout << t -> deleteUtil2(t -> root , "ARMS") << endl;
    // cout << "After deleting the nodes of ARM" << endl;
    // cout << t -> searchUtil(t -> root , "ARM") << endl;
    // cout << t -> searchUtil(t -> root , "ARMS") << endl;
    // cout << t -> prefixUtil(t -> root , "ARM") << endl;

    return 0;
}  