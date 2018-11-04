vector<int> Solution::lszero(vector<int> &A){
    vector<int> prefix_sum(A.size(), 0);
    
    prefix_sum[0] = A[0];   // Form the prefix sum array
    for(int i=1; i<A.size(); i++)
        prefix_sum[i] = prefix_sum[i-1]+A[i];
        
    map<int, int> m;
    int temp_start, temp_end, start=0, end=0;
    
    for(int i=0; i<A.size(); i++){   
        if(prefix_sum[i] == 0){   
            temp_start = -1; // Because we'll start counting from start+1 and you want that to be 0
            temp_end = i;
            if(temp_end - temp_start> end - start){
                start = temp_start;
                end = temp_end;
            }
        }
        else if(m.find(prefix_sum[i]) == m.end()) // Not found in the prefix array
                m[prefix_sum[i]] = i;
        
        else if(m.find(prefix_sum[i]) != m.end()){ // Found earlier in the array as well   
            temp_start = m[prefix_sum[i]];
            temp_end = i;
            if(temp_end-temp_start > end-start){   
                start = temp_start;
                end = temp_end;
            }
        }
    }
    vector<int> ans;
    for (int i = start+1; i<=end; i++)
        ans.push_back(A[i]);
    return ans;
}
