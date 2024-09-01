#include<iostream>
using namespace std;
class A{
    public:
    int a;
    string name;
    A()
    {
        cout<<"Class A constructor called"<<endl;
    }
    void fun()
    {
        cout<<"function of class A"<<endl;
    }

};
class A1{
    public:
    A1()
    {
        cout<<"Class A1 constructor called"<<endl;
    }
    void fun()
    {
        cout<<"function of class A1"<<endl;
    }
};
class B: public A       // Single inhertiance
{   public:
    B()
    {
        cout<<"Class B constructor called"<<endl;
    }
    void fun()
    {
        cout<<"function of class B"<<endl;
    }
};
class C:public B       //multipleinhertiance
{
};

class D: public A,public A1     //multilevel inhertiance 
{

};
                        
int main()
{
    C o;
    o.fun();
    cout<<endl<<endl;
    D obj;
  // obj.fun();          // Ambiguity created as A and B both have fun function
   obj.A1::fun();    //sol to ambiguity ,,it will refer to fun of A
    cout<<endl<<endl;
    return 0;
}
