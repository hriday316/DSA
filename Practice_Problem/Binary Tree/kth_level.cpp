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

void KthHelper(Node* root, int currLevel, int k){
   if (root == NULL || currLevel > k)
   {
       return;
   }
   
   if (currLevel ==  k)    
   {
       cout << root->data << " ";
       return;
   }

    KthHelper(root->left,currLevel+1,k);
    KthHelper(root->right,currLevel+1,k);
}

void KthLevel(Node* root, int k){
 KthHelper(root,1,k);
   
}


int main (){
   vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
   vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

   Node* root = buildTree(nodes);
   KthLevel(root,4);


   cout << endl;

   return 0;
}