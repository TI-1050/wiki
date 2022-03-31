import java.util.Scanner;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- != 0) {
            int n = in.nextInt();
            System.out.println(BigInteger.valueOf(2).pow(n));
        }
    }
}
