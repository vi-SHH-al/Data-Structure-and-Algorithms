#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{   vector<int> v;
    v.push_back(3);
    v.push_back(0);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    cout<<"sorted vector is "<<endl;
    sort(v.begin(),v.end());   
    for(int i:v)
    cout<<i<<" ";
    cout<<endl<<endl;
    cout<<"finding the 2 by binary search: "<<binary_search(v.begin(),v.end(),2)<<endl;
    cout<<"finding the 10 by binary search: "<<binary_search(v.begin(),v.end(),10)<<endl;
    cout<<endl;
    cout<<"after rotating the vector by 2 elements: "<<endl;
    rotate(v.begin(),v.begin()+2,v.end());
    for(int i:v)
    cout<<i<<" ";
    cout<<endl;

    cout<<"the max element of vector v is :" <<*max_element(v.begin(),v.end())<<endl;
    cout<<"the min element is vector v is :" <<*min_element(v.begin(),v.end())<<endl;
    string s="string";
    reverse(s.begin(),s.end());
    cout<<endl<<"the reverse string is "<<s<<endl<<endl;
    //assigning vector with aray elements
    int arr[]={5,3,2,6,1,1,1,5,11,52};
    vector<int> vec(arr,arr+10);//5 is size of array

    cout<<"occurence of 1 in the vector vec is : "<<count(vec.begin(),vec.end(),1)<<endl<<endl;
    cout<<"vec after deleting the element at index 3: ";
    //erase automatically setup the vector after  deleting element of selected position
    vec.erase(vec.begin()+3);
    for(int i:vec)
    cout<<i<<" ";
    cout<<endl;

    cout<<"the distance between first element and max element    is  :"<<distance(vec.begin(),max_element(vec.begin(),vec.end()));
    cout<<endl;
    return 0;
}