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

    void deleteFromKLast(int k) {
        if (k < 1 || k > m_count) {
            System.out.print("Position out of range");
        }
        if (k == 1) {
            if (head == null || head.next == null) {
                head = null;
                return;
            }
            Node temp = head;
            while (temp.next.next != null) {
                temp = temp.next;
            }
            temp.next = null;
            m_count--;
        } else if (k == m_count) {
            if (head == null || head.next == null) {
                head = null;
                return;
            }
            head = head.next;
            m_count--;
        } else {
            int new_value = m_count - k;
            Node temp = head;
            for (int i = 1; i < new_value; i++) {
                temp = temp.next;
            }
            temp.next = temp.next.next;
        }
    }

    void display() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

public class removeFromEnd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            list.insertValue(sc.nextInt());
        }
        list.deleteFromKLast(sc.nextInt());
        sc.close();

    }
}
