import java.util.Scanner;

public class largestNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        int temp;
        int result = 0;
        for (int i = 9; i >= 0; i--) {
            temp = input;
            while (temp != 0) {
                int lastDigit = temp % 10;
                if (lastDigit == i) {
                    result = (result * 10) + i;
                }
                temp = temp / 10;
            }
        }
        System.out.println(result);
    }
}
