#include <bits/stdc++.h>
#define ll long long
using namespace std;

string InputFileName,OutputFileName;

ll Memory_Limit;

int first1, last1, first2, last2;

void read_data()
{
    cout<<"Input File Name "<<endl;

    cin>>InputFileName;

    cout<<"Output File Name "<<endl;

    cin>>OutputFileName;

    cout<<"Memory limit "<<endl;

    cin>> Memory_Limit ;
}
// compare two word
bool compare(string word1 , string word2)
{
    first1 = 0 ;
    first2 = 0 ;
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
void merge_data_into_result_file(vector<string> small_data , string OutputFileName)
{
    string word;
    fstream data_,merge_result;
    // prepare merge sort -> sort vector small_data

    sort(small_data.begin(),small_data.end(),compare);

    //merge sort small_data and OutputFileName
    data_.open(OutputFileName,ios::in );
    cout<<"small size "<<small_data.size()<<" "<<small_data[0]<<endl;
    merge_result.open("current_data.txt",ios::out|ios::trunc );

    int first = 0;
    int last =small_data.size()-1;
    cout<<"********************"<<endl;
   /* while (data_>>word)
    {
        cout<<"lan thu n "<<word<<endl;
    }
    cout<<"********************"<<endl;*/
    while (data_>>word)
    {
        cout<<"day la tu"<<word<<endl;
        while (first <= last && compare(small_data[first],word))
        {
           // cout<<"xem "<<first<<" "<<last<<endl;
            merge_result<<small_data[first]<<endl;

            first++;
          //  if (first == last ) cout<<"(((( "<<small_data[first]<<endl;
        }
        if (first <= last )
        {
            merge_result<<word<<endl;
        }

        first++;
    }

    if (first < last) while (first < last )  cout<<small_data[first++]<<endl , merge_result<<small_data[first++]<<endl;

    data_.close();
    merge_result.close();

    data_.open(OutputFileName,ios::out |ios::trunc);
    merge_result.open("current_data.txt",ios::in );
    while(merge_result>>word)
    {
        data_<<word<<endl;

    }

    data_.close();
    merge_result.close();
    // save data from data into OutputFileName
}
void process(string InputFileName , string OutputFileName , ll Memory_Limit )
{
    fstream  data;
    vector<string> get_data;
    int length_string,sum_memory_in_small_file = 0;
    string st;
    data.open(InputFileName,ios::in );
    while (data>>st)
    {
        length_string = st.length();
        if (sum_memory_in_small_file + length_string >  10)
        {
            merge_data_into_result_file(get_data,OutputFileName);
            get_data.clear();
            sum_memory_in_small_file = 0;
        }
        get_data.push_back(st);
        sum_memory_in_small_file += length_string;
    }
    // thieu ne
}
int main()
{
    read_data();
    process(InputFileName,OutputFileName,Memory_Limit);

    return 0;
}
