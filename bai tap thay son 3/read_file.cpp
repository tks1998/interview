#include <bits/stdc++.h>

using namespace std;
int x;
int main()
{

    fstream f;
    f.open("hihi3.binary",ios::out | ios::binary);
    int dem=0;
    while (!f.eof())
    {
        dem++;
        if (dem==121) break;
        float x= rand();
        float y = x/113;
        f<<y<<endl;
        cout<<y<<endl;
    }
    f.close();
    return 0;
}
