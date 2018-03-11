import static org.junit.Assert.*;
import java.io.IOException;
import org.junit.Test;

public class CalendarTest
{
  @Test
  public void insertEventTest() {
    try {
      Calendar mycal = new Calendar();
      Event temp = new Event("public", "location", "low", "test", "1/1/1 1:1", "2/2/2 2:2");
      assertEquals(true, mycal.insertEvent(temp));
    }
    catch (IOException e) {
      fail();
    }
    
  }
}
