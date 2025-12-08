import java.util.Scanner;

class Node {
    int data;
    Node next;
}

class LinkedList {
    private Node head;
    private int m_count = 0;

    public LinkedList() {
        head = null;
    }

    public void insertValue(int data) {
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

    public void read() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public void reverse() {
        Node next = null;
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, data;
        LinkedList list = new LinkedList();
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            data = scanner.nextInt();
            list.insertValue(data);
        }
        list.reverse();
        list.read();
        scanner.close();
    }
}
