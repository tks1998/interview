#include <bits/stdc++.h>
#define ll long long
using namespace std;

string st,st1,InputFileName,OutputFileName;

ll Memory_limit;
void read_data()
{
    cout<<"Input File Name"<<endl;

    cin>>InputFileName;

    cout<<"Output File Name"<<endl;

    cin>>OutputFileName;

    cout<<"Memory limit "<<endl;

    cin>> Memory_limit ;

}
void split_data_to_file()
{
    ifstream  data;

    // split small_file
    ofstream  small_file ;
    int length_string,number_file=0;

    string base_name = "split_file";
    string file_name = base_name + to_string(number_file);
    small_file.open(file_name);
    data.open(InputFileName);

    int sum_memory_in_small_file;

    while (data>>st)
    {
        length_string = st.length();
        sum_memory_in_small_file += length_string;

        if (sum_memory_in_small_file + length_string >  8)
        {
            sum_memory_in_small_file = length_string;
            number_file++;

        }
    }
}
int main()
{
    /*
        read file data
        split big file data to small file
    */
    /*split_data_to_file();
     cout<<"Output File Name"<<endl;

    cin>>OutputFileName;

    cout<<"Memory limit "<<endl;

    cin>> Memory_limit ;
  */
    string st="a";
    st=st+to_string(123);
    cout<<st;
    return 0;
}
