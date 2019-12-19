import java.math.*;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int t = cin.nextInt();
        while (t-- > 0) {
            int n = cin.nextInt();
            BigDecimal ans = new BigDecimal(2).pow(n);
            System.out.println(ans);
        }
    }
}