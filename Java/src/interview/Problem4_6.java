package interview;

/**
 * Created by Tyler on 9/1/2016.
 */
public class Problem4_6 {
    public static BNode nextInOrder(BNode node) {
        if (node == null) return null;
        if (node.right() != null) {
            return inOrder(node.right());
        } else {
            BNode parent = node.parent();
            if (parent == null) return null;
            if (node.equals(parent.left())) return parent;
            else return traverseAntiInOrder(parent, node);
        }
    }

    private static BNode inOrder(BNode node) {
        if (node == null) return null;
        if (node.left() != null) {
            return inOrder(node.left());
        }
        return node;
    }
    private static BNode traverseAntiInOrder(BNode node, BNode last) {
        if (node == null) return null;
        if (last.equals(node.left())) return node;
        return traverseAntiInOrder(node.parent(), node);
    }
}
