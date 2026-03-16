import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;
}

class DoublyLinkedList {
    Node head, tail;
    int m_count = 0;

    DoublyLinkedList() {
        head = tail = null;
    }

    void insert(int data) {
        Node new_node = new Node();
        new_node.data = data;
        new_node.next = null;
        new_node.prev = null;
        m_count++;
        if (head == null) {
            head = new_node;
            new_node.prev = head;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_node;
        new_node.prev = temp;
    }

    void display() {
        if (head == null) {
            System.out.print("List is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}

public class doublyLinkedList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DoublyLinkedList dlist = new DoublyLinkedList();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            dlist.insert(sc.nextInt());
        }
        dlist.display();
        sc.close();
    }
}
