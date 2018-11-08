/*

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
Make sure the combinations are sorted.
To elaborate,
    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

*/

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
