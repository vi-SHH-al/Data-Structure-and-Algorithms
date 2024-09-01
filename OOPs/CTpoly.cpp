// Function overloading 
// operator overloading
#include<iostream>
using namespace std;

class A
{   public:
    int a;
    int b;
    float sum(float a,float b)
    {    
        return (a+b);
    }
    int sum(int a,int b)
    {   
        return a+b;
    }
    int sum(int a,int b,int c)
    {
        return a+b+c;
    }
    
    //operator overloading
    void operator+ (A obj)
    {
        cout<<"result is "<<(this->a)-obj.a;
    }
};


int main()
{   
    A obj;
    //long a=10;
   // float a=2.0;
    cout<<obj.sum(10,5)<<endl;
    cout<<obj.sum(10.0f,3.5f)<<endl;
    cout<<"sum of three is "<<obj.sum(4,9,1)<<endl<<endl;

    A obj1,obj2;
    obj1.a=5;
    obj2.a=7;
    
    cout<<"+ overloaded "<<endl;
    cout<<"a+b= "<<endl;
    obj1+obj2;
    return 0;
}