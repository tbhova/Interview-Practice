package interview;

import org.junit.Before;
import org.junit.Test;
import static org.assertj.core.api.Assertions.*;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;


/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_2Test {
    private Integer id = 0;
    private List<Node> nodes = new ArrayList<Node>();

    @Before
    public void buildGraph() {
        for (int i = 0; i < 5; i++) {
            nodes.add(new Node(++id));
        }

        //A to E
        Node current = nodes.get(0);
        current.addLink(nodes.get(4));

        //B to E
        current = nodes.get(1);
        current.addLink(nodes.get(4));

        //C to B
        current = nodes.get(2);
        current.addLink(nodes.get(1));

        //D to D
        current = nodes.get(3);
        current.addLink(nodes.get(3));

        //E to C, D
        current = nodes.get(4);
        current.addLink(nodes.get(2));
        current.addLink(nodes.get(3));
    }

    private void reset() {
        for (Node node : nodes) {
            node.reset();
        }
    }

    @Test
    public void testIsRoute() {
        Problem4_2 pr = new Problem4_2();

        assertThat(pr.isRoute(nodes.get(0), nodes.get(0))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(0), nodes.get(1))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(0), nodes.get(2))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(0), nodes.get(3))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(0), nodes.get(4))).isTrue();
        reset();

        assertThat(pr.isRoute(nodes.get(1), nodes.get(0))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(1), nodes.get(1))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(1), nodes.get(2))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(1), nodes.get(3))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(1), nodes.get(4))).isTrue();
        reset();

        assertThat(pr.isRoute(nodes.get(2), nodes.get(0))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(2), nodes.get(1))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(2), nodes.get(2))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(2), nodes.get(3))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(2), nodes.get(4))).isTrue();
        reset();

        assertThat(pr.isRoute(nodes.get(3), nodes.get(0))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(3), nodes.get(1))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(3), nodes.get(2))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(3), nodes.get(3))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(3), nodes.get(4))).isFalse();
        reset();

        assertThat(pr.isRoute(nodes.get(4), nodes.get(0))).isFalse();
        reset();
        assertThat(pr.isRoute(nodes.get(4), nodes.get(1))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(4), nodes.get(2))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(4), nodes.get(3))).isTrue();
        reset();
        assertThat(pr.isRoute(nodes.get(4), nodes.get(4))).isTrue();
        reset();
    }
}