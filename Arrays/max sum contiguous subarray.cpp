int Solution::maxSubArray(const vector<int> &A) {
    int maxYet, max_, plusOne;
    plusOne = maxYet = max_ = A[0];
    for (int i=1; i<A.size(); i++) {
        plusOne = maxYet + A[i];
        maxYet = max(A[i], plusOne);
        max_ = max(max_ , maxYet);
    }
    return max_;
}
