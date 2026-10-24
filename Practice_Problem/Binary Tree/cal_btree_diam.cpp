#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public : 
   int data;
   Node* left;
   Node* right;

   Node(int  data){
      this->data = data;
      left = right = NULL;
   }
};

static int idx = -1;

Node* buildTree(vector<int>nodes){
   idx++;

   if(nodes[idx] == -1){
      return NULL;
   }

   Node* curr = new Node(nodes[idx]);
   curr->left = buildTree(nodes);
   curr->right = buildTree(nodes);

   return curr;
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


int dim(Node* root){

   if (root == NULL)
   {
       return 0;
   }
   

   int curr = calHeight(root->left) + calHeight(root->right) + 1;
   int leftDim = dim(root->left);
   int rightDim = dim(root->right);
   int maxDim = max(curr, max(leftDim,rightDim));

   return maxDim;
}

void preOrder(Node* root){
   if (root == NULL)
   {
       return;
   }
   

   cout << root->data << " ";
   preOrder(root->left);
   preOrder(root->right);
}

//approach 1.. main approach
void levelOrder(Node* root){

   if (root == NULL)
   {
      return;
   }
   
   queue<Node*>q;
   q.push(root);

   while (!q.empty())
   {
      Node* curr = q.front();
      q.pop();

      cout << curr->data << " ";
      if (curr->left != NULL)
      {
         q.push(curr->left);
      }
      if (curr->right != NULL)
      {
         q.push(curr->right);
      }
       
   }

   cout << endl;
   
}

// approach 2 for better view
void levelOrder2(Node* root){

   if (root == NULL)
   {
      return;
   }
   
   queue<Node*>q;
   q.push(root);
   q.push(NULL);

   while (!q.empty())
   {
      Node* curr = q.front();
      q.pop();

      if (curr == NULL)
      {
         if (!q.empty())
         {
            q.push(NULL);
            cout << endl;
         }
         
      }else{
         cout << curr->data << " ";
      if (curr->left != NULL)
      {
         q.push(curr->left);
      }
      if (curr->right != NULL)
      {
         q.push(curr->right);
      }
      }
      
       
   }

   cout << endl;
   
}


int main (){
   vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
   vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

   Node* root = buildTree(nodes2);

   // preOrder(root);
   // cout << endl;
   // cout << endl;
   // levelOrder2(root);

   cout << dim(root) << endl; 


   cout << endl;

   return 0;
}