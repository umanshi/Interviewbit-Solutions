int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n==0) return 0;
    int ans = 0;
    for (int i = 0; i<n; i++)
    {   map<float, int> sc;  // slope-count hashmap
        int horiz = 0; // To keep track of horizontal points with respect to ith point.
        int max_count = 0;  // To keep track of points with any slope other than infinity
        for(int j = 0;  j<n; j++)
        {   
            if(j==i) continue;  // We don't calculate slope between ith point and ith point, obviously.
            float n = A[i] - A[j];
            float d = B[i] - B[j];
            if(d==0)
            {
                horiz++;
                continue;
            }
            float s = n/d;
            if(sc.find(s) == sc.end())
              sc[s]=1;
            else 
              sc[s]++;
            if(sc[s] > max_count)
                max_count = sc[s];
        }
        max_count = max(max_count, horiz);
        ans = max(max_count, ans);
    }
    return ans+1;
}
