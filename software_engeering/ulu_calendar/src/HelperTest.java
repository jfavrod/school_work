import static org.junit.Assert.assertEquals;
import org.junit.Test;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;


public class HelperTest {
  private Helper helper = new Helper();

  @Test
  public void countsLinesInFile() {
    int lines = 0;
    File testFile = null;
    FileWriter fw = null;

    try {
      testFile = new File(".helperTest");
      fw       = new FileWriter(testFile);

      testFile.createNewFile();
      fw.write("This\nfile\nhas\n5\nlines.\n");
      fw.flush();
      fw.close();

      lines = helper.countLines(testFile);
      testFile.delete();
    }
    catch (IOException iox) {
      System.out.println("IO Exception");
    }

    assertEquals(5, lines);
  }
}
