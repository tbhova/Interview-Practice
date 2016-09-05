package interview;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.*;

/**
 * Created by Tyler on 9/4/2016.
 */
public class Problem4_7Test {
    private List<BNode> nodes = new ArrayList<BNode>();

    @Before
    public void setUp() throws Exception {
        for (int i = 0; i < 13; i++) {
            nodes.add(new BNode(i+1));
        }

        nodes.get(0).addLeft(nodes.get(1));
        nodes.get(0).addRight(nodes.get(2));
        nodes.get(1).addLeft(nodes.get(3));
        nodes.get(1).addRight(nodes.get(4));
        nodes.get(2).addRight(nodes.get(5));
        nodes.get(3).addLeft(nodes.get(6));
        nodes.get(4).addLeft(nodes.get(7));
        nodes.get(4).addRight(nodes.get(8));
        nodes.get(5).addLeft(nodes.get(9));
        nodes.get(5).addRight(nodes.get(10));
        nodes.get(8).addRight(nodes.get(11));
        nodes.get(9).addLeft(nodes.get(12));
    }

    @Test
    public void testFirstAncestor() {
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(0), nodes.get(0))).isEqualTo(nodes.get(0));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(1), nodes.get(1))).isEqualTo(nodes.get(1));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(1), nodes.get(0))).isEqualTo(nodes.get(0));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(11), nodes.get(12))).isEqualTo(nodes.get(0));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(6), nodes.get(11))).isEqualTo(nodes.get(1));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(11), nodes.get(7))).isEqualTo(nodes.get(4));
        assertThat(Problem4_7.firstAncestor(nodes.get(0), nodes.get(10), nodes.get(12))).isEqualTo(nodes.get(5));
    }
}