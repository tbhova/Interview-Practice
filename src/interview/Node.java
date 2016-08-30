package interview; /**
 * Created by Tyler on 8/30/2016.
 */

import lombok.Getter;
import org.apache.commons.lang3.builder.EqualsBuilder;

public class Node {

    @Getter
    private List<Node> children = new ArrayList<Node>();

    @Getter
    private boolean visited = false;

    @Getter
    private Object data;

    public Node(Object data) {
        this.data = data;
    }

    public void addChild(Node child) {
        children.add(child);
    }

    public void visited() {
        visited = true;
    }

    @Override
    public boolean equals(Object other) {
        if (object == null) { return false; }
        if (object == this) { return true; }
        if (other.getClass() != this.getClass()) {
            return false;
        }
        Node rhs = (Node)other;
        return new EqualsBuilder().append(children, rhs.children).append(data, rhs.data).append(visited, rhs.visited).isEquals();
    }
}