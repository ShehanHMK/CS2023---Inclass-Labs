#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root != NULL) {
      traverseInOrder(root->left);
      cout<<root->key<<" ";
      traverseInOrder(root->right);
   }

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL){
  struct node* tempNode=(struct node *)malloc(sizeof(struct node));
  tempNode->key=key;
  tempNode->left=NULL;
  tempNode->right=NULL;
  return tempNode;

  }
  if (key < node->key){
    node->left = insertNode(node->left, key);
  }
  
  else if (key > node->key){
    node->right = insertNode(node->right, key);
  }
  
  return node;

}
struct node *getMinimumRightNode(struct node *node) {

  while (node && node->left != NULL){
    node=node->left;
  }
  return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL){
    return root;
  }
  else if(root->key==key){ //found the value in key
    if(root->left ==NULL and root->right==NULL){
      //no children
      return NULL;
    }
    else if(root->left ==NULL){
      //right child is there
      root=root->right;
      return root;
    }

    else if(root->right==NULL){
      //left child is there
      root= root->left;
      return root;
    }

    else{
      //node has both left and the right child
      struct node *right_min = getMinimumRightNode(root->right);
      root->key = right_min->key;
      root->right = deleteNode(root->right, right_min->key);
     
    }
  }
  else if (key < root->key){
    root->left = deleteNode(root->left, key);
  }
    
  else if (key > root->key){
    root->right = deleteNode(root->right, key);
  }
 return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}