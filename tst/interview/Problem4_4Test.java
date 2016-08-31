package interview;

import static org.assertj.core.api.Assertions.*;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

/**
 * Created by Tyler on 8/31/2016.
 */
public class Problem4_4Test {

    BNode root = new BNode(6);
    List<LLNode> expected = new ArrayList<LLNode>();

    @Before
    public void setUp() throws Exception {
        root.addLeft(new BNode(2));
        root.addRight(new BNode(11));

        BNode current = root.left();
        current.addLeft(new BNode(7));
        current.addRight(new BNode(6));

        current = current.left();
        current.addLeft(new BNode(8));
        current.addRight(new BNode(9));

        current = root.right();
        current.addRight(new BNode(14));

        current = current.right();
        current.addLeft(new BNode(1));

        current = current.left();
        current.addLeft(new BNode(3));


        expected.add(new LLNode(6));

        LLNode tmp = new LLNode(2);
        expected.add(new LLNode(11, tmp));

        tmp = new LLNode(14);
        tmp = new LLNode(6, tmp);
        expected.add(new LLNode(7, tmp));

        tmp = new LLNode(1);
        tmp = new LLNode(9, tmp);
        expected.add(new LLNode(8, tmp));

        expected.add(new LLNode(3));
    }

    @Test
    public void listifyTest() throws Exception {
        assertThat(Problem4_4.listify(null)).isEmpty();
        assertThat(Problem4_4.listify(root)).isEqualTo(expected);
    }

}