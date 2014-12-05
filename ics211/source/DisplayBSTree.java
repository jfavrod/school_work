import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class DisplayBSTree extends JPanel implements ActionListener 
{
    private BSTree<Integer, String> tree;

    public DisplayBSTree() {
        super();
        tree = new BSTree<Integer, String>();
        JButton addButton = new JButton("Add node");
        addButton.addActionListener(this);
        add(addButton);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (tree.height() > 0) {
            tree.addXByLevel(500,50);
            tree.printByLevel();
        }
    }

    public Dimension getPreferredSize() {
        return new Dimension(1000, 800);
    }

    public void actionPerformed(ActionEvent ae) {

    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                showGUI();
            }
        });
    }

    public static void showGUI() {
        JFrame myApp = new JFrame("Display BSTree");
        myApp.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        myApp.add(new DisplayBSTree());
        myApp.pack();
        myApp.setVisible(true);
    }
}
