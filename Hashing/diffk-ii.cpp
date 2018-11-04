int Solution::diffPossible(const vector<int> &A, int B) {
    map<int, int> m;
    for(int i=0; i<A.size(); i++){
        if (m.find(A[i]) != m.end()  )
            return 1;
        else { 
            m[A[i]-B] = 0; // The difference b/w the two numbers must be B, so the 
            m[A[i]+B] = 0; // number can be B greater than A[i] or B less than A[i].
        }
    }
    return 0;
}
