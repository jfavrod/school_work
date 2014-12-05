import java.awt.Point;
import java.util.ArrayList;

public class BSTree<K extends Comparable<K>, V> {
    class TreeNode {
        K key;
        V value;
        TreeNode left;
        TreeNode right;
        int x;
        int y;

        public TreeNode(K k, V val) {
            key = k;
            value = val;
            left = null;
            right = null;
            x = 0;
            y = 0;
        }

        public String toString() {
            return "(" + key + "," + value + ") (" + 
                x + "," + y + ")";
        }

        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
        public K getKey() {
            return key;
        }
        public V getValue() {
            return value;
        }
        public TreeNode getLeft() {
            return left;
        }
        public TreeNode getRight() {
            return right;
        }
    }

    private TreeNode root;
    private String childType;
    private int parentX;
    private int parentY;
    private int yInterval;
    private ArrayList<ArrayList<TreeNode>> treeNodes;
    private int level;
    private String preOrderString;

    public BSTree() {
        root = null;
        preOrderString = "";

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

    public void makePreOrder() {
        preOrderString = "{\"nodes\" : [";
        makePreOrder(root);
    }

    private void makePreOrder(TreeNode nd) {
        if (nd == null) {
            return;
        }

        preOrderString += "{ \"" + nd.key  + "\" : \"" + 
            nd.value + "\"},";
        makePreOrder(nd.left);
        makePreOrder(nd.right);
    }

    public String getPreOrderString() {
        preOrderString = preOrderString.trim().replaceAll(",$","");
        preOrderString += "]}";
        return preOrderString;
    }

    public void printByLevel() {
        int height = height(root);

        for (int depth = 1; depth <= height; depth++) {
            printByLevel(root,depth);
            System.out.println("");
        }
    }

    private void printByLevel(TreeNode nd, int depth) {
        if (nd == null) {
            return;
        }
    
        if (depth == 1) {
            System.out.print(nd + " ");
        }
        else {
            printByLevel(nd.left,depth-1);
            printByLevel(nd.right,depth-1);
        }
    }

    public ArrayList<ArrayList<TreeNode>> getTreeNodes() {
        return treeNodes;
    }

    public void addXByLevel(Point start, int xSize, int ySize) {
        int height = height(root);
        yInterval = ySize;
        root.x = start.x;
        root.y = start.y;
        treeNodes = new ArrayList<ArrayList<TreeNode>>();

        for (int i = 1; i <= height; i++) {
            ArrayList<TreeNode> myList = new ArrayList<TreeNode>();
            treeNodes.add(myList);
        }

        treeNodes.get(0).add(root);
        
        for (int depth = 2; depth <= height; depth++) {
            int spacing = power2(height-depth)*xSize;
            level = depth - 1;
            addXByLevel(root,depth,spacing);
        }
    }
    
    private void addXByLevel(TreeNode nd, int depth, int width) {
        if (nd == null) {
            return;
        }
    
        if (depth == 1) {
            int x = 0;
            if (childType.equals("left")) {
                x = parentX - width/2;
            }
            else if (childType.equals("right")) {
                x = parentX + width/2;
            }
            nd.x = x;
            nd.y = parentY + yInterval;
            treeNodes.get(level).add(nd);
        }
        else {
            parentX = nd.x;
            parentY = nd.y;
            childType = "left";
            addXByLevel(nd.left,depth-1,width);
            childType = "right";
            addXByLevel(nd.right,depth-1,width);
        }
    }

    private static int power2(int n) {
        int temp = 1;
        for (int i = 0; i < n; i++) {
            temp *= 2;
        }
        return temp;
    }

    public int height() {
        return height(root);
    }

    private int height(TreeNode nd) {
        if (nd == null) {
            return 0;
        }

        int leftht = height(nd.left);
        int rightht = height(nd.right);
        
        if (leftht > rightht) {
            return leftht + 1;
        }
        else {
            return rightht + 1;
        }
    }

    public TreeNode find(K key) {
        return find(root, key);
    }

    private TreeNode find(TreeNode nd, K key) {
        if (nd == null) {
            return null;
        }
    
        int cmp = key.compareTo(nd.key);
    
        if (cmp < 0) {
    
            return find(nd.left, key);
    
        }
        else if (cmp > 0) {
            return find(nd.right, key);
        }
        else {
            return nd;
        }
    }

    public TreeNode minimum() {
        return minimum(root);
    }

    private TreeNode minimum(TreeNode nd) {
        if (nd.left == null) {
            return nd;
        }
    
        return minimum(nd.left);
    }

    public TreeNode deleteMin() {
        return deleteMin(root);
    }

    private TreeNode deleteMin(TreeNode nd) {
        if (nd.left == null) {
            return nd.right;
        }

        nd.left = deleteMin(nd.left);
        return nd;
    }

    public void delete(K key) {
        root = delete(root,key);
    }

    private TreeNode delete(TreeNode nd, K key) {
    
        if (nd == null) {
            return null;
        }
    
        int cmp = key.compareTo(nd.key);
    
        if (cmp < 0) {
            nd.left = delete(nd.left,key);
        }
        else if (cmp > 0) {
            nd.right = delete(nd.right,key);
        }
        else {
            if (nd.right == null) {
                return nd.left;
            }
        
            if (nd.left == null) {
                return nd.right;
            }

            TreeNode old = nd;
            nd = minimum(old.right);
            nd.right = deleteMin(old.right);
            nd.left = old.left;
        }

        return nd;
    }
}
