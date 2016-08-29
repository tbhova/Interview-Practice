package interview;

import static org.assertj.core.api.Assertions.*;

import org.junit.Before;
import org.junit.Test;

public class Problem4_1Test {

    static private Node balancedTree, unbalancedTree;

    @Before
    public void setupBalanced() {
        balancedTree = new Node();
        Node cursor = balancedTree;

        cursor.addLeft(new Node());
        cursor = cursor.left();

        cursor.addLeft(new Node());
        cursor.addRight(new Node());

        cursor = balancedTree;
        cursor.addRight(new Node());
        cursor = cursor.right();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());
        cursor = cursor.left();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());

        cursor = balancedTree.right();
        cursor = cursor.right();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());
    }

    @Before
    public void setupUnbalanced() {
        unbalancedTree = new Node();
        Node cursor = unbalancedTree;

        cursor.addLeft(new Node());
        cursor = cursor.left();

        cursor.addLeft(new Node());
        cursor.addRight(new Node());

        cursor = unbalancedTree;
        cursor.addRight(new Node());
        cursor = cursor.right();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());
        cursor = cursor.left();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());

        cursor = unbalancedTree.right();
        cursor = cursor.right();
        cursor.addLeft(new Node());
        cursor.addRight(new Node());

        cursor = cursor.right();
        cursor.addRight(new Node());
    }

    @Test
    public void test() {
        Problem4_1 pr4_1 = new Problem4_1();
        assertThat(pr4_1.isBalanced(null)).isFalse();
        assertThat(pr4_1.isBalanced(unbalancedTree)).isFalse();
        assertThat(pr4_1.isBalanced(balancedTree)).isTrue();
    }

}