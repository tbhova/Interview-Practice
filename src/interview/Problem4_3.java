package interview;

import java.util.List;

/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_3 {

    public static BNode createBST(List<Integer> array) {
        if (array == null || array.size() == 0) return null;

        int mid = array.size()/2;
        BNode root = new BNode(array.get(mid));

        List<Integer> left = mid == 0 ? null : array.subList(0, mid);
        List<Integer> right = mid == array.size() -1 ? null : array.subList(mid + 1, array.size());
        root.addLeft(createBST(left));
        root.addRight(createBST(right));
        return root;
    }
}
