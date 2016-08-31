package interview;

/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_2 {

    public Problem4_2() {}

    public boolean isRoute(Node start, Node end) {
        start.setVisited();
        for(Node child : start.getChildren()) {
            if (child.equals(end)) {
                return true;
            }
            if (!child.isVisited() && isRoute(child, end)) { return true;}
        }
        return false;
    }
}
