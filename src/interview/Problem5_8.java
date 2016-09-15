package interview;

/**
 * Created by Tyler on 9/10/2016.
 */
public class Problem5_8 {
    public static byte[] drawHorizontalLine(byte screen[], int width, int x1, int x2, int y) {
        if (width % 8 != 0 || x2 - x1 > width || x1 > x2) return screen;

        int currentX = x1;
        int remainingWidth = x2-x1;

        int index = ((y*8)/width) + currentX / 8;
        while (remainingWidth > 0) {
            int first = currentX % 8;
            int second = (currentX/8 != (currentX+remainingWidth)/8) ? 7 : (x2 % 8);

            screen[index] = setBits(screen[index], first, second);

            remainingWidth -= 8-first;
            index ++;
            currentX += 8-first;
        }
        return screen;
    }

    private static byte setBits(byte b, int x1, int x2) {
        byte mask = (byte)((byte)(1 << (8-x1)) - (byte)1);
        byte mask2 = (byte)((byte)(1 << (7-x2)) - (byte)1);
        mask2 = (byte)~mask2;
        mask &= mask2;

        return (byte)(b | mask);
     }
}
