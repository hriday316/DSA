#include <iostream>
using namespace std;

void removeDuplicate(string str, int i, string ans, int map[])
{

   if (i == str.size() - 1)
   {
      cout << ans << endl;
      return;
   }

   char ch = str[i];
   int idx = int(ch - 'a');

   if (map[idx] == true)
   {
      removeDuplicate(str, i + 1, ans, map);
   }
   else
   {
      map[idx] = true;
      ans = ans + ch;
      removeDuplicate(str, i + 1, ans, map);
   }
}

int main()
{
   int i = 0;
   string str = "apdnacodddllege";
   string ans = "";
   int arr[26] = {false};
   removeDuplicate(str, i, ans, arr);
   cout << ans << endl;

   return 0;
}

// clang++ code.cpp -o a.out && ./a.out