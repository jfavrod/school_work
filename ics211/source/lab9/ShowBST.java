import java.io.*;
import java.util.Scanner;

class ShowBST 
{
    public static void main(String[] args) throws FileNotFoundException,IOException {
        BSTree<Integer,String> tree = new BSTree<Integer,String>();
        Scanner keyboard = new Scanner (System.in);
        File f = null;

        try {
            System.out.println("Which xml file would you like to translate into a Binary Search Tree?");
            f = new File(keyboard.next());
            FileReader fr = new FileReader(f);
            BufferedReader infile = new BufferedReader(fr);
            String line = "";
            String keyString = "";
            String value = "";
            while ((line = infile.readLine()) != null) {
                if (line.contains("</node>")) {
                tree.add(new Integer(keyString.trim()),value.trim());
                }
                else if (line.contains("<key>")) {
                keyString = line.replaceAll("<key>","").
                replaceAll("</key>","");
                }
                else if (line.contains("<value>")) {
                value = line.replaceAll("<value>","").
                replaceAll("</value>","");
                }
            }
            System.out.println("Printing tree inorder");
            tree.printInOrder();
            System.out.println("\nPrinting tree preorder");
            tree.printPreOrder();
        }
        catch (FileNotFoundException e) {
            System.out.println("Not a valid file");
        }
    }
}
