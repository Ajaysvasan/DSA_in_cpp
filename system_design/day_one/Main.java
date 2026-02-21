import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        vending_machine machine = new vending_machine();
        machine.add(true);
        String choice = sc.nextLine();
        while (choice != "exit") {
            machine.get_products();
        }
        sc.close();
    }
}
