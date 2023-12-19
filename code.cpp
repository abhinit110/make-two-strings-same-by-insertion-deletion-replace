class Solution {
public:
    // int distance(string w1,string w2,int i,int j)
    // {
    //     if(i<=0||j<=0)
    //     {
    //         if(i>0)
    //         return i;
    //         else if(j>0)
    //         return j;
    //         else
    //         return 0;
    //     }
        
    //     if(w1[i-1]==w2[j-1])
    //     {
    //         return distance(w1,w2,i-1,j-1);
    //     }
    //     else
    //     {
    //         return min(1+distance(w1,w2,i-1,j),1+distance(w1,w2,i-1,j-1));
    //     }
    // }
    int minDistance(string w1, string w2) {
        int n=w1.length();
        int m=w2.length();
        // int res=distance(w1,w2,n,m);
        // return res;
        int dp[n+1][m+1];
        for(int i=0;i<m+1;i++)
        dp[0][i]=i;
        for(int i=0;i<n+1;i++)
        dp[i][0]=i;
        // dp[0][0]=INT_MAX;
        // if(w1[0]==w2[0])
        // dp[0][0]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(w1[i-1]==w2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=min(1+dp[i-1][j],min(1+dp[i-1][j-1],1+dp[i][j-1]));
            }
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n][m];

    }
};
