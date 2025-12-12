import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class BinaryNode {
    Node root;

    BinaryNode() {
        root = null;
    }

    Node insertData(int data, Node root) {
        if (root == null) {
            return new Node(data);
        }

        if (data < root.data)
            root.left = insertData(data, root.left);
        else if (data > root.data)
            root.right = insertData(data, root.right);

        return root;
    }

    void BFS(Node root, int level, ArrayList<ArrayList<Integer>> arr) {
        if (root == null) {
            return;
        }
        if (arr.size() <= level) {
            arr.add(new ArrayList<>());
        }
        arr.get(level).add(root.data);
        BFS(root.left, level + 1, arr);
        BFS(root.right, level + 1, arr);
    }

    ArrayList<ArrayList<Integer>> levelOrder(Node root) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        BFS(root, 0, res);
        return res;
    }

    void DFS(Node root) {
        if (root == null)
            return;

        DFS(root.left);
        System.out.print(root.data + " ");
        DFS(root.right);
    }
}

public class binarySearchTree {
    public static void main(String[] args) {
        BinaryNode tree = new BinaryNode();

        int n = 10;
        for (int i = 0; i < n; i++) {
            tree.root = tree.insertData(i, tree.root);
        }
        System.out.print("DFS: ");

        tree.DFS(tree.root);
        System.out.println();
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        res = tree.levelOrder(tree.root);
        System.out.print("BFS: ");
        for (ArrayList<Integer> level : res) {
            for (int val : level) {
                System.out.print(val + " ");
            }
        }
    }
}
