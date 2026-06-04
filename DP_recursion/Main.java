public class Main {

    public static int longestCommonStringTab(String s1, String s2) {
        // In Java, a 2D array is automatically initialized with 0s
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        int maxLen = 0;

        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                // Use charAt() instead of array indexing [] for Strings in Java
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLen = Math.max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return maxLen;
    }

    // A quick test to verify it works
    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "abfce";
        System.out.println(longestCommonStringTab(s1, s2)); // Output: 2
    }
}
