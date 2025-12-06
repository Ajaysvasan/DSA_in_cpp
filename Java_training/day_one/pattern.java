import java.util.Scanner;

public class pattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int input = sc.nextInt();
        int number = 0;
        for (int i = 1; i <= input; i++) {

            if (i % 2 == 0) {
                for (int j = 0; j < i; j++) {
                    number++;
                    if (j == i) {
                        System.out.print(number);
                    } else {
                        System.out.print(number + "*");
                    }
                }
            }

            else {
                int temp = number + i;
                number = temp;
                for (int j = 0; j < i; j++) {
                    System.out.print((temp - j) + "*");
                }
            }

            System.out.println();
        }

        sc.close();
    }
}
