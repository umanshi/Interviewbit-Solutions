/*
 * Consider a directed graph whose vertices are numbered from 1 to n. 
 * There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i.
 * The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
 
Editorial :
Let n be 100 for example:
Since the task is to minimize number of edges, 
we would prefer to follow 3*i.  

Let us follow multiple of 3.

1 => 3 => 9 => 27 => 81, now we can't follow multiple
of 3. So we will have to follow i+1. This solution gives
a long path.

What if we begin from end, and we reduce by 1 if 
the value is not multiple of 3, else we divide by 3.
100 => 99 => 33 => 11 => 10 => 9 => 3 => 1

So we need total 7 edges.
 */
 
#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int count=0;
	    while(n!=1)
	    {
	        if(n%3==0)
	        {
	            count++;
	            n=n/3;
	        }
	        else
	        {
	            count++;
	            n-=1;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
