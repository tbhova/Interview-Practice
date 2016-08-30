
package interview;

public class Problem4_1 {
    private class TreeSize {
        public int min, max;
    }

    public boolean isBalanced(BNode root) {
        if (root == null) {
            return false;
        }

        TreeSize size = traverse(root, 0);

        return Math.abs(size.max - size.min) <= 1;
    }

    private TreeSize traverse(BNode BNode, int depth) {
        TreeSize left = new TreeSize();
        left.min = (BNode.left() == null || BNode.right() == null) ? depth : Integer.MAX_VALUE;
        left.max = depth;
        TreeSize right = left;

        if (BNode.left() != null) left = traverse(BNode.left(), depth + 1);
        if (BNode.right() != null) right = traverse(BNode.right(), depth + 1);

        left.min = left.min < right.min ? left.min : right.min;
        left.max = left.max > right.max ? left.max : right.max;
        return left;
    }

}