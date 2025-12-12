import java.util.*;

class Patient implements Comparable<Patient> {
    String name;
    int severity;

    public Patient(String name, int severity) {
        this.name = name;
        this.severity = severity;
    }

    @Override
    public int compareTo(Patient obj) {
        return Integer.compare(obj.severity, this.severity);
    }

    @Override
    public String toString() {
        return name + " " + severity;
    }
}

public class Main {
    static PriorityQueue<Patient> pq = new PriorityQueue<>();

    public static void enqueue(String name, int severity) {
        pq.add(new Patient(name, severity));
    }

    public static void dequeue() {
        if (pq.isEmpty()) {
            System.out.println("Treated Patient: Queue is empty. No patient to treat.");
        } else {
            Patient p = pq.poll();
            System.out.println("Treated Patient: " + p.name + " " + p.severity);
        }
    }

    public static void display() {
        if (pq.isEmpty()) {
            System.out.println("Queue is empty.");
        } else {
            System.out.print("Current Queue: ");
            List<Patient> temp = new ArrayList<>(pq);
            for (int i = 0; i < temp.size(); i++) {
                System.out.print(temp.get(i));
                if (i < temp.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println(" ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine().trim();
            String[] parts = line.split(" ");
            String operation = parts[0];

            if (operation.equals("ENQUEUE")) {
                String name = parts[1];
                int severity = Integer.parseInt(parts[2]);
                enqueue(name, severity);
            } else if (operation.equals("DEQUEUE")) {
                dequeue();
            } else if (operation.equals("DISPLAY")) {
                display();
            }
        }

        sc.close();
    }
}
