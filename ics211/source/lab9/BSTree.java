import java.util.ArrayList;
public class BSTree<K extends Comparable<K>, V> {
    class TreeNode
    {
        K key;
        V value;
        TreeNode left;
        TreeNode right;

        public TreeNode(K k, V val) {
            key = k;
            value = val;
            left = null;
            right = null;
        }

        public String toXML() {
            String xmlnode = "\t<node>\n";
            xmlnode += "\t\t<key>"+key+"</key>\n";
            xmlnode += "\t\t<value>"+value+"</value>\n";
            xmlnode += "\t</node>\n";
            return xmlnode;
        }
        
        public String toString() {
            return "key: " + key + ", value: " + value;
        }
    }

    private TreeNode root;
    private String preOrderString;

    public BSTree() {
        root = null;
        preOrderString = null;
    }

    public void add(K key, V val)  {
        root = add(root, key, val);
    }

    private TreeNode add(TreeNode nd, K key, V val) {
        if (nd == null) {
            return new TreeNode(key,val);
        }
        int cmp = key.compareTo(nd.key);
        
        if (cmp == 0) {
            nd.value = val;
        }
        else if (cmp > 0) {
            nd.right = add(nd.right,key,val);
        }
        else {
            nd.left = add(nd.left,key,val);
        }
        return nd;
    }

    public void printInOrder() {
        printInOrder(root);
    }

    private void printInOrder(TreeNode nd) {
        if (nd == null) {
            return;
        }
        printInOrder(nd.left);
        System.out.println(nd.toString());
        printInOrder(nd.right);
    }

    public void printPreOrder() {
        printPreOrder(root);
    }
    
    private void printPreOrder(TreeNode nd) {
        if (nd == null) {
            return;
        }
        System.out.println(nd.toString());
        printPreOrder(nd.left);
        printPreOrder(nd.right);
    }

    public String makePreOrderString() {
        preOrderString = "<?xml version=\"1.0\" ?>\n";
        preOrderString += "<nodes>\n";
        makePreOrderString(root);
        preOrderString += "</nodes>";
        return preOrderString;
    }

    private void makePreOrderString(TreeNode nd) {
        if (nd == null) {
            return;
        }
        preOrderString += nd.toXML();
        makePreOrderString(nd.left);
        makePreOrderString(nd.right);
    }
}
