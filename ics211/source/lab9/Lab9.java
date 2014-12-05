/* 
   Lab 9 - Jason Favrod

   1) XML is perfect for storing the tree contents, because the structure of
      an XML document consists of hierarcherical nodes same as the BSTree.

   2) Whenn storing a BSTree's contents the most important things that need
      to be preserved is the key <-> value pairings. With this information
      intact, one could rebuild the BSTree.
*/

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

class Lab9 
{
    public static void main(String[] args) throws IOException {
        BSTree<Integer,String> tree = new BSTree<Integer,String>();
        tree.add(15,"animal");
        tree.add(20,"cat");
        tree.add(10,"cow");
        tree.add(12,"horse");
        tree.add(18,"dog");
        tree.add(19,"pig");
        tree.printPreOrder();
        System.out.println(tree.makePreOrderString());
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Where would you like to save the file?");
        
        try {
            File f = new File(keyboard.next());
            FileWriter fw = new FileWriter(f);
            PrintWriter pw = new PrintWriter(fw);
            pw.println(tree.makePreOrderString());
            pw.close();
        }
        catch (FileNotFoundException e) {
            System.out.println("Not a valid file name.");
        }
    }
}
