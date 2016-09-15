package interview;

import static org.assertj.core.api.Assertions.*;
import org.junit.Test;

/**
 * Created by Tyler on 9/11/2016.
 */
public class binarySearchTest {

    private int a[] = new int[]{-55, -5, 0, 4, 6, 71, 97, 101};
    @Test
    public void findNumber() throws Exception {
        assertThat(binarySearch.findNumber(a, 1)).isEqualTo(-1);
        assertThat(a[binarySearch.findNumber(a, 4)]).isEqualTo(4);
        assertThat(a[binarySearch.findNumber(a, 71)]).isEqualTo(71);
    }

}