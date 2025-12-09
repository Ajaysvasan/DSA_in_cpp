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

    void insertValue(int data) {
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

    boolean deleteAtPosition(int pos) {
        // Check if list is empty
        if (head == null) {
            System.out.println("List is empty");
            return false;
        }

        // Check if position is out of range
        if (pos < 1 || pos > m_count) {
            System.out.println("Position out of range");
            return false;
        }

        // Delete at beginning (position 1)
        if (pos == 1) {
            head = head.next;
            m_count--;
            return true;
        }

        // Delete at middle or end
        Node temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp.next;
        }

        temp.next = temp.next.next;
        m_count--;
        return true;
    }

    void display() {
        if (head == null) {
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
        System.out.println();
    }
}

public class deleteAtPosition {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        LinkedList list = new LinkedList();

        for (int i = 0; i < n; i++) {
            list.insertValue(scanner.nextInt());
        }

        int pos = scanner.nextInt();

        boolean deleted = list.deleteAtPosition(pos);
        if (deleted) {
            list.display();
        }

        scanner.close();
    }
}
