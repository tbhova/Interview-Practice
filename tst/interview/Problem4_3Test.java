package interview;

import static org.assertj.core.api.Assertions.*;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import static org.junit.Assert.*;


/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_3Test {
    List<Integer> l1 = new ArrayList<Integer>(), l2 = new ArrayList<Integer>();

    @Before
    public void createLists() {
        l1 = Arrays.asList(new Integer[]{1, 3, 4, 6, 7, 8, 9});
        Random r = new Random();
        for (int i = 0; i < r.nextInt(10) + 1; i++) {
            int next = r.nextInt(22);
            while (l2.contains(next)) {
                next= r.nextInt(22);
            }
            l2.add(next);
        }
    }

    private boolean validateBST(BNode node) {
        if (node.left() != null && node.left().getValue() > node.getValue() && !validateBST(node.left())) {
            return false;
        }
        if (node.right() != null && node.right().getValue() < node.getValue() && !validateBST(node.right())) {
            return false;
        }
        return true;
    }

    private int countNodes(BNode node) {
        if (node == null) return 0;
        return countNodes(node.left()) + countNodes(node.right()) + 1;
    }

    @Test
    public void createBSTTest() throws Exception {
        BNode t1 = Problem4_3.createBST(l1);
        BNode t2 = Problem4_3.createBST(l2);

        assertThat(validateBST(t1)).isTrue();
        assertThat(validateBST(t2)).isTrue();

        Problem4_1 p = new Problem4_1();
        assertThat(p.isBalanced(t1)).isTrue();
        assertThat(p.isBalanced(t2)).isTrue();

        assertThat(countNodes(t1)).isEqualTo(l1.size());
        assertThat(countNodes(t2)).isEqualTo(l2.size());
    }

}