import javax.swing.*;
import java.awt.event.*;
import java.awt.BorderLayout;

class GUIDemo extends JFrame implements ActionListener
{
    private String someText;
    private JTextArea textarea;
    static Queue q = new Queue();

    public GUIDemo(String title) {
        super(title);
        setBounds(10,10,600,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        int[] ray = {3, 32, 15, 75, 23,11};
        for (int i = 0; i < ray.length; i ++) {
            q.enqueue(ray[i]);
            q.print();
        }

        JButton numbs[] = new JButton[ray.length];
        for (int i = 0; i < ray.length; i ++) {
            numbs[i]= new JButton((Integer.toString(ray[i])));
            numbs[i].addActionListener(this);
        }

        JPanel panel = new JPanel();
        
        for (int i = 0; i < ray.length; i ++) {
            panel.add(numbs[i]);
        }
        add(panel, BorderLayout.CENTER);

        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);
        JMenu file = new JMenu("File");
        JMenuItem quit = new JMenuItem("Quit");
        quit.addActionListener(this);
        file.add(quit);
        menuBar.add(file);
        
        textarea = new JTextArea();
        panel.add(textarea);
        someText = q.toString(); 
        textarea.setText(someText);
    }

    public void actionPerformed(ActionEvent ae) {
        String choice = ae.getActionCommand();

        if (choice.equals("Click Me")) {
            JOptionPane.showMessageDialog(this, "Now going to add a new line after every three chars.");
            someText = someText.replaceAll("(.{3})", "$1\n");
            textarea.setText(someText);
        }
        else if (choice.equals("Quit")) {
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        GUIDemo myApp = new GUIDemo("Hello World");
        myApp.setVisible(true);
    }
}
