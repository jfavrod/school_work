import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Calendar {
  protected File icsFile = null;
  protected FileWriter out = null;
  protected ArrayList<Event> event = new ArrayList<Event>();


  public Calendar() throws IOException {
    // calls the constructor with the given string (eg. Calendar("calendar.ics"))
    this("calendar.ics");
  }


  public Calendar(String file) throws IOException {
    icsFile = new File(file);
    event = new ArrayList<Event>();

    if (!icsFile.exists()) {
      createICSFile();
    }
    else {
      // if it does exist parse the file and add the events.
      loadEvents();
    }
  }


  public Calendar(File infile) throws IOException {
    icsFile = infile;
    event = new ArrayList<Event>();

    if (!icsFile.exists()) {
      createICSFile();
    }
    else {
      // if it does exist parse the file and add the events.
      loadEvents();
    }
  }


  /**
   * createICSFile
   *
   * Creates a formatted ics file.
   *
   * @param FILE icsFile The file object with the path to where the ics file will be created.
   * @return boolean True if created successfully, false otherwise.
   * @throws IOException
   *
   */

  protected boolean createICSFile() {
    try {
      icsFile.createNewFile();
      out = new FileWriter(icsFile);
      out.write("BEGIN:VCALENDAR\r\n");
      out.write("VERSION:2.0\r\n");
      out.write("END:VCALENDAR\r\n");
      out.flush();
      out.close();
    }
    catch (IOException ioe) {
      return false;
    }
    return true;
  }


  /**
   * insertEvent
   *
   * Takes an Event object and inserts a text representation of if to the .ics file.
   *
   * @param Event event The event object to write to the disk.
   * @return boolean True if successful, false otherwise.
   */

  public boolean insertEvent(Event event) {
    try {
      Helper.deleteLastLine(icsFile, Helper.countLines(icsFile));
      Helper.appendStringToFile(event.toString(), this.icsFile);
      Helper.appendStringToFile("END:VCALENDAR\r\n", this.icsFile);
      this.event.add(event);
    }
    catch (IOException e) {
      return false;
    }
    return true;
  }


  /**
   * deleteEvent
   *
   * Deletes an event from the icsFile.
   *
   * @return boolean True if successful, false otherwise.
   */

  public boolean deleteEvent() {
    return true;
  }


  /**
   * printEvents
   *
   * Prints the userCalender events.
   *
   * @param void
   * @return void
   */

  public void printEvents() {

  }


  /**
   * gets the events from the file
   * 
   * @throws FileNotFoundException
   */
  private void loadEvents() throws FileNotFoundException {
    Scanner scan = new Scanner(icsFile);
    scan.useDelimiter("\n");
    while (scan.hasNext()) {
      String temp = scan.next().trim();
      if (temp.compareTo("BEGIN:VEVENT") == 0) {
        Event newEvent = new Event();
        String[] str = new String[2];
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.dtstart = str[1];
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.dtend = str[1];
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.setClassification(str[1]);
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.priority = Integer.parseInt(str[1]);
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.setLocation(str[1]);
        temp = scan.next().trim();
        str = temp.split(":");
        newEvent.setSummary(str[1]);
        event.add(newEvent);
      }
    }
    scan.close();
  }
}
