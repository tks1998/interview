#include <bits/stdc++.h>
#define ll long long
using namespace std;

string st,st1,InputFileName,OutputFileName;
int first1,first2 , last1,last2;
ll Memory_limit;
bool compare(string word1 , string word2)
{
    first1 = 0 ; first2 = 0 ;
    last1 = word1.size();
    last2 = word2.size();
    while (first1!=last1)
    {
        if (first2 == last2 || word1[first1] > word2[first2]) return false;
        else if (word1[first1] < word2[first2]) return true;
        ++first1 ;
        ++first2 ;
    }
    return (first2!=last2);
}
int main()
{
    string st1 = "ca";
    string st2 = "bb";
    if (compare(st1,st2))
    {
        cout<<st1<<" "<<st2<<endl;
    }
    else cout<<st2<<" "<<st1<<endl;

    return 0;
}
/*
    def
xya
xxya
ahuh12
*/
