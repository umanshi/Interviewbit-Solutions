/*
Dynamic Programming

QUESTION> 1.  Longest Increasing Subsequence

Given a sequence, find the length of the longest increasing subsequence from a given sequence .
<This subsequence is not necessarily contiguous, or unique>
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {  int T;  cin>>T;
    while(T--)
    {
     int max = 1; int s; cin>>s;
     if(s==0)
     {   cout<<s<<endl;
         continue;
     }
     int arr[s];
     int L[s];
     for (int i=0; i<s; i++)
     {   L[i] = 1;
         cin>>arr[i];
     }   
     for (int i=1; i<s; i++)
     {   for(int j = 0; j<i; j++)
         {   if ( (arr[i]>arr[j]) && (L[j]+1 > L[i]))
                    L[i] = L[j] + 1;
                    
             if (L[i]>max)
                    max = L[i];
         }       
     }
     cout<< max<<endl;
    }
	return 0;
}

