import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    private Node head;
    private Node tail;
    private int m_count = 0;

    public CircularLinkedList() {
        head = null;
        tail = null;
    }

    public void insertData(int data) {
        Node new_node = new Node(data);
        m_count++;
        if (head == null) {
            head = new_node;
            tail = new_node;
            new_node.next = new_node;
        } else {
            new_node.next = head;
            tail.next = new_node;
            tail = new_node;
        }
    }

    public void middleTask() {
        Node temp = head;
        int middle_value = m_count / 2;
        for (int i = 0; i < middle_value; i++) {
            head = head.next;
            m_count--;
        }
        // System.out.print(temp.data);

    }

    public void read() {
        Node temp = head;
        for (int i = 0; i < m_count; i++) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

public class circularLinkedList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, data;
        CircularLinkedList clist = new CircularLinkedList();
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            data = scanner.nextInt();
            clist.insertData(data);
        }
        clist.middleTask();
        clist.read();
        scanner.close();
    }
}
