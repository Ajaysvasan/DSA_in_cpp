import java.util.Scanner;

class Node {
    int data;
    Node next, prev;
}

class DoublyLinkedList {
    int m_count = 0;
    Node head, tail;

    DoublyLinkedList() {
        head = tail = null;
    }

    void insert(int data) {
        Node new_node = new Node();
        new_node.data = data;
        new_node.next = null;
        if (head == null) {
            head = tail = new_node;
            new_node.prev = null;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_node;
        new_node.prev = temp;
        tail = new_node;
    }

    void delete() {
        if (head == null || head.next == null) {
            head = null;
            System.out.print("List is empty");
            return;
        }
        tail = tail.prev;
        tail.next = null;
    }
}

public class removeFromEndDLL {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList dlist = new DoublyLinkedList();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            dlist.insert(sc.nextInt());
        }
        dlist.delete();
        sc.close();
    }
}
