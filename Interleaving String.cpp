class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len_s1 = s1.size();
        int len_s2 = s2.size();
        int len_s3 = s3.size();
        
        if (len_s3 != len_s1 + len_s2) return false;
        
        bool dp[len_s1+1][len_s2+1] = {0};
        
        for (int i = 0; i < len_s1 + 1; i++)
        {
            for (int j = 0; j < len_s2 + 1; j++)
            {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] & (s2[j-1] == s3[i+j-1]);
                else if (j == 0)
                    dp[i][j] = dp[i-1][j] & (s1[i-1] == s3[i+j-1]);
                else
                    dp[i][j] = (dp[i-1][j] & (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] & (s2[j-1] == s3[i+j-1]));
            }
        }
        
        return dp[len_s1][len_s2];
    }
};