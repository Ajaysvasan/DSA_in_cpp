import java.util.*;
import java.util.LinkedList;

class Node {
    int data;
    // stores the address of the children
    ArrayList<Node> children;

    Node(int data) {
        this.data = data;
        children = new ArrayList<>();
    }
}

public class narytree {
    static void levelOrderTraversal(Node root) {
        if (root == null)
            return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node curr = q.poll();
            System.out.print(curr.data + " ");
            for (Node node : curr.children) {
                q.add(node);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = new Node(sc.nextInt());
        for (int i = 1; i < n; i++) {
            root.children.add(new Node(sc.nextInt()));
        }
        // to access the elements we use root.children.get(index_value).data; since
        // root.children.get(index_value) points to the
        // address of the node we need .data to get the actual value
        levelOrderTraversal(root);
        sc.close();
    }
}
