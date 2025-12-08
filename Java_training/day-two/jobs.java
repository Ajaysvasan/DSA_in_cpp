import java.util.Scanner;

class Node {
    int data;
    Node next;
}

class LinkedList {
    int m_count = 0;
    Node head;

    LinkedList() {
        head = null;
    }

    void insertData(int data) {
        Node new_node = new Node();
        new_node.data = data;
        new_node.next = null;
        m_count++;
        if (head == null) {
            head = new_node;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_node;
    }

    void deleteFromEnd() {
        if (head == null) {
            return;
        }
        if (head.next == null) {
            head = null;
            m_count--;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
        m_count--;
    }

    void read() {
        if (head == null) {
            System.out.print("List is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data);
            if (temp.next != null) {
                System.out.print(" ");
            }
            temp = temp.next;
        }
    }
}

public class jobs {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int data = scanner.nextInt();
            list.insertData(data);
        }
        int m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            list.deleteFromEnd();
        }
        list.read();
        scanner.close();
    }
}
