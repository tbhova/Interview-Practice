package interview;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.*;

/**
 * Created by Tyler on 9/1/2016.
 */
public class Problem4_6Test {
    private List<BNode> nodes = new ArrayList<BNode>();

    @Before
    public void buildTree() {
        nodes.add(new BNode(1));
        nodes.add(new BNode(2));
        nodes.add(new BNode(3));
        nodes.add(new BNode(4));
        nodes.add(new BNode(5));
        nodes.add(new BNode(6));
        nodes.add(new BNode(7));

        nodes.get(6).addLeft(nodes.get(3));
        nodes.get(3).addLeft(nodes.get(2));
        nodes.get(3).addRight(nodes.get(5));
        nodes.get(2).addLeft(nodes.get(0));
        nodes.get(0).addRight(nodes.get(1));
        nodes.get(5).addLeft(nodes.get(4));
    }

    @Test
    public void testNextInOrder() {
        for (int i = 0; i < nodes.size()-1; i++) {
            BNode answer = Problem4_6.nextInOrder(nodes.get(i));
            assertThat(answer).isEqualTo(nodes.get(i+1));
        }
        assertThat(Problem4_6.nextInOrder(nodes.get(nodes.size() - 1))).isEqualTo(null);
    }
}