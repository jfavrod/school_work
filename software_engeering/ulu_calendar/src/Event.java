/**
 * An iCalendar Event. Provides a grouping of component properties that describe an event.
 */

class Event {
  /**
   * PUBLIC, PRIVATE, or CONFIDENTIAL Default: PUBLIC
   */
  public String classification;
  /**
   * 2.0
   */
  public String version;
  public String location;
  /**
   * Contains a value between 0-9 0 - undefined 1 - highest priority 9 - lowest priority
   */
  public int priority;
  public String summary;
  public String dtstart;
  public String dtend;


  public Event() {
    classification = "PUBLIC";
    version = "2.0";
    priority = 0;
    location = new String();
    summary = new String();
    dtstart = new String();
    dtend = new String();
  }


  public Event(String name) {
    classification = "PUBLIC";
    version = "2.0";
    priority = 0;
    location = new String();
    summary = name;
    dtstart = new String();
    dtend = new String();
  }
  
  public Event(String classification, String location, String priority, String summary, String dtstart, String dtend) {
    version = "2.0";
    setClassification(classification);
    setLocation(location);
    setPriority(priority);
    setSummary(summary);
    setDtstart(dtstart);
    setDtend(dtend);
   }



  public String getClassification() {
    return classification;
  }


  public void setClassification(String classification) {
    this.classification = classification;
  }


  public String getVersion() {
    return version;
  }


  public String getLocation() {
    return location;
  }


  public void setLocation(String location) {
    this.location = location;
  }


  public int getPriority() {
    return priority;
  }


  public void setPriority(String priority) {
    if (priority.equalsIgnoreCase("low")) {
      this.priority = 9;
    }
    else if (priority.equalsIgnoreCase("medium")) {
      this.priority = 5;
    }
    else if (priority.equalsIgnoreCase("high")) {
      this.priority = 1;
    }
    else {
      this.priority = 0;
    }
  }


  public String getSummary() {
    return summary;
  }


  public void setSummary(String summary) {
    this.summary = summary;
  }


  public String getDtstart() {
    return dtstart;
  }


  public void setDtstart(String dtstart) {

    this.dtstart = convertDTStringToICSFormat(dtstart);
  }
  

  public String getDtend() {
    return dtend;
  }


  public void setDtend(String dtend) {
    this.dtend = convertDTStringToICSFormat(dtend);
  }

  protected String convertDTStringToICSFormat(String userdate) {
    String[] temp, date, time;
    String newDate = "";
    int month, day, year, hour, minute;

    temp = userdate.split(" ");
    date = temp[0].split("/");
    time = temp[1].split(":");

    month = Integer.parseInt(date[0]);
    day = Integer.parseInt(date[1]);
    year = Integer.parseInt(date[2]);
    hour = Integer.parseInt(time[0]);
    minute = Integer.parseInt(time[1]);

    if (year < 1000) {
      newDate = newDate.concat("0" + Integer.toString(year));
    }
    else if (year < 100) {
      newDate = newDate.concat("00" + Integer.toString(year));
    }
    else if (year < 10 && year != 0) {
      newDate = newDate.concat("000" + Integer.toString(year));
    }
    else {
      newDate = newDate.concat(date[2]);
    }
    if (month < 10 && month != 0) {
      newDate = newDate.concat("0" + Integer.toString(month));
    }
    else {
      newDate = newDate.concat(Integer.toString(month));
    }
    if (day < 10 && day != 0) {
      newDate = newDate.concat("0" + Integer.toString(day));
    }
    else {
      newDate = newDate.concat(date[1]);
    }
    newDate = newDate.concat("T");
    if (hour < 10 && hour != 0) {
      newDate = newDate.concat("0" + Integer.toString(hour));
    }
    else {
      newDate = newDate.concat(time[0]);
    }
    if (minute < 10 && minute != 0) {
      newDate = newDate.concat("0" + Integer.toString(minute));
    }
    else {
      newDate = newDate.concat(time[1]);
    }
    newDate = newDate.concat("00z");
    return newDate;
  }



  @Override
  public String toString() {
    return "BEGIN:VEVENT\r\n" + "DTSTART:" + dtstart + "\r\n" + "DTEND:" + dtend + "\r\n" + "CLASS:"
        + classification + "\r\n" + "PRIORITY:" + priority + "\r\n" + "LOCATION:" + location + "\r\n" + "SUMMARY:" + summary + "\r\n" + "END:VEVENT\r\n";
  }
}
