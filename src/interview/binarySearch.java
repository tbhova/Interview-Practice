package interview;

/**
 * Created by Tyler on 9/11/2016.
 */
public class binarySearch {
    public static int findNumber(int a[], int n) {
        int low = 0, high = a.length - 1;

        while (low <= high) {
            int mid = low+(high-low)/2;
            if (a[mid] == n) {
                return mid;
            } else if (a[mid] > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
}
