public class halloSum {
    public static void main(String[] args) {
        int n = 4;
        int matrix[][] = new int[n][n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    sum += matrix[i][j];
                }
            }
        }
    }
}
