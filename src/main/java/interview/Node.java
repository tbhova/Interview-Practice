package interview;

public class Node {
    private Node left = null, right = null;

    Node() {};

    Node(Node left, Node right) {
        this.left = left;
        this.right = right;
    }

    public Node left() { return left; }
    public Node right() { return right; }

    public void addLeft(Node leftNode) {
        left = leftNode;
    }

    public void addRight(Node rightNode) {
        right = rightNode;
    }

    public void newLeft() {
        left = new Node();
    }

    public void newRight() {
        right = new Node();
    }

}
