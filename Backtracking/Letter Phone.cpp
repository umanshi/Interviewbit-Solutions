void util (vector<string> allStrings, vector<string> &ans, string temp, int c)
{   // In this function we are trying to fill the cth place in the ans
    // by picking the cth string -> allStrings[c] and filling up the cth location of temp
    // from all values that can be obtained using the cth string. 
    if(c==allStrings.size())
    {   ans.push_back(temp);
        return;
    }
    for(int i=0; i<allStrings[c].length(); i++) // From 0th when c = 0
    {   
        temp+=allStrings[c][i]; // Take from i
        util(allStrings, ans, temp, c+1); // Go ahead with the i you just picked,
        // Look for the next location--> build a future with 
        // the i you chose
        temp = temp.substr(0, temp.length()-1); // After exploring all the possibilities 
        //and learing  how life would be if you chose i, backtrack to the original string 
        //where there was no i so that you can start life afresh with the next i 
        // (by the virtue of the for loop you're in :) 
    }
}
vector<string> Solution::letterCombinations(string A) {
    map<int, string> m;
    m[2]="abc"; m[3]="def"; m[4] = "ghi"; m[5] = "jkl";
    m[6]="mno"; m[7]="pqrs"; m[8] = "tuv"; m[9] = "wxyz";
    m[0] = "0"; m[1] = "1";
    
    vector<string> allStrings;
    for(int i=0; i<A.length(); i++)
    {
        allStrings.push_back(m[A[i]-'0']);
    }
    vector<string> ans;
    string temp = "";
    util(allStrings, ans, temp, 0);
    return ans;
}
