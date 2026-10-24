#include <iostream>
using namespace std;

 class Node{
  public: 
   int data;
   Node* next;

 public:
   Node(int val){
         data = val;
         next = NULL;
      }
 };

 class List {
   Node* head;
   Node* tail;

public:
   List(){
      head = NULL;
      tail = NULL;
   }

   void push_front(int val){
      Node* newNode = new Node(val);
      if(head == NULL){
         head = tail = newNode;
      }else{
         newNode-> next = head;
         head = newNode;
      }
   }

   void push_back(int val){
      Node* newNode = new Node(val);
      if(head==NULL){
         head = tail = newNode;
      }else{
         tail->next = newNode;
         tail = newNode;
      }
   }

   void insert(int val , int pos){
      Node* newNode = new Node(val);
      Node* tmp;
      for(int i =0; i< pos -1; i++){
         tmp = tmp->next;
      }

      // tmp is now at pos -1 means insert node place prev/left
      newNode->next = tmp->next;
      tmp->next = newNode;

   }
   int iteration(int key){
      Node* tmp = head;
      for(int i=0; tmp!=NULL; i++){
         if(tmp->data ==key){
            return i;
         }
         tmp = tmp->next;
      }
      return -1;
   }

   void print (){
      Node* tmp = head;
      while(tmp != NULL){
         cout << tmp->data << " ";
         tmp = tmp->next;
      }
      cout << "NULL\n";

    }
    
   void recursivePrintHelper(Node* tmp){
      if (tmp==NULL)
      {
          return;
      }
      cout << tmp->data << " ";
      recursivePrintHelper(tmp->next);

   }
   void recursivePrint(){
      recursivePrintHelper(head);
   }

   int searchRecHelper(Node* localHead, int key){
       if( localHead ==NULL){
         return -1;
      }
      if( localHead->data == key){
         return 0;
      }
     
     int idx = searchRecHelper( localHead->next ,key);
     if (idx == -1)
     {
      return idx;
     }
     

      return idx +1;
   }

   int searchRec(int key){
      return searchRecHelper(head, key);
   }

 };

 
int main()
{
   List linkList;
   linkList.push_front(3);
   linkList.push_front(2);
   linkList.push_front(1);
   linkList.insert(4,2);
   linkList.push_back(5);
   linkList.push_back(6);
   linkList.print();
   // cout << linkList.iteration(6);
   cout << linkList.searchRec(6) << endl;
    
   
  
   return 0;
}

// clang++ code.cpp -o a.out && ./a.out
