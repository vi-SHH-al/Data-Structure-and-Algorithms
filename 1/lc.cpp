#include<iostream>
using namespace std;
int main()
{
    int a[11]={1,2,3,4,5,7,2,1,4,5,3};
    
    for(int i=0;i<11;i++)
    {int flag = 0;
        for(int j=0;j<11;j++)
      { if(i==j)
        continue;
         if(a[i]==a[j])
        {
            flag=0;
            break;
          }
        else 
        flag=1;
      }
      if(flag==1)
      cout<<a[i]<<endl;
    }

    return 0;
}