package interview;

import java.util.List;

/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_3 {

    public static BNode createBST(List<Integer> array) {
        if (array == null || array.size() == 0) return null;
        return createBST(array, 0 , array.size()-1);
    }
    public static BNode createBST(List<Integer> array, int start, int end) {
        if (start > end) return null;

        int size = (end - start + 1);
        int mid = start + (size / 2);
        BNode root = new BNode(array.get(mid));

        root.addLeft(createBST(array, start, mid - 1));
        root.addRight(createBST(array, mid + 1, end));
        return root;
    }
}
