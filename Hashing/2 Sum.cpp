vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int, int> m;
    int s = -1, e=-1;
    for(int i=0; i<A.size(); i++){ 
        if(m.find(A[i])!=m.end()){
            s = m[A[i]];
            e = i;
            break;
        }
        else if (m.find(B-A[i]) == m.end())
            m[B-A[i]] = i;
    }
    vector<int> ans;
    if(s!=-1){
        ans.push_back(s+1);
        ans.push_back(e+1);
    }
    return ans;
}
