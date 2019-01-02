int Solution::jump(vector<int> &A) {
    int n = A.size();
    int jumps, min_jumps, dp_jumps[n];
    dp_jumps[n-1] = 0;
    for (int i=n-2; i>=0; i--)
    {   min_jumps = INT_MAX; 
        if(A[i] == 0)
            min_jumps = INT_MAX;
        else if(A[i] >= n-1-i)
            min_jumps = 1;
        else
        {   for(int j = i+1; j<=i+A[i] && (j<=n-1); j++) 
            {   
                if(dp_jumps[j]!=INT_MAX) jumps = 1+dp_jumps[j];
                else jumps = dp_jumps[j];
                
                if(jumps<min_jumps) 
                    min_jumps = jumps;
            }
        }
        dp_jumps[i] = min_jumps;
    }
    if(dp_jumps[0]==INT_MAX) return -1;
    return dp_jumps[0];
}
