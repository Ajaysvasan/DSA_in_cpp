import java.util.Scanner;

public class singledigit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int digit = sc.nextInt();
        int result = 0;
        if (digit % 2 == 0) {
            System.out.println("Even");
            while (digit != 0 || result / 10 != 0) {
                if (digit != 0) {
                    int lastDigit = digit % 10;
                    result += lastDigit;
                    digit = digit / 10;
                } else if (result != 0) {
                    digit = result;
                    result = 0;
                }
            }
        } else {
            System.out.println("Odd");
            result = 1;
            while (digit != 0 || result / 10 != 0) {
                if (digit != 0) {
                    int lastDigit = digit % 10;
                    result *= lastDigit;
                    digit = digit / 10;
                } else if (result != 0) {
                    digit = result;
                    result = 1;
                }
            }

        }
        System.out.println(result);
    }
}
