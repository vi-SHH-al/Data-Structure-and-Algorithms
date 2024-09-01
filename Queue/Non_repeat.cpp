/*
Given an input stream of A of n characters consisting only of lower case alphabets.
 The task is to find the first non repeating character, 
 each time a character is inserted to the stream. 
If there is no such character then append '#' to the answer.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
		string FirstNonRepeating(string A){
		   unordered_map<char,int> count;   // map for counting the occurence of characers
		   queue<int> q;
		   string ans="";
		   for(int i=0;i<A.length();i++)
		   {
		       char ch=A[i];
		       
		       count[ch]++;
		       
		       q.push(ch);
		       
		       while(!q.empty())
		       {
		           if(count[q.front()]>1)   // repeating charcters 
		                q.pop();
		           else
		              {     // non repeating characters found
		                  ans.push_back(q.front());
		                  break;
		              }
		       }
		       if(q.empty())    // this will happen only if q is empty that means 
		            ans.push_back('#');//there is only repeating charcters for stream till now
		   }
		   return ans;
		}

};