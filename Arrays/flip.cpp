vector<int> Solution::flip(string A) {
    vector<int> ans;
    int L = -1, R = -1;
    int Lcan = 0; // L candidate
    int maxSum = 0;
    int curSum = 0;
    vector<int> A_(A.size());
    for (int i=0; i<A.size(); i++) 
        A_[i] = (A[i]=='1')?(-1):1;
    for (int i=0; i<A.size(); i++) {
        if (curSum+A_[i]>=0) curSum += A_[i];
        else                 Lcan = i+1;

        if (curSum > maxSum) {
            R = i;
            L = Lcan;
            maxSum = curSum;
        }
    }
    if (L == -1)
        return ans;
    ans.push_back(L+1);
    ans.push_back(R+1);
    return ans;
} /* Kadane's Algorithm */
