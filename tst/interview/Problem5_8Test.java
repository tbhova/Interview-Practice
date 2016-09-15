package interview;

import static org.assertj.core.api.Assertions.*;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Tyler on 9/10/2016.
 */
public class Problem5_8Test {
    private byte screen[] = new byte[6];
    private byte screen2[] = new byte[6];

    @Before
    public void setup() {
        for (int i = 0; i < 6; i++) {
            screen[i] = 0;
            screen2[i] = 0;
        }
    }

    @Test
    public void drawHorizontalLineTest() throws Exception {
        screen2[0] |= 28;
        assertThat(Problem5_8.drawHorizontalLine(screen, 24, 3, 5, 0)).isEqualTo(screen2);
    }

    @Test
    public void drawHorizontalLineTest2() throws Exception {
        screen2[0] |= 31;
        screen2[1] |= 192;
        assertThat(Problem5_8.drawHorizontalLine(screen, 24, 3, 9, 0)).isEqualTo(screen2);
    }

}