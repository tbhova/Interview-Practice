package interview;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Tyler on 8/31/2016.
 */
public class Problem4_4 {
    public static List<LLNode> listify(BNode root) {
        List<LLNode> heads = new ArrayList<LLNode>();
        listify(root, 0, heads);
        return heads;
    }

    private static void listify(BNode node, int depth, List<LLNode> heads) {
        if (node == null) return;
        while (depth >= heads.size()) {
            heads.add(null);
        }
        // update list head
        heads.set(depth, new LLNode(node.getValue(), heads.get(depth)));
        listify(node.left(), depth + 1, heads);
        listify(node.right(), depth + 1, heads);
    }
}
