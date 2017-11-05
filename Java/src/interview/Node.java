package interview; /**
 * Created by Tyler on 8/30/2016.
 */

import lombok.Getter;
import org.apache.commons.lang3.builder.EqualsBuilder;
import org.apache.commons.lang3.builder.HashCodeBuilder;

import java.util.List;
import java.util.ArrayList;

public class Node {

    @Getter
    private List<Node> children = new ArrayList<Node>();

    private static int staticID = 0;

    private int id = ++staticID;

    public Node() { }

    public void addLink(Node node) {
        children.add(node);
    }

    @Override
    public boolean equals(Object other) {
        if (other == null) { return false; }
        if (other == this) { return true; }
        if (other.getClass() != this.getClass()) {
            return false;
        }
        Node rhs = (Node)other;
        return new EqualsBuilder().append(id, rhs.id).isEquals();
    }

    @Override
    public int hashCode() {
        return new HashCodeBuilder().append(id).hashCode();
    }
}