import javax.swing.*;
import java.awt.event.*;
import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.Point;

class GUIDraw extends JPanel implements ActionListener
{
    public GUIDraw() {
        super();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Point point = new Point(40,40);
        g.drawRect(point.x, point.y, 150,75);
        g.drawString("Hi", point.x + 50, point.y + 50);
    }

    public Dimension getPreferredSize() {
        return new Dimension(800, 600);
    }


    public void actionPerformed(ActionEvent ae) {
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }

    public static void createAndShowGUI() {
        System.out.println("Created GUI on EDT?" +
                SwingUtilities.isEventDispatchThread());
        
        JFrame frame = new JFrame("JPanel Demo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new GUIDraw());
        frame.pack();
        frame.setVisible(true);
    }
}
