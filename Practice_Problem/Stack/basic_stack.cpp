#include<iostream>
#include<vector>
using namespace std;
template <class T> //template class 
class Stack{
   vector<T> vec;
public:
   void push(T val){
      vec.push_back(val);
   }

   void pop(){

      if(vec.empty()){
         cout << "Stack is empty" << endl;
         return;
      }
      vec.pop_back();
   }

   T top(){

       if(vec.empty()){
         cout << "Stack is empty" << endl;
         return;
      }

      int lastIdx = vec.size()-1;
      cout << vec[lastIdx] << endl;
      return vec[lastIdx];
   }
};

int main(){
   Stack<int> s;
   s.pop();
   s.push(5);
   s.top();
   return 0;
}