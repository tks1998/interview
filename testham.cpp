// to_string example
#include <bits/stdc++.h>   // std::cout
using namespace std;
bool cmp(string st1 , string st2)
{
    return st1<st2;
}
int main ()
{
   fstream f;
   string st;
   f.open("sen.txt", ios::in);
   while (f>>st)
   {

   }
   f.close();
   f.open("sen.txt",ios::out | ios::trunc);
   f<<1<<endl;
   f.close();

  return 0;
}
