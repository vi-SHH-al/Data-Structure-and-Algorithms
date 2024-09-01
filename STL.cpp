#include<iostream>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>

using namespace std;

void vector1()
{       // vector increase its size  by accuring the double of it
    vector<int> v;
    v.push_back(1);
    cout<<"the size of vector is: "<<v.size()<<endl;
    v.push_back(2);
    cout<<"the size of vector is: "<<v.size()<<endl;
    v.push_back(3);
    cout<<"the size of vector is : "<<v.size()<<endl;
    for(auto i:v)
    cout<<i<<endl;
    cout<<"after popping the last element"<<endl;
    v.pop_back();
    for(auto i:v)
    cout<<i<<endl;
   // v.assign(5,0);
    //for(auto i:v)
    //out<<i<<endl;
    cout<<"after inserting 6 at desired position";
    v.insert(v.begin()+2,6);
    for(auto i:v)
    cout<<i<<endl;

    cout<<"we can print it by v.at(i) and v[i] also";

}


void map1()
{
    map<int,int> m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    m[4]=40;
    m[5]=50;
    m.insert({6,60});

    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;
    map<int,int>::iterator itr=m.begin();
    itr++;
    m.erase(itr);
    cout<<"Fter ersing eh second element";
    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;
}


void set1()
{
    set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(7);
    s.insert(0);

    for(auto i:s)
    cout<<i<<endl;
    set<int>::iterator it=s.begin();
    it++;
    it++;
    s.erase(it);
    for(auto i:s)
    cout<<i<<endl;

    cout<<"5 is present or not"<<s.count(5);
     
}


void priority_queue1()
{
    priority_queue<int> qp;
    qp.push(4);
    qp.push(2);
    qp.push(1);
    qp.push(7);
    int n=qp.size();
    for(int i=0;i<n;i++)
    { 
        cout<<qp.top()<<" ";   
        qp.pop();
    }
    cout<<endl;
}


void queue1()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"size is "<<q.size()<<endl;
    cout<<"The front element is "<<q.front()<<endl;
    cout<<"The last element is "<<q.back()<<endl;
    q.pop();
    cout<<"after popping the first element is "<<q.front()<<endl;
    cout<<"new size is "<<q.size()<<endl;
}


void stack1()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;
    cout<<"the size of stack is "<<s.size()<<endl;
    s.pop();
    cout<<"After deleting top element, new top is "<<s.top()<<endl;
}


void list1(void)
{
    list<int> l;
    l.push_back(3);
    l.push_back(4);

    for(int i:l)
    cout<<i<<endl;

}

void deque1()
{     deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.erase(d.begin());
  
    for(int i:d)
    cout<<i<<endl;
    for(auto i=d.begin();i<d.end();++i)
    cout<<*i<<endl;
}



int main()
{   //map1();
    set1();
    //priority_queue1();
    //queue1();
    //stack1();
   
    //list1();
    // deque1();
    //vector1();
    return 0;
}