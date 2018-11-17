string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    bool mat[A+1][B+1];
    for(int i=0; i<=A; i++)
    {   for(int j=0; j<=B; j++)
        {   mat[i][j] = false; 
            for(int p=0; p<C; p++)
            {
                float dist = sqrt((float)pow((E[p]-i), 2)+(float)pow((F[p]-j), 2));
                if(dist <=(float)D )
                    mat[i][j] = true; 
            }
        }
    }
    if(mat[A][B] == true || mat[0][0]==true)
        return "NO";
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    int move_x[] = {1,-1, 0, 0, 1, 1,-1,-1};
    int move_y[] = {0, 0, 1,-1, 1,-1, 1,-1};
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first; int y = p.second;
        if(x==A && y==B)
            return "YES";
        for(int m = 0; m<8; m++)
        {   
            int new_x = x+move_x[m]; int new_y = y+move_y[m];
            if(mat[new_x][new_y]==false && new_x<=A && new_x>=0 && new_y>=0 && new_y<=B)
            {
                q.push(make_pair(new_x,new_y));
                mat[new_x][new_y] = true;
            }
        }
    }
    return "NO";
}
