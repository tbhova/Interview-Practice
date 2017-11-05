package interview;

/**
 * Created by Tyler on 9/5/2016.
 */
public class Problem5_2 {
    public static String doubleToBinaryString(double n) {
        if (n <= 0 || n >= 1) return "ERROR";
        return binString(n, "0.");
    }

    private static String binString(double n, String str) {
        if (str.length() >= 34) return "ERROR";
        double val = n * 2;
        if (val >= 1) {
            str += "1";
            val -= 1;
            if (val == 0) return str;
        } else {
            str += "0";
        }
        return binString(val, str);
    }
}
