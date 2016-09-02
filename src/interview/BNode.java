package interview;

import lombok.Getter;
import org.apache.commons.lang3.builder.EqualsBuilder;

public class BNode {
    private BNode left = null, right = null, parent = null;

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

    private void setParent(BNode parent) {
        this.parent = parent;
    }

    public void addLeft(BNode leftBNode) {
        left = leftBNode;
        left.setParent(this);
    }

    public void addRight(BNode rightBNode) {
        right = rightBNode;
        right.setParent(this);
    }

    public void newLeft() {
        left = new BNode();
    }

    public void newRight() {
        right = new BNode();
    }

    public BNode parent() {
        return parent;
    }

    @Override
    public boolean equals(Object other) {
        if (other == null || other.getClass() != this.getClass()) return false;
        if (other == this) return true;

        BNode rhs = (BNode)other;
        return new EqualsBuilder().append(value, rhs.value).append(parent, rhs.parent).append(left, rhs.left).append(right, rhs.right).isEquals();
    }

}
