int Solution::canJump(vector<int> &A) {
    int n = A.size(); if(n==1) return 1;
    int p[n]; // p means possible, p[i] means possible from i
    for(int i=0; i<n; i++) p[i] = 0;
    p[n-1] = 1;
    for(int i=n-2; i>=0; i--)
    {   if(A[i]!=0)
        {
            if(n-1-i<=A[i])
                p[i] = 1;
            else
            {   
                for(int j=i+1; j<=i+A[i]; j++)
                {
                    if(p[j]==1)
                    {   
                        p[i] = 1;
                        break;
                    }    
                }
            }
        }
    }
    return p[0];
}
