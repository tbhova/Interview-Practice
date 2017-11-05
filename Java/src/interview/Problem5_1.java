package interview;

/**
 * Created by Tyler on 9/5/2016.
 */
public class Problem5_1 {
    public static int insertInt(int N, int M, int i, int j) {
        if (!(j < i)) return N;
        int ret = N;
        int mask = (1 << (i+1)) - 1;
        int mask2 = (1 << j) - 1;
        mask &= ~mask2;
        mask = ~mask;

        ret &= mask;
        int shiftedM = M << j;
        ret |= shiftedM;
        return ret;
    }
}
