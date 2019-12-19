import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigDecimal a, b, ll, rr;
        ll = BigDecimal.valueOf(2);
        rr = BigDecimal.valueOf(3);
        for (int i = 0; i < 500; i++) {
            BigDecimal m = ll.add(rr).divide(BigDecimal.valueOf(2));
            if (m.multiply(m).compareTo(BigDecimal.valueOf(5)) < 0) {
                ll = m;
            } else {
                rr = m;
            }
        }

        BigDecimal p = ll.add(BigDecimal.ONE).divide(BigDecimal.valueOf(2));

        while (cin.hasNext()) {
            a = cin.nextBigDecimal();
            b = cin.nextBigDecimal();
            BigDecimal dif = a.subtract(b);
            dif = dif.abs();
            BigDecimal minn = a.min(b);
            if (minn.compareTo(p.multiply(dif).setScale(0, BigDecimal.ROUND_FLOOR)) == 0) {
                System.out.println(0);
            } else {
                System.out.println(1);
            }
        }
    }
}