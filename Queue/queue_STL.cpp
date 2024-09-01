#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.emplace(7);

    cout<<" Size :  "<<q.size()<<endl;
    cout<<" Front : "<<q.front()<<endl;
    cout<<" Rear :  "<<q.back()<<endl;

    q.pop();
    q.pop();
    cout<<"\n After two pop \n";
    cout<<" Front : "<<q.front()<<endl;
    cout<<" Rear :  "<<q.back()<<endl;

    queue<int> r;
    r.push(10);
    r.push(9);
    r.push(8);
    cout<<endl;
    cout<<"Size of q is : "<<q.size()<<endl;
    cout<<"Size of r is : "<<r.size()<<endl;
    q.swap(r);
    cout<<"Size of q is : "<<q.size()<<endl;
    cout<<"Size of r is : "<<r.size()<<endl;
    cout<<endl;


    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout<<"\n After another 4  pop \n";
    cout<<" Is queue empty :  "<<q.empty()<<endl;
    cout<<" Front : "<<q.front()<<endl;
    cout<<" Rear :  "<<q.back()<<endl;

    cout<<"\n After one more pop \n";
    q.pop();
    cout<<" Is queue empty :  "<<q.empty()<<endl;
    return 0;
}