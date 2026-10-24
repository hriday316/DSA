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
      left = NULL;
      right = NULL;
   }
};

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
   idx++;
   if (nodes[idx] == -1)
   {
      return NULL;
   }

   Node *currNode = new Node(nodes[idx]);
   currNode->left = buildTree(nodes);
   currNode->right = buildTree(nodes);

   return currNode;
}

int calHeight(Node* root){
   if (root == NULL)
   {
       return 0;
   }
   
   int left = calHeight(root->left);
   int  right = calHeight(root->right);
   int height = max(left,right) +1;
   cout << root->data << " " << left << " " << right << "  " << height << endl;
   return height;
} 

void levelOrderPrint(Node *root)
{
   queue<Node *> Q;
   Q.push(root);
   Q.push(NULL);

   while (!Q.empty())
   {
      Node *curr = Q.front();
      Q.pop();

      // this if part only for level print 
      if (curr == NULL)
      {
         if (Q.empty())
            break;
         cout << endl;
         Q.push(NULL);
      }
      else
      {
         // main part 
         cout << curr->data << " ";

         if (curr->left != NULL)
         {
            Q.push(curr->left);
         }
         if (curr->right != NULL)
         {
            Q.push(curr->right);
         }
      }
   }
}

void preOrderPrint(Node *root)
{ // O(n)
   if (root == NULL)
   {
      return;
   }

   cout << root->data << " ";
   preOrderPrint(root->left);
   preOrderPrint(root->right);
}

void inOrderPrint(Node *root)
{ // O(n)
   if (root == NULL)
   {
      return;
   }

   inOrderPrint(root->left);
   cout << root->data << " ";
   inOrderPrint(root->right);
}

void postOrderPrint(Node *root)
{ // O(n)
   if (root == NULL)
   {
      return;
   }

   postOrderPrint(root->left);
   postOrderPrint(root->right);
   cout << root->data << " ";
}

int main()
{
   vector<int> nodes = {50, 30, 20, 10, -1, -1, -1, 40, -1, -1, 70, 60, -1, -1, 80, -1, -1};
   vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
   Node *root = buildTree(nodes2);
   // preOrderPrint(root);
   // cout << endl;
   // inOrderPrint(root);
   // cout << endl;
   // postOrderPrint(root);
   // cout << endl;
   // cout << endl;
   // levelOrderPrint(root);

   int ans = calHeight( root) ;

  cout <<"max height " << ans << endl;

   cout << endl;
   return 0;
}