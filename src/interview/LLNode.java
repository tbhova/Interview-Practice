package interview;

import lombok.Getter;
import lombok.Setter;
import org.apache.commons.lang3.Validate;
import org.apache.commons.lang3.builder.EqualsBuilder;

/**
 * Created by Tyler on 8/31/2016.
 */
public class LLNode {

    @Getter @Setter
    private LLNode next;

    @Getter @Setter
    private Object data;

    public LLNode(Object data) {
        this(data, null);
    }
    public LLNode(Object data, LLNode next) {
        Validate.notNull(data);
        this.next = next;
        this.data = data;
    }

    public boolean contains(LLNode node) {
        if (next == null) return false;
        if (next.equals(node)) return true;
        return next.contains(node);
    }

    @Override
    public boolean equals(Object other) {
        if (other == null || other.getClass() != this.getClass()) return false;
        if (other == this) return true;
        LLNode rhs = (LLNode)other;
        return new EqualsBuilder().append(data, rhs.data).append(next, rhs.next).isEquals();
    }
}
