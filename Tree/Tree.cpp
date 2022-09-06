#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
};

Node* createNode(int data){ //return Node* 型別(也就是回傳這個Node的地址，型別是Node*)
    Node * newNode = new Node;
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

void printTree(Node* root){
    if(root == NULL)
        return;
    /*
    preorder data,left,right
    inorder left,data,right
    postorder left,right,data
    */
    cout << root -> data << endl;
    printTree(root -> left);
    printTree(root -> right);
}

int findSum(Node* root){
    if(root == NULL)
        return 0;
    return root -> data + findSum(root -> left) + findSum(root -> right);
}

int maxDepth(Node* root){
    if(root == NULL)
        return 0;
    return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
}

int main(){
    //Level 1
    Node * root = createNode(1);
    //Level 2
    root -> left = createNode(2);
    root -> right = createNode(3);
    //Level 3
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root -> right -> left = createNode(6);
    root -> right -> right = createNode(7);
    //level 4
    root -> left -> right -> left = createNode(9);
    root -> right -> right -> left = createNode(15);

    printTree(root);
    cout << "Sum : " << findSum(root) << endl;
    cout << "Max Depth : " << maxDepth(root) << endl;
}