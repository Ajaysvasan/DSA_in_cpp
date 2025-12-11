import java.util.*;

public class postclasst2 {
    public static void main(String[] args) {

        HashMap<Integer, String> mpp = new HashMap<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        HashSet<Integer> seen = new HashSet<>();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            String choice = sc.next();

            if (choice.equals("ENQUEUE")) {
                String name = sc.next();
                int priority = sc.nextInt();

                if (mpp.containsKey(priority)) {
                    mpp.put(priority, mpp.get(priority) + " " + name);
                } else {
                    mpp.put(priority, name);

                    if (!seen.contains(priority)) {
                        maxHeap.add(priority);
                        seen.add(priority);
                    }
                }
            }

            if (choice.equals("DEQUEUE")) {

                if (maxHeap.isEmpty()) {
                    System.out.println("EMPTY");
                    continue;
                }

                int priority = maxHeap.peek();
                String line = mpp.get(priority); // names at that priority
                String[] arr = line.split(" ");

                String removedName = arr[0]; // remove first name

                if (arr.length == 1) {
                    // No names left → remove entire priority
                    mpp.remove(priority);
                    maxHeap.poll(); // remove from heap
                    seen.remove(priority);
                } else {
                    // Rebuild remaining names
                    StringBuilder sb = new StringBuilder();
                    for (int j = 1; j < arr.length; j++) {
                        sb.append(arr[j]);
                        if (j != arr.length - 1)
                            sb.append(" ");
                    }
                    mpp.put(priority, sb.toString());
                }

                System.out.println("Dequeued: " + removedName);
            }

            // ---------------- DISPLAY ----------------
            if (choice.equals("DISPLAY")) {

                // Copy heap (so original not destroyed)
                PriorityQueue<Integer> temp = new PriorityQueue<>(maxHeap);

                while (!temp.isEmpty()) {
                    int priority = temp.poll();

                    if (!mpp.containsKey(priority))
                        continue;

                    String[] arr = mpp.get(priority).split(" ");
                    for (String person : arr) {
                        System.out.print(person + "(" + priority + ") ");
                    }
                }
                System.out.println();
            }
        }
    }
}
