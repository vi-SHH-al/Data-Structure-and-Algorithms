/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/

#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
      int deficit=0;
      int balance=0;
      int start=0;
      
      for(int i=0;i<n;i++)
      {
           balance += p[i].petrol - p[i].distance;
           
           if(balance<0)
           {
               deficit += balance;
               start= i+1;
               balance=0;
           }
      }
           if(deficit + balance >=0)
           return start;
           else
           return -1;
      
      
    }
};
