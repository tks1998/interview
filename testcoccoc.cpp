#include <bits/stdc++.h>
#define ll long long
using namespace std;

string st,st1,InputFileName,OutputFileName;

ll Memory_limit;

int main()
{

    fstream ofs;
    ofs.open("sen.txt",ios::in |ios::trunc);
    int dem=0;
    while (ofs>>st)
    {
        cout<<st<<endl;
    }
    ofs.close();

    ofs.open("sen.txt",ios::out);

    ofs.close();


  /*  ofs.open("sen.txt",ios::in |ios::trunc);

    while (ofs>>st){

    }
    ofs.close();*/


    return 0;
}
/*
    def
xya
xxya
ahuh12
*/
