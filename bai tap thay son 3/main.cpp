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
    int demc=0;
    while (!result.eof() && !result2.eof())
    {
        result>>x;
        result2>>y;
        if (x>y)
        {
            result3<<y<<endl;
            if (!result2.eof()) result2>>y;
        }
        else
        {
            result3<<x<<endl;
            if (!result.eof()) result>>x;
        }
    }
    if (!result.eof()) result3<<y<<endl;
    if (!result2.eof()) result3<<x<<endl;

    while(!result.eof()) { result>>x ; result3<<x<<endl;}
    while(!result2.eof()) {result2>>y ;result3<<y<<endl;}

    result.close();
    result2.close();
    result3.close();

    result.open("EXT.binary",ios::out | ios::binary );
    result3.open("EXT3.binary",ios::in | ios::binary);

    while (result3>>x)
    {
        result<<x<<endl;
        demc++;
    }
    cout<<"day la size sau khi merge "<<demc<<endl;
    result.close();
    result3.close();
}
void merge_data(int n)
{
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
    ii top_heap ;
    int cs;
    cout<<"toi la size "<<p.size()<<endl;
    int dem1=0,dem2=0;
    while (!p.empty() )
    {
        top_heap = p.top();
        p.pop();
        result2<<top_heap.second<<endl;
        cs = top_heap.first;
        if (!file[cs].eof())
        {
            file[cs]>>x;
            p.push(ii(cs,x));
        }
        dem1++;
    }
    for (int i=0;i<=n;i++)
    {
        while(!file[i].eof())
        {
            dem2++;
                file[i]>>x;
                result2<<x<<endl;
        }
    }
    cout<<dem1+dem2<<endl;
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
        g<<a[i]<<endl;
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
    for (int i=0;i<=running;i++)
    {
        st = st + 'b';
        name[i]=st+".binary";
    }

    float x;
    int k = 0;
    a.clear();
    int demsize=0;
    while (f>>x)
    {
        if (k>running)
        {
            merge_data(running);
            k=0;
        }
        if (a.size()== maxx-1)
        {
            write_file(a,k);
            k++;
            a.clear();
        }
        a.push_back(x);
        demsize++;
    }
    f.close();
    write_file(a,k);
    merge_data(k);

    cout<<demsize<<endl;

    result.open("EXT.binary",ios::in | ios::binary);
    int dem=0;
    while (result>>x)
    {
        dem++;
    }
    cout<<demsize<<" "<<dem<<endl;
    return 0;
}

/*
        load all data -> vector ; sort nlog(n)
*/
