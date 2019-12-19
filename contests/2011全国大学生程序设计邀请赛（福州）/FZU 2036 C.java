import java.io.*;
import java.math.*;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int cas = 1; cas <= t; cas++) {
            BigDecimal a = cin.nextBigDecimal(), b = cin.nextBigDecimal();
            BigDecimal big = a, small = b;
            BigDecimal ans;
            if (a.compareTo(b) < 0) {
                small = a;
                big = b;
            }
            BigDecimal delta = big.subtract(small);
            if (delta.compareTo(BigDecimal.valueOf(35)) > 0) {
                ans = big;
            } else {
                double tmp = Math.log(Math.pow(2.0, delta.doubleValue()) + 1)/Math.log(2.0);
                ans = small.add(BigDecimal.valueOf(tmp));
            }
            System.out.println("Case " + cas + ": " + ans.setScale(9, BigDecimal.ROUND_HALF_UP));
        }
    }
}