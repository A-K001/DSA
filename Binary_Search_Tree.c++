#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node (int data){
        this -> data = data;
        this -> left  = this -> right = nullptr;
    }
};

node* insertIntoBST(node* &root , int data){
    // base case
    if (root == nullptr){
        root = new node(data);
        return root;
    }

    if (data < root -> data){
        root -> left = insertIntoBST(root -> left , data);
    }
    else{
        root -> right = insertIntoBST(root -> right , data);
    }
    return root;
}

void TakeInput(node* &root){

    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cin >> data;
    }
}

int MaxInTree(node* root){
    if (root == nullptr){
        return -1;
    }

    node *temp = root;
    while(temp -> right != nullptr){
        temp = temp -> right;
    }
    return temp -> data;
}

int MinInTree(node* root){
    if (root == nullptr){
        return -1;
    }

    node *temp = root;
    while(temp -> left != nullptr){
        temp = temp -> left;
    }
    return temp -> data;
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

node* DeleteFromBST(node* root , int data){
    if (root == nullptr){
        return nullptr;
    }

    if (root -> data == data){
    // 0 child
        if (root -> left == nullptr && root -> right == nullptr){
            delete root;
            return nullptr;
        }

    // 1 child

        // left child not null
        if (root -> left != nullptr && root -> right == nullptr){
            node *temp = root -> left;
            delete root;
            return temp;
        }

        // right child not null
        if (root -> right != nullptr && root -> left == nullptr){
            node* temp = root ->right;
            delete root;
            return temp;
        }
        
    // 2 children
        if (root -> right != nullptr && root -> left != nullptr){
            int minval = MinInTree(root -> right);
            root -> data = minval;
            root -> right = DeleteFromBST(root -> right , minval);
            return root;
        }

    }

    else if (root -> data > data){
        root -> left = DeleteFromBST(root -> left , data);
        return root;
    }
    else{
        root -> right = DeleteFromBST(root -> right , data);
        return root;
    }
}

int main(){
    // 10 8 21 7 27 5 4 3 -1
    // 10 8 21 9 7 27 25 5 22 4 3 23 29 -1
    node* root = nullptr;
    cout << "Enter data to create BTS" << endl;
    TakeInput(root);

    cout << "Printing the BTS" << endl;
    levelOrderTraversal(root);  
    cout << endl;

    cout << "In Order Traversal (LNR) also sorted in ascending " << endl;
    inorder(root);
    cout << endl;

    cout << "Pre Order Traversal (NLR)" << endl;
    preorder(root);
    cout << endl;

    cout << "Post Order Traversal (LRN)" << endl;
    postorder(root);
    cout << endl;
    
    cout << "Maximum value in BST is : " << MaxInTree(root) << endl;
    cout << "Minimum value in BST is : " << MinInTree(root) << endl;
    cout << endl;
    
    int val = 0;
    while (val != -1){
        cout << "Enter the number you want to delete and -1 to exit : " << endl;
        cin >> val;
        root = DeleteFromBST(root , val); // Deletion
        if (root == nullptr){
            cout << "BST is empty" << endl;
        }
        else {
            cout << "Printing the BTS after deletion of "<< val << endl;
            levelOrderTraversal(root);  
            cout << endl;
        }
    }
    return 0;
}

