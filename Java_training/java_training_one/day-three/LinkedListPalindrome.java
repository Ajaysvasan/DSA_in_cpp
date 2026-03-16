import java.util.Scanner;

class Node {
    int data;
    Node next, prev;
}

class LinkedList {
    int m_count = 0;
    Node head, tail;

    LinkedList() {
        head = null;
        tail = null;
    }

    void insert(int data) {
        Node new_node = new Node();
        new_node.data = data;
        new_node.next = null;
        m_count++;
        if (head == null) {
            new_node.prev = null;
            head = new_node;
            tail = new_node;
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

    boolean palindrom() {
        Node left = head;
        Node right = tail;
        while (left != right) {
            if (left.data != right.data) {
                return false;
            }
            left = left.next;
            right = right.prev;
        }
        return true;

    }
}

class LinkedListPalindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            list.insert(sc.nextInt());
        }
        if (list.palindrom()) {
            System.out.print("Yes");
        } else {
            System.out.println("No");
        }
    }
}
