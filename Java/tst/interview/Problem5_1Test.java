package interview;

import static org.assertj.core.api.Assertions.*;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Tyler on 9/5/2016.
 */
public class Problem5_1Test {
    @Test
    public void insertInt() throws Exception {
        assertThat(Problem5_1.insertInt(215, 5, 5, 3)).isEqualTo(239);
        assertThat(Problem5_1.insertInt(1024, 19, 6, 2)).isEqualTo(1100);
    }

}