vector<int> Solution::plusOne(vector<int> &A)
{   
    int e = A.size()-1;
    int carry = 0;
    if(A[e]<9)
        A[e] = A[e]+1;
    else if (A[e]==9)
    {
        A[e] = 0;
        carry = 1;
        for (int i=A.size()-2; i>=0; i--)
        {
            A[i]+=carry;
            if(A[i]==10)
            {
                A[i] = 0;
                carry = 1;    
            }
            else 
                carry = 0;
        }
        if(carry == 1)
            A.insert(A.begin(), 1);
    }
    while(A[0] == 0)
            A.erase (A.begin());
    return A;
}
