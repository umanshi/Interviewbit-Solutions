vector<int> Solution::equal(vector<int> &A) {
    map<int, vector<int> > m;
    int sum;
    vector<int> ans(4,INT_MAX);
    
    for(int i=0; i<A.size(); i++){
        for(int j=i+1; j<A.size(); j++){
            sum = A[i] + A[j];
            if(m.find(sum) == m.end()){ // Not found
                m[sum].push_back(i);
                m[sum].push_back(j); 
            }
            else if(m[sum][0]!=i && m[sum][1]!=j && m[sum][1]!=i){ // found
                vector<int> temp_ans;
                temp_ans.push_back(m[sum][0]);
                temp_ans.push_back(m[sum][1]);
                temp_ans.push_back(i);
                temp_ans.push_back(j);
                
                if(temp_ans[0]<ans[0]){ //cout<<"Case 1"<<endl;
                    ans.swap(temp_ans); 
                }
                else if(temp_ans[0]==ans[0]){ //cout<<"Case 2"<<endl;
                    if(temp_ans[1]<ans[1]){
                        ans.swap(temp_ans);
                    }
                    else if(temp_ans[1]==ans[1]){ //cout<<"Case 3"<<endl;
                        if(temp_ans[2]<ans[2]){
                            ans.swap(temp_ans);
                        }  
                        else if(temp_ans[2]==ans[2]){ //cout<<"Case 4"<<endl;
                            if(temp_ans[3]<ans[3]){
                                ans.swap(temp_ans);
                            }  
                        }
                    }
                }    
            }
        }
    }

    if(ans[0]!=-1)
        return ans;
    vector<int> a;
    return a;
}
