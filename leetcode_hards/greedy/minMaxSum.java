package leetcode_hards.greedy;

import java.util.*;

public class minMaxSum {
    public static boolean canSplit(ArrayList<Integer> requests, int k, long allowedSum) {
        int count = 1;
        long currentSum = 0;
        for (int request : requests) {
            if (currentSum + request <= allowedSum) {
                currentSum += request;
            } else {
                count++;
                currentSum = request;
            }
        }
        return count <= k;
    }

    public static int splitArray(ArrayList<Integer> requests, int k) {
        int low = 1;
        long high = 0;
        for (int i = 0; i < requests.size(); i++) {
            low = Math.max(low, requests.get(i));
            high += requests.get(i);
        }
        long ans = high;
        while (low <= high) {
            long mid = low + (high - low) / 2;
            if (canSplit(requests, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = (int) mid + 1;
            }
        }
        return (int) ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> requests = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            requests.add(sc.nextInt());
        }
        int k = sc.nextInt();
        System.out.println(splitArray(requests, k));
        sc.close();
        return;
    }
}
