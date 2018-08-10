import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static int n, k, i, j, val;
    static BigInteger[][] f = new BigInteger[2005][15];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        k = in.nextInt();
        for (i = 1; i <= n; i++) {
            for (j = 0; j < k; j++) f[i][j] = BigInteger.valueOf(0);
        }
        for (i = 1; i < k; i++) f[1][i] = BigInteger.valueOf(1);
        for (i = 2; i <= n; i++) {
            for (j = 0; j < k; j++) {
                if (j > 0) {
                    for (val = 0; val < k; val++) f[i][j] = f[i][j].add(f[i-1][val]);
                } else {
                    for (val = 1; val < k; val++) f[i][j] = f[i][j].add(f[i-1][val]);
                }
            }
        }        
        BigInteger ans = BigInteger.valueOf(0);
        for (i = 0; i < k; i++) ans = ans.add(f[n][i]);
        System.out.println(ans);
    }
}