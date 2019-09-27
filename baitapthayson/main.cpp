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
    result3.open("EXT3.binary",ios::out | ios::binary | ios::trunc);

    float x,y;
    int demc=0;
    if (!(result>>x))
    {
        while(result2>>y) result3<<y<<endl;
    }
    else
    {
        result>>x;
        result2>>y;
        while (!result.eof() && !result2.eof())
        {
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

        if (result.eof()) result3<<y<<endl;
        if (result2.eof()) result3<<x<<endl;

        while(!result.eof()) { result>>x ; result3<<x<<endl;}
        while(!result2.eof()) {result2>>y ;result3<<y<<endl;}

    }

    result.close();
    result2.close();
    result3.close();

    result.open("EXT.binary",ios::out | ios::binary | ios::trunc);
    result3.open("EXT3.binary",ios::in | ios::binary );

    while (result3>>x)
    {
        result<<x<<endl;
    }
    result.close();
    result3.close();

}
void merge_data(int n)
{
    while (!p.empty()) p.pop();
    result2.open("EXT2.binary",ios::out | ios::trunc);
    float x;
    for (int i=0;i<n;i++)
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
    int dem2=0;
    while (!p.empty() )
    {
        top_heap = p.top();
        p.pop();
        result2<<top_heap.second<<endl;
        cs = top_heap.first;
        if (file[cs]>>x) p.push(ii(cs,x));
    }

    for (int i=0;i<n;i++)
    {
        while(!file[i].eof())
        {
            file[i]>>x;
            result2<<x<<endl;
        }
    }
    // result 2


    for (int i=0;i<n;i++) file[i].close();
    result2.close();

    result2.open("EXT2.binary",ios::in| ios::binary);
    dem2=0;
    while (result2>>x)
    {
        dem2++;
    }
    cout<<"day la merge ext2 "<< dem2<<endl;
    result2.close();
    merge_result_result2();
}
void write_file(vector<float> a ,int k)
{
    if (a.size()<10) cout<<"-----------"<<a.size()<<endl;
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
    f.open("EXT.binary",ios::out|ios::binary| ios::trunc);
    f.close();
    f.open("EXT2.binary",ios::out|ios::binary| ios::trunc);
    f.close();
    f.open("EXT3.binary",ios::out|ios::binary| ios::trunc);
    f.close();
    int running;
    f.open("hihi3.binary",ios::in | ios::binary);
    cout<<"please input running"<<endl;

    cin>>running;
    string st ="";
    //string st = "a";
    for (int i=0;i<running;i++)
    {
        st = st + 'b';
        name[i]=st+".binary";
    }
    float x;
    int k = 0;
    a.clear();
    int demsize=0;
    int sub_list = 0;
    while (f>>x)
    {
        if (k>running-1)
        {
            merge_data(running);
            k=0;
        }
        if (a.size()== maxx)
        {
            write_file(a,k);
            k++;
            a.erase(a.begin(),a.end());
        }
        a.push_back(x);
        demsize++;
    }
    cout<<"dem seize "<<demsize<<endl;
    f.close();

    cout<<"chuck cuoi "<<a.size()<<endl;
    if (a.size() >0 )
    {
        cout<<"day la k "<<k<<endl;
        write_file(a,k);

    } else k--;

    if (k>=0) merge_data(k+1);

    cout<<demsize<<endl;

    result.open("EXT.binary",ios::in | ios::binary);
    int dem=0;
    while (result>>x)
    {
        dem++;
    }
    result.close();
    cout<<demsize<<" "<<dem<<endl;
    return 0;
}

/*
        load all data -> vector ; sort nlog(n)
*/
