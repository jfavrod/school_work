import java.io.IOException;


public class UluCalendar {

  public static void main(String[] args) {

    try {
      GUI myWindow = new GUI();
      myWindow.setLocationRelativeTo(null);
    }
    catch (IOException e) {
      e.printStackTrace();
    }
  }
  
  /**
   * isClassification
   *
   * Determines whether or not the given argument is a valid classification (public, private, confidential) and returns
   * true or false accordingly.
   *
   * @param String classification A classification string to test.
   * @return boolean response True valid classification, false otherwise.
   */

  public static boolean isClassification(String classification) {
    boolean response = false;

    classification = classification.toLowerCase();
    if (classification.equals("public") || classification.equals("private") || classification.equals("confidential")) {
      response = true;
    }
    else {
      System.out.println("Invalid Classification!");
    }

    return response;
  }


  /**
   * isPriority
   *
   * Determines whether or not the given argument is a valid priority (high, medium, low) and returns true or false
   * accordingly.
   *
   * @param String priority A priority string to test.
   * @return boolean response True valid priority, false otherwise.
   */

  public static boolean isPriority(String priority) {
    boolean response = false;

    priority = priority.toLowerCase();
    if (priority.equals("high") || priority.equals("medium") || priority.equals("low")) {
      response = true;
    }
    else {
      System.out.println("Invalid Priority");
    }

    return response;
  }


  /**
   * isDateTime
   *
   * Checks whether or not the give string is a valid date time string.
   *
   * @param String dateTimeString The string to check for validity.
   * @return boolean True if valid, false otherwise.
   */

  public static boolean isDateTime(String dateTime) {
    String[] temp = new String[2];
    String[] date = new String[3];
    String[] time = new String[2];
    int month, day, year;
    int hour, minute;

    temp = dateTime.split(" ");
    if (temp.length != 2)
      return false;
    date = temp[0].split("/");
    if (date.length != 3)
      return false;
    time = temp[1].split(":");
    if (time.length != 2)
      return false;

    try {
      month = Integer.parseInt(date[0]);
      day = Integer.parseInt(date[1]);
      year = Integer.parseInt(date[2]);
      hour = Integer.parseInt(time[0]);
      minute = Integer.parseInt(time[1]);
    }
    catch (NumberFormatException e) {
      return false;
    }

    if (month < 0 || day < 0 || year < 0 || hour < 0 || minute < 0)
      return false;
    if (month > 12 || day > 31 || hour > 24 || minute > 59)
      return false;

    return true;
  }

}
