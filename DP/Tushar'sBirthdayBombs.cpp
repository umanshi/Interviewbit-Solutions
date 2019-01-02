vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size(); 
    vector<int> ans;
    vector<pair<int, int> > vec;
    for(int i=0; i<n; i++)
    {
        vec.push_back(make_pair(B[i], i));
    }
    sort(vec.begin(), vec.end());
    int min_val = vec[0].first;
    int d = A/min_val; 
    int index = vec[0].second;
    //Find suitable candidates for the solution
    // If an element is greater than the one on its left, it wont't be taken
    // I would rather take the left element // I put all of them in newB
    vector<pair<int,int> > newB;
    newB.push_back(make_pair(B[0], 0));
    for(int i=1; i<n; i++)
    {
        if(B[i]<B[i-1])
        {
            newB.push_back(make_pair(B[i], i));
        }
    }int i=0; 
    n = newB.size();
    while( i<n)
    {
        if( A>=newB[i].first && ((A-newB[i].first)/min_val == ((A/min_val)-1))  )
        {
            ans.push_back(newB[i].second);
            A-=newB[i].first;
        }
        else
            i++;
    }
    return ans;
}
