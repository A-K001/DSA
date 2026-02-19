#include <iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

    node (int d){
        this -> data = d;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

node* buildTree(node* root){
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    
    if (data == -1) {
        return nullptr;
    }
    
    cout << "Enter data for inserting in the left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in the right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    
    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);
    
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        
        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        
        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal_Using_Size(node* root) {
    if (root == nullptr) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {

        int levelSize = q.size();  
        // Number of nodes at current level

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }

        cout << endl;  
        // After processing one level
    }
}


void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(node* root){
    // base case
    if (root == nullptr){
        return;
    }

    inorder(root -> left);          //! L
    cout << root -> data << " ";    //! N
    inorder (root -> right);        //! R
}

void preorder(node *root){
    if (root == nullptr){
        return;
    }

    cout << root -> data << " ";    //! N
    preorder(root -> left);         //! L
    preorder(root -> right);        //! R
    
}

void postorder(node *root){
    if (root == nullptr){
        return;
    }

    postorder(root -> left);         //! L
    postorder(root -> right);        //! R
    cout << root -> data << " ";    //! N
    
}

int main (){
    node* root = nullptr;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root); // Building tree using recursive function
    
    cout << "Level Order Traversal Using NULL" << endl;
    levelOrderTraversal(root);

    cout << "Level Order Traversal using .size()" << endl; 
    levelOrderTraversal_Using_Size(root);
    cout << endl;
    cout << "In Order Traversal (LNR)" << endl;
    inorder(root); // 7 3 11 1 17 5

    cout << endl;
    cout << "Pre Order Traversal (NLR)" << endl;
    preorder(root); // 1 3 7 11 5 17

    cout << endl;
    cout << "Post Order Traversal (LRN)" << endl;
    postorder(root);
    cout << endl;
    cout << endl;

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1    
    cout << "Buildind Tree using level Order Terversal" << endl;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;
}