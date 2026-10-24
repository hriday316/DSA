#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;

   Node(int val)
   {
      data = val;
      left = right = NULL;
   }
};

Node *insert(Node *root, int val)
{
   if (root == NULL)
   {
      root = new Node(val);
      return root;
   }
   if (root->data > val)
   {
      root->left = insert(root->left, val);
   }
   else
   {
      root->right = insert(root->right, val);
   }

   return root;
}

Node *buildBST(vector<int> arr)
{
   Node *root = NULL;

   for (int i = 0; i < arr.size(); i++)
   {
      root = insert(root, arr[i]);
   }
   return root;
}

void inOrder(Node *root)
{
   if (root == NULL)
   {
      return;
   }

   inOrder(root->left);
   cout << root->data << " ";
   inOrder(root->right);
}

Node *getInorderSuccessor(Node *root)
{
   while (root->left != NULL)
   {
      root = root->left;
   }
   return root;
}

Node *delNode(Node *root, int val)
{
   if (root == NULL)
      return NULL;

   if (root->data > val){ // left subtree
      root->left = delNode(root->left, val);
   }else if (root->data < val){ // right subtree
      root->right = delNode(root->right, val);
   }else{
      // root == val
      // case1 : 0 child both null
      if (root->left == NULL && root->right == NULL)
      {
         delete root;
         return NULL;
      }
       // case2: 1 child one null
      if (root->left == NULL || root->right == NULL){
         return root->left == NULL ? root->right : root->left;
      }
      // case3 : 2 children
      //  inorder successor == root right subtree left most node
      Node *IS = getInorderSuccessor(root->right);
      root->data = IS->data;
      root->right = delNode(root->right, IS->data);
      return root;
   }
   return root;
}

int main()
{
   vector<int> arr = {8, 5, 3, 1, 4, 6, 10, 11, 14};
   Node *root = buildBST(arr);
   inOrder(root);
   cout << endl;
   delNode(root, 5);
   inOrder(root);

   cout << endl;

   return 0;
}