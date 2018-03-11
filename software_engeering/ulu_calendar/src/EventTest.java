import static org.junit.Assert.*;
import org.junit.Test;


public class EventTest {

  @Test
  public void testEvent() {
    Event test = new Event();
    boolean result = true;
    result = result && test.classification.equals("PUBLIC");
    result = result && test.version.equals("2.0");
    result = result && test.priority == 0;
  
    assertTrue(result);
  }
  
  @Test
  public void testEventStringVersion() {
    Event test = new Event("test event");
    boolean result = true;
    result = result && test.classification.equals("PUBLIC");
    result = result && test.version.equals("2.0");
    result = result && test.priority == 0;
    result = result && test.summary.equals("test event");
  
    assertTrue(result);
  }
  
  @Test
  public void testEventMultiStringVersion() {
    Event test = new Event("public", "test location", "low", "test summary", "1/1/1111 1:11", "2/2/2222 2:22");
    boolean result = true;
    result = result && test.classification.equals("public");
    result = result && test.version.equals("2.0");
    result = result && test.priority == 9;
    result = result && test.summary.equals("test summary");
    result = result && test.location.equals("test location");
    result = result && test.dtstart.equals("11110101T011100z");
    result = result && test.dtend.equals("22220202T022200z");
  
    assertTrue(result);
  }
  
  
  @Test
  public void testGetClassification() {
    Event test = new Event();
    test.classification = "test";
    
    assertEquals(test.classification, test.getClassification());
  }


  @Test
  public void testSetClassification() {
    Event test = new Event();
    test.setClassification("test");
    
    assertEquals("test", test.classification);
  }


  @Test
  public void testGetVersion() {
    Event test = new Event();
    
    assertEquals("2.0", test.getVersion());
  }


  @Test
  public void testGetLocation() {
    Event test = new Event();
    test.location = "test";
    
    assertEquals(test.location, test.getLocation());
  }


  @Test
  public void testSetLocation() {
    Event test = new Event();
    test.setLocation("test");
    
    assertEquals("test", test.location);
  }


  @Test
  public void testGetPriority() {
    Event test = new Event();
    test.priority = 5;
    
    assertEquals(test.priority, test.getPriority());
  }


  @Test
  public void testSetPriority() {
    Event test = new Event();
    test.setPriority("low");
    
    assertEquals(9, test.priority);
  }


  @Test
  public void testGetSummary() {
    Event test = new Event();
    test.summary = "test";
    
    assertEquals(test.summary, test.getSummary());
  }


  @Test
  public void testSetSummary() {
    Event test = new Event();
    test.setSummary("test");
    
    assertEquals("test", test.summary);
  }


  @Test
  public void testGetDtstart() {
    Event test = new Event();
    test.dtstart = "test";
    
    assertEquals(test.dtstart, test.getDtstart());
  }


  @Test
  public void testSetDtstart() {
    Event test = new Event();
    test.setDtstart("1/1/1111 1:11");
    
    assertEquals("11110101T011100z", test.dtstart);
  }


  @Test
  public void testGetDtend() {
    Event test = new Event();
    test.dtend = "test";
    
    assertEquals(test.dtend, test.getDtend());
  }


  @Test
  public void testSetDtend() {
    Event test = new Event();
    test.setDtend("1/1/1111 1:11");
    
    assertEquals("11110101T011100z", test.dtend);
  }

}
