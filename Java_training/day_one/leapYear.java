import java.util.Scanner;

public class leapYear {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int month = sc.nextInt();
        if (year >= 1600 && year <= 2099 && month <= 12 && month > 0) {
            if (year == 1752 && month == 9) {
                System.out.println(19);
            }
            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        if (month == 2) {
                            System.out.println(29);
                        }
                    }
                } else {
                    if (month == 2) {
                        System.out.println(29);
                    }
                }
            } else {
                if (month == 2) {
                    System.out.println(29);
                }
            }
            if (month % 2 == 0 && month != 2 && month < 8) {
                System.out.println(30);
            } else if (month >= 8) {
                if (month % 2 == 0) {
                    System.out.print(31);
                } else {
                    System.out.println(30);
                }
            }

        } else {
            System.out.println("Not a valid input");
        }
        sc.close();

    }
}
