#include<bits/stdc++.h>
using namespace std;
/*
Given an array A[] of size N and a positive integer K, 
find the first negative integer for each and every window(contiguous subarray) of size K.

using window slide concept
*/
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    deque<long long int> dq;    // to store -ve indexs
    vector<long long> ans;      // to store value of dq index
    
    for(int i=0;i<K;i++)        //searching in the first k size window
    {
        if(A[i]<0)
        dq.push_back(i);        //puttig the indexs of all -ve integers of first window in dq
    }
    
    if(dq.size()>0)             
        ans.push_back(A[dq.front()]);//putting the value of  first index or first -ve integer in window in the ans
    else
        ans.push_back(0);       //this indicates there is no -ve integer in current window , hence insert 0
                                // 0 to k-1 has solved
    for(int i=K;i<N;i++)        // solving for k to n-1 elements
    {    
        if(!dq.empty() && i-dq.front()>=K)      // removing the element which is not in window now
            dq.pop_front();         //popping  the previous index which not in the window
            
        if(A[i]<0)      //adding the new index in window if it's -ve
            dq.push_back(i);            //pushing -ve index of A[i] if it is -ve
            
        if(dq.size()>0)                     // there is -ve element index in dq
            ans.push_back(A[dq.front()]);   //storing the value at first index of dq in  ans
        else
            ans.push_back(0);   //size is zero it's indicates that there is no -ve element in current window
        
    }
    return ans;     //return the ans
 }