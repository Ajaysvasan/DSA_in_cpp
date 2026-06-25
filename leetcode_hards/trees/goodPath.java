package leetcode_hards.trees;

import java.util.*;

public class goodPath {

    static int n;
    static int[] value;
    static List<Integer>[] graph;
    static long answer = 0;

    static void dfs(int node, int parent, int mask) {

        // Toggle parity of current node value
        mask ^= (1 << value[node]);

        // Good path:
        // all even OR exactly one odd
        if (Integer.bitCount(mask) <= 1) {
            answer++;
        }

        for (int neighbour : graph[node]) {

            if (neighbour == parent)
                continue;

            dfs(neighbour, node, mask);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        value = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            value[i] = sc.nextInt();
        }

        graph = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {

            int u = sc.nextInt();
            int v = sc.nextInt();

            graph[u].add(v);
            graph[v].add(u);
        }

        dfs(1, -1, 0);

        System.out.println(answer);

        sc.close();
    }
}
