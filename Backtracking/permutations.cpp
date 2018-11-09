void swap(vector<int>& A, int c, int i)
{
    int temp = A[c];
    A[c] = A[i];
    A[i] = temp;
}
void util(vector<int> A, vector<vector<int> >& ans, int c)
{
    if(c==A.size())
    {
        ans.push_back(A);
        return;
    }
    for(int i=c; i<A.size(); i++)
    {
        swap(A, c, i);
        util(A, ans, c+1);
        swap(A, i, c);
    }  
}
vector<vector<int> > Solution::permute(vector<int> &A) 
{
    vector<vector<int> > ans;
    util(A, ans, 0);
    return ans;
}
