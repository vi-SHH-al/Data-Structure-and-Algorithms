#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);

    cout<<"Top element is "<<s.top()<<endl;
    cout<<"Size os stack is : "<<s.size()<<endl;

    s.pop();
    s.pop();
    cout<<"\nAfter popping 2 elements\n"<<endl;
    cout<<"top element is : "<<s.top()<<endl;
    cout<<"Size of stack is : "<<s.size()<<endl;

    return 0;
}