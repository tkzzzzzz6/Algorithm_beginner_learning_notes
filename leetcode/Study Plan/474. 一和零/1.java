class Solution{
    public int findMaxForm(String[] strs,int m,int n){
        int k = strs.length;
        int[] cnt0 = new int[k];
        for(int i =0;i<k;++i){
            cnt0[i] = (int)strs[i].chars().filter(ch->ch == '0').count();
        }

        int[][][] dp = new int[strs.length][m+1][n+1];
        for(int[][] mat:dp){
            for(int[] arr:mat){
                Arrays.fill(arr,-1);
            }
        }
        return dfs(k-1,m,n,strs,cnt0,dp);
    }

    private int dfs(int i,int m,int n,String[] strs,int[] cnt0,int[][][] dp){
        if(i<0){
            return 0;
        }
        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }
        int res = dfs(i-1,m,n,strs,cnt0,dp);
        int cnt1 = strs[i].length()-cnt0[i];
        if(m>=cnt0[i] && n>=cnt1){
            res = Math.max(res,1+dfs(i-1,m-cnt0[i],n-cnt1,strs,cnt0,dp));
        }
        return dp[i][m][n] = res;
    }

}
