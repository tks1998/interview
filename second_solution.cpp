#include <bits/stdc++.h>
#define ll long long
using namespace std;

string InputFileName,OutputFileName;

ll Memory_limit;
void read_data()
{
    cout<<"Input File Name "<<endl;

    cin>>InputFileName;

    cout<<"Output File Name "<<endl;

    cin>>OutputFileName;

    cout<<"Memory limit "<<endl;

    cin>> Memory_limit ;
}
bool compare(string word1 , string word2)
{
    // flase-> word1<word2
    // true word1>word2
     // library support compare two string with lexicographical compare
    return lexicographical_compare(word1,word2);
}
void merge_data_into_result_file(vector<string> small_data , string OutputFileName)
{
    fstream data,merge_result;
    // prepare merge sort -> sort vector small_data
    sort(small_data,small_data+small_data.size(),compare);

    //merge sort small_data and OutputFileName
    data.open(OutputFileName,ios::in |ios::trunc);
    merge_result.open("current_data.txt",ios::out |ios::trunc);
    int first = 0;
    int last =small_data.size()-1;
    while (data>>st)
    {
        while (first <= last && lexicographical_compare(st,small_data[first]))
        {
            merge_result<<small_data[first];
            first++;
        }
        merge_result<<st<<endl;
    }
    data.close();
    if (first < last) while (first < last )   merge_result<<small_data[first++];
    merge_result.close();
    data.close();
    data.open(OutputFileName,ios::out |ios::trunc);
    merge_result.open("current_data.txt",ios:: in |ios::trunc);
    while(merge_result>>st)
    {
        data<<st<<endl;
    }
    data.close();
    merge_result.close();
    // save data from data into OutputFileName

}
void process(string InputFileName , string OutputFileName , ll Memory_Limit )
{
    ifstream  data_file;
    ofstream  small_file, result_file;
    vector<string> get_data;
    int length_string,number_file=0;

    int sum_memory_in_small_file;

    while (data>>st)
    {

        length_string = st.length();


        if (sum_memory_in_small_file + length_string >  4)
        {
            merge_data_into_result_file(get_data,OutputFileName);
            get_data.clear();
            sum_memory_in_small_file = 0;
        }
        get_data.push_back(st);
        sum_memory_in_small_file += length_string;
    }
}
int main()
{
    read_data();
    process();



    return 0;
}
