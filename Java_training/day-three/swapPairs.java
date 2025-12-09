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

    void insert(int data) {
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

    void swapPair() {
        Node slow = head;
        Node fast = head.next;
        while (fast.next != null) {
            fast.data ^= slow.data;
            slow.data ^= fast.data;
            fast.data ^= slow.data;
            if (slow.next.next != null) {
                slow = slow.next.next;
                fast = slow.next;
            } else {
                break;
            }
        }
    }

    void display() {
        if (head == null) {
            System.out.print("List is empty");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data);
            temp = temp.next;
        }
    }
}

public class swapPairs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        LinkedList list = new LinkedList();
        for (int i = 0; i < n; i++) {
            list.insert(sc.nextInt());
        }
        list.swapPair();
        list.display();
        sc.close();
    }
}
