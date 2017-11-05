package interview;

/**
 * Created by Tyler on 9/4/2016.
 */
public class Problem4_7 {
    public static BNode firstAncestor(BNode root, BNode a, BNode b) {
        BNode ancestor = null;
        if (isInTree(root, a, b)) {
            ancestor = root;
            if (isInTree(root.left(), a, b)) {
                ancestor = firstAncestor(root.left(), a, b);
            } else if (isInTree(root.right(), a, b)) {
                ancestor = firstAncestor(root.right(), a, b);
            }
        }
        return ancestor;
    }

    private static boolean isInTree(BNode root, BNode a, BNode b) {
        return inTree(root, a) && inTree(root, b);
    }

    private static boolean inTree(BNode root, BNode node) {
        if (root == null) return false;
        if (root.equals(node)) return true;
        return inTree(root.left(), node) || inTree(root.right(), node);
    }
}
