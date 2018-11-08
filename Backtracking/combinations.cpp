void util (int A, int B, vector<int> temp, vector<vector<int > >& ans , int from_num)
{   if(temp.size()==B) 
    {   ans.push_back(temp);
        return;
    }
    for(int i=from_num; i<=A; i++)
    {   vector<int> temp1(temp);
        temp1.push_back(i);
        util(A, B, temp1, ans, i+1);
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> temp;
    vector<vector<int> > ans;
    util(A, B, temp, ans, 1);
    return ans;
}
