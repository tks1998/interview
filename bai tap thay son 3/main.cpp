#include <bits/stdc++.h>
#define ii pair<int,float>

using namespace std;
const int maxn = 100;
const int maxx = 10;
vector<float> a(1000); // max 100 running
string name[maxn];
fstream file[maxn];
fstream f,g;
struct cmp{
    bool operator() (ii a , ii b)
    {
        return (a.second>b.second) ;
    }
};
fstream result,result2,result3;
priority_queue<ii,vector<ii>,cmp> p;
void merge_result_result2()
{
    result.open("EXT.binary",ios::in | ios::binary );
    result2.open("EXT2.binary",ios::in | ios::binary );
    result3.open("EXT3.binary",ios::out | ios::binary );
    float x,y;
    while (!result.eof() && !result2.eof())
    {
        result>>x;
        result2>>y;
        if (x>y)
        {
            result3<<y<<" ";
            if (!result2.eof()) result2>>y;
        }
        else
        {
            result3<<x<<" ";
            result>>x;
        }
    }
    while(result>>x) result3<<x<<" ";
    while(result2>>y) result3<<y<<" ";

    result.open("EXT.binary",ios::out | ios::binary | ios::trunc);
    result3.open("EXT3.binary",ios::in | ios::binary);

    while (result3>>x)
    {
        result<<x<<" ";
    }
    result.close();
    result2.close();
    result3.close();
}
void merge_data(int n)
{
    cout<<n<<endl;
    while (!p.empty()) p.pop();
    result2.open("EXT2.binary",ios::out);
    float x;
    for (int i=0;i<=n;i++)
    {
        file[i].open(name[i],ios::in | ios :: binary);
        if (!file[i].eof())
        {
            file[i]>>x;
            p.push({i,x});
        }
    }
    cout<<"trc vao heap "<<p.size()<<endl;
    ii top_heap ;
    int cs;
    while (!p.empty() && !file[cs].eof())
    {
        top_heap = p.top();
        p.pop();
        result2<<top_heap.second<<" ";
        cs = top_heap.first;
        cout<<cs<<endl;
        if (!file[cs].eof())
        {
            file[cs]>>x;
            cout<<cs<<" "<<x<<endl;
            p.push(ii(cs,x));
        }
    }
    cout<<"sau heap"<<endl;
    for (int i=0;i<=n;i++) file[i].close();
    result2.close();
    merge_result_result2();
}
void write_file(vector<float> a ,int k)
{
    sort(a.begin(),a.end());
    g.open(name[k],ios::out | ios::binary);
    for (int i=0 ; i<a.size(); i++)
    {
        g<<a[i]<<" ";
    }
    g.close();
}
int main()
{

    int running;
    f.open("hihi3.binary",ios::in | ios::binary);

    cout<<"please input running"<<endl;

    cin>>running;
    string st ="";
    //string st = "a";
    for (int i=1;i<=running;i++)
    {
        st = st + 'b';
        name[i]=st+".binary";
    }

    float x;
    int k = 0;

    while (f>>x)
    {
        if (k>running)
        {
            merge_data(running);
            k=0;
        }
        if (a.size()== maxx)
        {
            write_file(a,k);
            k++;
        }
        a.push_back(x);
    }
    for (int i=0;i<10;i++) cout<<a[i]<<endl;
    cout<<"toi day"<<endl;
    write_file(a,k);

    merge_data(k);

    return 0;
}

/*
        load all data -> vector ; sort nlog(n)
*/
