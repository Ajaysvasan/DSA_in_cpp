import java.util.*;

public class converting {
    public static void main(String[] args) {
        Queue<Integer> q = new PriorityQueue<>();// min heap
        q.offer(10);
        q.offer(4);
        q.offer(0);
        q.offer(11);

        ArrayList<Integer> a = new ArrayList<>(q);

        while (!q.isEmpty()) {
            System.out.print(q.peek() + " ");
            q.poll();
        }

        System.out.println();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());// max heap
        pq.offer(10);
        pq.offer(4);
        pq.offer(0);
        pq.offer(11);

        while (!pq.isEmpty()) {
            System.out.print(pq.peek() + " ");
            pq.poll();
        }

        System.out.println();
    }
}
