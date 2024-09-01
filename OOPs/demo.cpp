#include<iostream>
//#include<string>
using namespace std;
class Hero{
    public:
    int health;
    string name;

    Hero(int health,string name)
    {
        this->health=health;
        this->name=name;
    }
    ~Hero()
    {
        cout<<"dest is called for "<<name<<endl;
    }
    int main()
    {
        cout<<"aa";
        return 0;
    }
};

