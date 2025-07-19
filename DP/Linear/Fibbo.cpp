class Solution
{
public:
    // recursion
    /*
     int rec(int n){
        if(n==0 || n==1) return n;

        return rec(n-1)+rec(n-2);
     }
     */
    /* Memo(Top Down)
     int rec(int n,vector<int> &dp){
       if(n==0 || n==1) return n;
       if(dp[n]!=-1){
           return dp[n];
       }
       return dp[n]=rec(n-1,dp)+rec(n-2,dp);
    }
    */
    /* Bottom Up(iterative)
      int rec(int n){
       vector<int> dp(n+1);
       if(n==0 || n==1) return n;
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
    }*/
    // space optimization
    int rec(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int a = 0;
        int b = 1;
        for (int i = 2; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    int fib(int n)
    {
        return rec(n);
    }
};