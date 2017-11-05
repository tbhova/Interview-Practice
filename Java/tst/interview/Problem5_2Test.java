package interview;

import static org.assertj.core.api.Assertions.*;
import org.junit.Test;

/**
 * Created by Tyler on 9/5/2016.
 */
public class Problem5_2Test {
    @Test
    public void doubleToBinaryString() throws Exception {
        assertThat(Problem5_2.doubleToBinaryString(0.5)).isEqualTo("0.1");
        assertThat(Problem5_2.doubleToBinaryString(1)).isEqualTo("ERROR");
        assertThat(Problem5_2.doubleToBinaryString(0.3)).isEqualTo("ERROR");
        assertThat(Problem5_2.doubleToBinaryString(0.61288452148437500000)).isEqualTo("0.100111001110011");
    }

}