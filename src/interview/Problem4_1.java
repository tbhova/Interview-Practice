
package interview;

public class Problem4_1 {
    private class TreeSize {
        public int min, max;
    }

    public boolean isBalanced(Node root) {
        if (root == null) {
            return false;
        }

        TreeSize size = traverse(root, 0);

        return Math.abs(size.max - size.min) <= 1;
    }

    private TreeSize traverse(Node node, int depth) {
        TreeSize left = new TreeSize();
        left.min = (node.left() == null || node.right() == null) ? depth : Integer.MAX_VALUE;
        left.max = depth;
        TreeSize right = left;

        if (node.left() != null) traverse(node.left(), depth + 1);
        if (node.right() != null) traverse(node.right(), depth + 1);

        left.min = left.min < right.min ? left.min : right.min;
        left.max = left.max > right.max ? left.max : right.max;
        return left;
    }

}