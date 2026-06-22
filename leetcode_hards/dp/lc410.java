package leetcode_hards.dp;

class Solution {

    public int splitArray(int[] nums, int k) {

        int low = 0;
        long high = 0;

        for (int num : nums) {
            low = Math.max(low, num);
            high += num;
        }

        long answer = high;

        while (low <= high) {

            long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = (int) (mid + 1);
            }
        }

        return (int) answer;
    }

    private boolean canSplit(int[] nums, int k, long maxAllowedSum) {

        int partitions = 1;
        long currentSum = 0;

        for (int num : nums) {

            if (currentSum + num <= maxAllowedSum) {
                currentSum += num;
            } else {
                partitions++;
                currentSum = num;
            }
        }

        return partitions <= k;
    }
}
