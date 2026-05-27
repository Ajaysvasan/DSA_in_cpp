import java.util.*;

public class q1 {
    public static int binarySearch(ArrayList<Integer> arr, int high, int low, int target) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if (arr.get(mid) == target)
                return mid;
            if (arr.get(mid) > target)
                return binarySearch(arr, mid - 1, low, target);
            else
                return binarySearch(arr, high, mid + 1, target);
        }
        return -1;
    }

    public static void main(String[] args) {

    }
}
