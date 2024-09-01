#include<iostream>
#include"demo.cpp"
using namespace std;
/*class Hero{
    int heath;
    char name[18];
};*/
class mt{

};

//getter and setter
class person{
    public:         //for constructors
    int age;
    string name;
    char *height;
    
    person()    //Default constructor
    {
        cout<<"default constructor is called: "<<endl;
    }
    person(int age,string name)
    {   //this keyword will refer to the object variables ,,not local varaiableof the constructor
        this->age = age;
        this->name = name;
       
    }

    person(int age)
    {
        this->age=age;
    }

    //copy cconstructor;
    //deep copy of char
    person(person& A)
    {
        this->name=A.name;
        this->age=A.age;
        char *t=new char();
        *t=*A.height;
        this->height=t;
    }

    //age and name are of private change ,, so we can;t access directlyoutside the class.
    //so we use getter and setter function
    public:
    void set_name(string s)
    {
        name=s;
    }
    void set_age(int n)
    {
        age=n;
    }
    string get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    void printinfo()
    {
        cout<<"Age and name and char is : "<<name<<" "<<age<<" "<<*height<<endl;
    }

 
};
int main()
{    
    person A;       // calling default constructor or non parametrices constructor
    A.name="mike";
    A.age=20;

    
    person B(22,"Alice");
    
    person *C=new person(30);
    C->name="WIll";
    char c='A';
    (*C).height=&c;
    person D(*C);      // Values of C will copy in D
    cout<<"checking shadow and deep copy";
     D.printinfo();
     c='B';
     *((*C).height)='B';
      D.printinfo();
      cout<<endl<<endl;

      cout<<"fun outside class";
      
      A.printinfo();
   // cout<<"Age and name of A is : "<<A.name<<" "<<A.age<<endl;
    //cout<<"Age and name of B is : "<<B.name<<" "<<B.age<<endl;
    //cout<<"Age and name of C is : "<<C->name<<" "<<C->age<<endl;
    /*
    //static memory allocation
    person A;
    A.set_name("alex");
    A.set_age(20);

    cout<<"Name of A is: "<<A.get_name()<<endl;
    cout<<"Age of A is: "<<A.get_age()<<endl;

    //Dynamic memory allocation
    person *B=new person();
    B->set_name("Mike");
    B->set_age(25);
    cout<<"Name of B is: "<<B->get_name()<<endl;
    cout<<"Age of B is: "<<B->get_age()<<endl;
    */


    /*
    Hero h1;
    cout<<"size of class Hero  is "<<sizeof(h1)<<endl;// structure paddling
    mt e1;
    cout<<"size of empty class is : "<<sizeof(e1)<<endl;
    //health is declared public in Hero class
    h1.health=2;
    cout<<h1.health<<endl;
    
    person A;
    A.set_name("Alex");   // calling seter which is made public
    cout<<"Person A name is : "<<A.get_name();        //accessing private string by public getter function
    */
    cout<<endl<<endl;
    return 0;
}