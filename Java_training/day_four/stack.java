import java.util.*;

public class stack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine().trim());
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < N; i++) {
            String choice = sc.next();
            if (choice.equals("Push")) {
                st.push(sc.nextInt());

            } else if (choice.equals("Pop")) {
                if (st.empty()) {
                    System.out.println("Stack Underflow");
                } else {
                    st.pop();
                }
            } else if (choice.equals("Top")) {
                if (st.empty()) {
                    System.out.println("Stack Underflow");
                } else
                    System.out.println(st.peek());
            } else if (choice.equals("IsEmpty")) {
                System.out.println(st.empty());
            } else if (choice.equals("Size")) {
                System.out.println(st.size());
            }

        }
        sc.close();
    }
}
