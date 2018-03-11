import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class GUI extends JFrame {

  /**
   * 
   */
  private static final long serialVersionUID = 1L;
  // Variable definitions
  private final JPanel panel = new JPanel(new GridLayout(0, 2));
  private final JLabel summaryLabel = new JLabel("Summary:");
  private final JLabel locationLabel = new JLabel("Location:");
  private final JLabel classificationLabel = new JLabel("Classification (public/private/confidential):");
  private final JLabel dtstartLabel = new JLabel("Date Start (MM/DD/YYYY HH:MM):");
  private final JLabel dtendLabel = new JLabel("Date End (MM/DD/YYYY HH:MM):");
  private final JLabel priorityLabel = new JLabel("Priority (low/medium/high):");
  private final JTextField summaryTBox = new JTextField(250);
  private final JTextField locationTBox = new JTextField(30);
  private final JTextField classificationTBox = new JTextField(15);
  private final JTextField priorityTBox = new JTextField(6);
  private final JTextField dtstartTBox = new JTextField(16);
  private final JTextField dtendTBox = new JTextField(16);
  private final JButton createCal = new JButton("Create a new Calendar");
  private final JButton open = new JButton("Open a Calendar");
  private final JButton compare = new JButton("Compare a list of Calendars");
  private final JButton quit = new JButton("Quit");
  private final JButton create = new JButton("New Event");
  private final JButton done = new JButton("Done");
  private final JButton save = new JButton("Save Event");
  private final JButton cancel = new JButton("Cancel");
  private Calendar mycal;


  public GUI() throws IOException {
    setTitle("Main Menu");
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setResizable(false);
    setSize(550, 250);

    // Set button colors
    createCal.setBackground(Color.GREEN);
    compare.setBackground(Color.YELLOW);
    quit.setBackground(Color.RED);
    create.setBackground(Color.YELLOW);
    save.setBackground(Color.GREEN);
    done.setBackground(Color.GREEN);
    cancel.setBackground(Color.RED);

    Handler handle = new Handler();
    createCal.addActionListener(handle);
    open.addActionListener(handle);
    compare.addActionListener(handle);
    quit.addActionListener(handle);
    create.addActionListener(handle);
    done.addActionListener(handle);
    save.addActionListener(handle);
    cancel.addActionListener(handle);

    add(panel);
    panel.add(createCal);
    panel.add(open);
    panel.add(compare);
    panel.add(quit);
    setVisible(true);
  }


  /**
   * Resets the text fields of this window
   */
  public void resetText() {
    summaryTBox.setText(null);
    locationTBox.setText(null);
    classificationTBox.setText(null);
    dtstartTBox.setText(null);
    dtendTBox.setText(null);
    priorityTBox.setText(null);
  }


  /**
   * Updates GUI view to the main menu
   */
  public void goToMainMenu() {
    panel.removeAll();
    panel.add(createCal);
    panel.add(open);
    panel.add(compare);
    panel.add(quit);
    setTitle("Main Menu");
    panel.updateUI();
  }


  /**
   * Updates GUI view to the calendar menu
   */
  public void goToCalendarMenu() {
    panel.removeAll();
    panel.add(create);
    // panel.add(write);
    panel.add(done);
    setTitle("Calendar");
    panel.updateUI();
  }


  /**
   * Gets a file chosen by the user
   * 
   * @param title The title to display on the GUI menu
   * @return The File the user chooses
   * @throws Exception User pressed cancel
   */
  public File getFile(String title) throws Exception {
    JFileChooser fc = new JFileChooser();
    fc.setDialogTitle(title);
    int response = fc.showDialog(panel, "use");
    if (response == JFileChooser.APPROVE_OPTION) {
      return fc.getSelectedFile();
    }
    else {
      throw new Exception("File Operation cancelled");
    }
  }


  /**
   * Gets a file chosen by the user
   * 
   * @param title The title to display on the GUI menu
   * @return The File the user chooses
   * @throws Exception User pressed cancel
   */
  public File[] getFiles(String title) throws Exception {
    JFileChooser fc = new JFileChooser();
    fc.setDialogTitle(title);
    fc.setMultiSelectionEnabled(true);
    int response = fc.showDialog(panel, "use");
    if (response == JFileChooser.APPROVE_OPTION) {
      return fc.getSelectedFiles();
    }
    else {
      throw new Exception("File Operation cancelled");
    }
  }

  /**
   * Handles the GUI button actions
   * 
   * @author Justin
   *
   */
  private class Handler implements ActionListener {

    @Override
    public void actionPerformed(ActionEvent e) {
      if (e.getSource().equals(createCal)) {
        String fileName = JOptionPane.showInputDialog(panel, "Enter the Calendar name:");
        // catch cancel case
        fileName = fileName.concat(".ics");
        try {
          mycal = new Calendar(fileName);
        }
        catch (IOException e1) {
          dispose();
        }
        goToCalendarMenu();
      }
      else if (e.getSource().equals(open)) {
        File infile;
        try {
          infile = getFile("Open Calendar File");
          mycal = new Calendar(infile);
          goToCalendarMenu();
        }
        catch (IOException e1) {
          dispose();
        }
        catch (Exception e2) {
          goToMainMenu();
        }

      }
      else if (e.getSource().equals(compare)) {

        try {
          File[] files = getFiles("Choose the files to compare");
          String userDate = JOptionPane.showInputDialog("Enter the Date (MM/DD/YYYY):");
          // fileNames.add("event_1.ics");
          // fileNames.add("event_2.ics");

          // String date = "02/25/2015";

          try {
            compareICS(files, userDate);
          }
          catch (IOException e1) {
            dispose();
          }

        }
        catch (Exception e1) {
          dispose();
        }
      }
      else if (e.getSource().equals(quit)) {
        dispose();
      }
      else if (e.getSource().equals(create)) {
        panel.removeAll();

        // new stuff in the window
        setTitle("Event Information");
        summaryLabel.setLabelFor(summaryTBox);
        panel.add(summaryLabel);
        panel.add(summaryTBox);
        locationLabel.setLabelFor(locationTBox);
        panel.add(locationLabel);
        panel.add(locationTBox);
        classificationLabel.setLabelFor(classificationTBox);
        panel.add(classificationLabel);
        panel.add(classificationTBox);
        priorityLabel.setLabelFor(priorityTBox);
        panel.add(priorityLabel);
        panel.add(priorityTBox);
        dtstartLabel.setLabelFor(dtstartTBox);
        panel.add(dtstartLabel);
        panel.add(dtstartTBox);
        dtendLabel.setLabelFor(dtendTBox);
        panel.add(dtendLabel);
        panel.add(dtendTBox);
        panel.add(cancel);
        panel.add(save);
        panel.updateUI();
      }
      else if (e.getSource().equals(done)) {
        goToMainMenu();
      }
      else if (e.getSource().equals(cancel)) {
        setTitle("Calendar");
        resetText();
        goToCalendarMenu();
      }
      else if (e.getSource().equals(save)) {
        // prompt for confirmation
        int num = JOptionPane.showConfirmDialog(panel, "Are you sure???");
        boolean success = true; // based on the validity of user input
        if (num == JOptionPane.YES_OPTION) {
          // read in user input
          String summary = summaryTBox.getText().trim();
          String location = locationTBox.getText().trim();
          String classification = classificationTBox.getText().trim().toUpperCase();
          String dtstart = dtstartTBox.getText().trim();
          String dtend = dtendTBox.getText().trim();
          String priority = priorityTBox.getText().trim();

          // validate user input
          if (!UluCalendar.isClassification(classification)) {
            JOptionPane.showMessageDialog(panel, "Please Re-Enter the Classification");
            success = false;
          }
          if (!UluCalendar.isPriority(priority)) {
            JOptionPane.showMessageDialog(panel, "Please Re-Enter the Priority");
            success = false;
          }
          if (!UluCalendar.isDateTime(dtstart)) {
            JOptionPane.showMessageDialog(panel, "Please Re-Enter the Start Date");
            success = false;
          }
          if (!UluCalendar.isDateTime(dtend)) {
            JOptionPane.showMessageDialog(panel, "Please Re-Enter the End Date");
            success = false;
          }
          if (success) {

            Event temp = new Event(classification, location, priority, summary, dtstart, dtend);
            mycal.insertEvent(temp);
            resetText();
            goToCalendarMenu();
          }
          else {
            JOptionPane.showMessageDialog(panel, "Please Try Again");
          }
        }
        else if (num == JOptionPane.CANCEL_OPTION) {
          resetText();
          goToCalendarMenu();
        }
        else {
          // case where user enters no
          // reset text fields
          resetText();
        }
      }
      /********************************************** END SAVE ******************************************************************/

    }


    private void compareICS(File files[], String date) throws IOException {

      int x, y;
      int month, day, year;
      int temp, temp2;
      String startString;
      String endString;

      ArrayList<Calendar> list = new ArrayList<Calendar>();

      ArrayList<Integer> startTime = new ArrayList<Integer>();
      ArrayList<Integer> endTime = new ArrayList<Integer>();

      Calendar freeTime = new Calendar("free_time.ics");

      month = Integer.parseInt(date.split("/")[0]);
      day = Integer.parseInt(date.split("/")[1]);
      year = Integer.parseInt(date.split("/")[2]);

      for (x = 0; x < files.length; x++) {
        list.add(new Calendar(files[x]));

        for (y = 0; y < list.get(x).event.size(); y++) {
          temp = Integer.parseInt(list.get(x).event.get(y).dtstart.substring(0, 4));

          // System.out.println("year");
          // System.out.println(temp);
          // System.out.println(year);

          if (temp != year)
            continue;

          temp = Integer.parseInt(list.get(x).event.get(y).dtstart.substring(4, 6));

          // System.out.println("month");
          // System.out.println(temp);
          // System.out.println(month);

          if (temp != month)
            continue;

          temp = Integer.parseInt(list.get(x).event.get(y).dtstart.substring(6, 8));

          // System.out.println("day");
          // System.out.println(temp);
          // System.out.println(day);

          if (temp != day)
            continue;

          // System.out.println("Adding Event");

          startTime.add(Integer.parseInt(list.get(x).event.get(y).dtstart.substring(9, 13)));
          endTime.add(Integer.parseInt(list.get(x).event.get(y).dtend.substring(9, 13)));

        }

      }

      Collections.sort(startTime);
      Collections.reverse(startTime);
      Collections.sort(endTime);
      Collections.reverse(endTime);

      // for (int counter: startTime) {
      // System.out.println(counter);
      // }
      //
      // for (int counter: endTime) {
      // System.out.println(counter);
      // }

      if (!endTime.isEmpty()) {
        if ((temp = endTime.remove(0)) < 2400) {
          if (temp < 1000) {
            startString =
                date + " " + Integer.toString(temp).substring(0, 1) + ":" + Integer.toString(temp).substring(1, 3);
          }

          else if (temp < 100) {
            startString = date + " 00" + ":" + Integer.toString(temp).substring(0, 2);
          }

          else if (temp < 10) {
            startString = date + " 00" + ":0" + Integer.toString(temp).substring(0, 1);
          }

          else {
            startString =
                date + " " + Integer.toString(temp).substring(0, 2) + ":" + Integer.toString(temp).substring(2, 4);
          }

          freeTime.insertEvent(new Event("public", "", "low", "free time", startString, date + " 24:00"));

        }
      }

      while (!endTime.isEmpty()) {
        if ((temp = endTime.remove(0)) < (temp2 = startTime.remove(0))) {
          if (temp < 1000) {
            startString =
                date + " " + Integer.toString(temp).substring(0, 1) + ":" + Integer.toString(temp).substring(1, 3);
          }

          else if (temp < 100) {
            startString = date + " 00" + ":" + Integer.toString(temp).substring(0, 2);
          }

          else if (temp < 10) {
            startString = date + " 00" + ":0" + Integer.toString(temp).substring(0, 1);
          }

          else {
            startString =
                date + " " + Integer.toString(temp).substring(0, 2) + ":" + Integer.toString(temp).substring(2, 4);
          }

          if (temp2 < 1000) {
            endString =
                date + " " + Integer.toString(temp2).substring(0, 1) + ":" + Integer.toString(temp2).substring(1, 3);
          }

          else if (temp2 < 100) {
            endString = date + " 00" + ":" + Integer.toString(temp2).substring(0, 2);
          }

          else if (temp2 < 10) {
            endString = date + " 00" + ":0" + Integer.toString(temp2).substring(0, 1);
          }

          else {
            endString =
                date + " " + Integer.toString(temp2).substring(0, 2) + ":" + Integer.toString(temp2).substring(2, 4);
          }
          freeTime.insertEvent(new Event("public", "", "low", "free time", startString, endString));
        }

      }

      if (!startTime.isEmpty()) {
        // System.out.println("last start time");
        // System.out.println(startTime.get(0));
        if ((temp = startTime.remove(0)) > 0) {
          // System.out.println("inserting event");
          // System.out.println(temp);

          if (temp < 1000) {
            endString =
                date + " " + Integer.toString(temp).substring(0, 1) + ":" + Integer.toString(temp).substring(1, 3);
          }

          else if (temp < 100) {
            endString = date + " 00" + ":" + Integer.toString(temp).substring(0, 2);
          }

          else if (temp < 10) {
            endString = date + " 00" + ":0" + Integer.toString(temp).substring(0, 1);
          }

          else {
            endString =
                date + " " + Integer.toString(temp).substring(0, 2) + ":" + Integer.toString(temp).substring(2, 4);
          }

          freeTime.insertEvent(new Event("public", "", "low", "free time", date + " 00:00", endString));
          // System.out.println("finish insert");
        }

        // else {
        // System.out.println("no event");
        // }
      }

      // System.out.println("Finish");
      JOptionPane.showMessageDialog(panel, "Finished");

    }

  }

}
