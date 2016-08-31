package interview;

import java.util.HashSet;

/**
 * Created by Tyler on 8/30/2016.
 */
public class Problem4_2 {

    private static HashSet<Node> visited = new HashSet<Node>();

    private static void nodeVisited(Node node) {
        visited.add(node);
    }

    private static boolean isVisited(Node node) {
        return visited.contains(node);
    }

    public static boolean isRoute(Node start, Node end) {
        visited = new HashSet<Node>();
        return recurse(start, end);
    }

    private static boolean recurse(Node start, Node end) {
        nodeVisited(start);
        for(Node child : start.getChildren()) {
            if (child.equals(end)) { return true; }
            if (!isVisited(child) && recurse(child, end)) { return true; }
        }
        return false;
    }
}