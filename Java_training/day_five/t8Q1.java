import java.util.*;
import java.util.LinkedList;

class t8Q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int op = sc.nextInt();
        Queue<String> q = new LinkedList<String>();
        for (int i = 0; i < op; i++) {
            String operation = sc.next();
            if (operation == "ENQUEUE") {
                String name = sc.next();
                if (q.size() == n) {
                    System.out.println("Queue is full. Cannot add " + name);
                    break;
                } else {
                    q.offer(name);
                }
            } else if (operation == "DEQUEUE") {
                if (q.isEmpty()) {
                    System.out.println("Queue underflow");
                    break;
                }
                System.out.println("Served Customer " + q.poll());
            } else if (operation == "DISPLAY") {
                Queue<String> temp = q;
                while (!temp.isEmpty()) {
                    System.out.print("Current Queue:" + temp.poll());
                }
            }
        }
    }
}
