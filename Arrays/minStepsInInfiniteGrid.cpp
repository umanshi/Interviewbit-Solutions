int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int x1, y1;
    int x0 = A[0];
    int y0 = B[0];
    int ans = 0;
    for (int i=1; i<A.size(); i++) {
        x1 = A[i];
        y1 = B[i];
        ans += max(abs(x1-x0), abs(y1-y0));
        x0 = x1;
        y0 = y1;
    }
    return ans;
}
