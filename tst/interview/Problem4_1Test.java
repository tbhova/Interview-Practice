package interview;

import static org.assertj.core.api.Assertions.*;

import org.junit.Before;
import org.junit.Test;

public class Problem4_1Test {

    static private BNode balancedTree, unbalancedTree;

    @Before
    public void setupBalanced() {
        balancedTree = new BNode();
        BNode cursor = balancedTree;

        cursor.addLeft(new BNode());
        cursor = cursor.left();

        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());

        cursor = balancedTree;
        cursor.addRight(new BNode());
        cursor = cursor.right();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());
        cursor = cursor.left();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());

        cursor = balancedTree.right();
        cursor = cursor.right();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());
    }

    @Before
    public void setupUnbalanced() {
        unbalancedTree = new BNode();
        BNode cursor = unbalancedTree;

        cursor.addLeft(new BNode());
        cursor = cursor.left();

        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());

        cursor = unbalancedTree;
        cursor.addRight(new BNode());
        cursor = cursor.right();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());
        cursor = cursor.left();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());

        cursor = unbalancedTree.right();
        cursor = cursor.right();
        cursor.addLeft(new BNode());
        cursor.addRight(new BNode());

        cursor = cursor.right();
        cursor.addRight(new BNode());
    }

    @Test
    public void test() {
        Problem4_1 pr4_1 = new Problem4_1();
        assertThat(pr4_1.isBalanced(null)).isFalse();
        assertThat(pr4_1.isBalanced(unbalancedTree)).isFalse();
        assertThat(pr4_1.isBalanced(balancedTree)).isTrue();
    }

}