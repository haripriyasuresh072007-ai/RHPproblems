package RHPproblems;

import java.util.*;
public class dpmaxval {
    public static void main(String[] args) {
        int R, C;
        long[][] mat;
        try (Scanner sc = new Scanner(System.in)) {
            R = sc.nextInt();
            C = sc.nextInt();

            mat = new long[R][C];
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    mat[i][j] = sc.nextLong();
        }

        long[][] dp = new long[R][C];

        System.arraycopy(mat[0], 0, dp[0], 0, C); 

        for (int i = 1; i < R; i++) {
            long[] fsmax = getFSMax(dp, i - 1, C);
            for (int j = 0; j < C; j++) {
                dp[i][j] = mat[i][j] + (dp[i-1][j] == fsmax[0] ? fsmax[1] : fsmax[0]);
            }
        }

        System.out.println(getFSMax(dp, R - 1, C)[0]);
    }

    private static long[] getFSMax(long[][] dp, int row, int col) {
        long fmax = Long.MIN_VALUE;
        long smax = Long.MIN_VALUE;
        for (int j = 0; j < col; j++) {
            if (dp[row][j] > fmax) {
                smax = fmax;
                fmax = dp[row][j];
            } else if (dp[row][j] > smax) {
                smax = dp[row][j];
            }
        }
        return new long[]{fmax, smax};
    }
}

