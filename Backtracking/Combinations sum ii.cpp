bool similar(vector<int> A, vector<int> B)
{
    if(A.size()!=B.size())
        return false;
    for(int i=0; i<A.size(); i++)
    {   if(A[i]!=B[i])
            return false;
    }
    return true;
}
void util(vector<int> A, int B, vector<int>& temp, vector<vector<int> > &ans, int i)
{   
    if(B==0)
    {   if(ans.size()==0)
        {   ans.push_back(temp);
            return;
        }
        else if(!similar(temp, ans[ans.size()-1]))
        {   ans.push_back(temp);
            return;
        }
    }
    if(i==A.size() || B<0 )
        return;
    temp.push_back(A[i]);
    util(A, B-A[i], temp, ans, i+1);
    temp.pop_back();
    util(A, B, temp, ans, i+1);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    vector<int> temp;
    util(A, B, temp, ans, 0);
    return ans;
}
