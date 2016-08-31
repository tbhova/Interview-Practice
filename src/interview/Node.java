package interview; /**
 * Created by Tyler on 8/30/2016.
 */

import lombok.Getter;
import org.apache.commons.lang3.builder.EqualsBuilder;
import java.util.List;
import java.util.ArrayList;

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

    public void addLink(Node node) {
        children.add(node);
    }

    public void setVisited() { visited = true; }

    public void reset() { visited = false; }

    @Override
    public boolean equals(Object other) {
        if (other == null) { return false; }
        if (other == this) { return true; }
        if (other.getClass() != this.getClass()) {
            return false;
        }
        Node rhs = (Node)other;
        return new EqualsBuilder().append(data, rhs.data).append(visited, rhs.visited).append(children, rhs.children).isEquals();
    }
}