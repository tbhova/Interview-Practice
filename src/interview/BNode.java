package interview;

import lombok.Getter;

public class BNode {
    private BNode left = null, right = null;

    @Getter
    private Integer value = 0;

    public BNode() {};

    public BNode(Integer value) { this.value = value; }

    public BNode(BNode left, BNode right) {
        this.left = left;
        this.right = right;
    }

    public BNode left() { return left; }
    public BNode right() { return right; }

    public void addLeft(BNode leftBNode) {
        left = leftBNode;
    }

    public void addRight(BNode rightBNode) {
        right = rightBNode;
    }

    public void newLeft() {
        left = new BNode();
    }

    public void newRight() {
        right = new BNode();
    }

}
