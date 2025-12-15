import java.util.*;

class Node {
    int data;
    Node right;
    Node left;

    Node(int val) {
        this.data = val;
        this.left = this.right = null;
    }
}

class BinaryTree {
    Node root;

    BinaryTree() {
        root = null;
    }

    Node insertData(int data, Node root) {
        if (root == null) {
            return new Node(data);
        }
        if (data < root.data) {
            root.left = insertData(data, root.left);
        } else if (data > root.data) {
            root.right = insertData(data, root.right);
        }
        return root;
    }

    void DFS(Node node) {
        if (node == null)
            return;
        DFS(node.left);
        System.out.print(node.data + " ");
        DFS(node.right);
    }

    Node getSuccessor(Node curr) {
        while (curr != null && curr.left != null) {
            curr = curr.left;
        }
        return curr;
    }

    Node deleteNode(Node root, int target) {
        if (root == null)
            return null;
        if (target < root.data) {
            root.left = deleteNode(root.left, target);
        } else if (target > root.data) {
            root.right = deleteNode(root.right, target);
        } else {
            if (root.right == null)
                return root.left;
            if (root.left == null)
                return root.right;
            Node curr = getSuccessor(root.right);
            root.data = curr.data;
            root.right = deleteNode(root.right, curr.data);
        }
        return root;
    }

    void search(Node root, int target) {
        if (root == null) {
            System.out.println("Book is not found");
            return;
        }
        if (target < root.data) {
            search(root.left, target);
        } else if (target > root.data) {
            search(root.right, target);
        } else if (target == root.data) {
            System.out.println("Book found! Subtree rooted at:" + root.data);
            DFS(root);
            return;
        }
    }
}

public class trees {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        BinaryTree tree = new BinaryTree();
        for (int i = 0; i < n; i++)
            tree.root = tree.insertData(sc.nextInt(), tree.root);
        System.out.println("Data inserted");
        tree.DFS(tree.root);
        System.out.println("The values in the trees are printed");
        tree.search(tree.root, sc.nextInt());
        System.out.println("Deletion");
        tree.deleteNode(tree.root, sc.nextInt());
        System.out.println("After deletion");
        tree.DFS(tree.root);
        sc.close();
    }
}
