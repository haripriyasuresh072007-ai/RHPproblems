package RHPproblems;

public class longestcommonsubstring {

    public static String findLongestCommonSubstring(String s1, String s2) {
        if (s1 == null || s2 == null || s1.isEmpty() || s2.isEmpty()) {
            return "";
        }

        int m = s1.length();
        int n = s2.length();
        
        int[][] dp = new int[m + 1][n + 1];
        
        int maxLength = 0;
        int endIndexS1 = 0; 
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        endIndexS1 = i; 
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s1.substring(endIndexS1 - maxLength, endIndexS1);
    }

    public static void main(String[] args) {
        String s1 = "ABCDGH";
        String s2 = "ACDGHR";

        String resultStr = findLongestCommonSubstring(s1, s2);
        
        System.out.println("String 1: " + s1);
        System.out.println("String 2: " + s2);
        System.out.println("Longest Common Substring: \"" + resultStr + "\"");
        System.out.println("Length: " + resultStr.length());
    }
}


