package leetcode_hards.greedy;

import java.util.*;

public class minMaxShipYard {
    public static boolean canSplit(ArrayList<Integer> weights, int days, long allowedWeight) {
        int count = 1;
        long currentSum = 0;
        for (int weight : weights) {
            if (currentSum + weight <= allowedWeight) {
                currentSum += weight;
            } else {
                count++;
                currentSum = weight;
            }
        }
        return count <= days;
    }

    public static int splitArray(ArrayList<Integer> weights, int days) {
        long low = 1;
        long high = 0;
        for (int i = 0; i < weights.size(); i++) {
            low = Math.max(low, weights.get(i));
            high += weights.get(i);
        }
        long ans = high;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (canSplit(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int) ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> weights = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            weights.add(sc.nextInt());
        }
        int days = sc.nextInt();
        System.out.println(splitArray(weights, days));
        sc.close();
        return;
    }
}
