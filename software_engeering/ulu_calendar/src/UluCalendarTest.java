import static org.junit.Assert.*;
import org.junit.Test;

public class UluCalendarTest {

  @Test
  public void isClassificationTest() {

    //  Valid test cases
    boolean result = UluCalendar.isClassification("public") && UluCalendar.isClassification("private");
    result = result && UluCalendar.isClassification("confidential") && UluCalendar.isClassification("PUBLIC");
    result = result && UluCalendar.isClassification("PRIVATE") && UluCalendar.isClassification("CONFIDENTIAL");
    
    //  Invalid test cases
    result = result && !UluCalendar.isClassification("pub5lic") && !UluCalendar.isClassification("pri2vate");
    result = result && !UluCalendar.isClassification("con5fidential") && !UluCalendar.isClassification("test");
    result = result && !UluCalendar.isClassification("5");
    
    assertTrue(result);

  }


  @Test
  public void isPriorityTest() {

    //  Valid test cases
    boolean result = UluCalendar.isPriority("low") && UluCalendar.isPriority("medium");
    result = result && UluCalendar.isPriority("high") && UluCalendar.isPriority("LOW");
    result = result && UluCalendar.isPriority("MEDIUM") && UluCalendar.isPriority("HIGH");
    
    //  Invalid test cases
    result = result && !UluCalendar.isPriority("hi5gh") && !UluCalendar.isPriority("LO2W");
    result = result && !UluCalendar.isPriority("9") && !UluCalendar.isPriority("test");

    assertTrue(result);

  }
  
  @Test
  public void isDateTimeTest() {
    //  Valid date tests
    boolean result = UluCalendar.isDateTime("1/1/1900 2:00") && UluCalendar.isDateTime("01/01/1900 02:00");
    result = result && UluCalendar.isDateTime("00/00/0000 00:00") && UluCalendar.isDateTime("12/31/9999 24:59"); 
    
    //  Invalid date tests
    result = result && !UluCalendar.isDateTime("1/1/1900 25:00") && !UluCalendar.isDateTime("12/31/9999 345:00");
    result = result && !UluCalendar.isDateTime("1/1/1900") && !UluCalendar.isDateTime("13/31/9999 2:00");
    result = result && !UluCalendar.isDateTime("12/32/9999 2:00") && !UluCalendar.isDateTime("12/25/99995 2:60");
    result = result && !UluCalendar.isDateTime("123/31/9999 2:00") && !UluCalendar.isDateTime("12/315/9999 2:00");
    result = result && !UluCalendar.isDateTime("12/31/9999 236:00") && !UluCalendar.isDateTime("12/31/9999 2:369");
    result = result && !UluCalendar.isDateTime("12//9999 2:00") && !UluCalendar.isDateTime("/31/9999 2:00");
    result = result && !UluCalendar.isDateTime("12/25/ 2:00") && !UluCalendar.isDateTime("5/31/9999 :00");
    result = result && !UluCalendar.isDateTime("12/25/1236 2:") && !UluCalendar.isDateTime("5/31/9999 2.5:00");
    result = result && !UluCalendar.isDateTime("12.5/25/1236 2:00") && !UluCalendar.isDateTime("5/31.5/9999 2:00");
    result = result && !UluCalendar.isDateTime("12/25/1236.5 2:00") && !UluCalendar.isDateTime("5/31/9999 2:1.5");
    result = result && !UluCalendar.isDateTime("0j5/05/0005 05:05") && !UluCalendar.isDateTime("12/3j1/9999 24:59");
    result = result && !UluCalendar.isDateTime("05/05/0j05 05:05") && !UluCalendar.isDateTime("12/31/9999 2j4:59");
    result = result && !UluCalendar.isDateTime("05/05/0005 05:0j0") && !UluCalendar.isDateTime("12/31/9999 24:59j");
    result = result && !UluCalendar.isDateTime("January 5, 1960 3:00") && !UluCalendar.isDateTime("test");
    
    assertTrue(result);
  }

}
