import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.lang.NoSuchFieldException;


public class Helper
{
    public static int countLines(File file) throws IOException {
        int c = 0;
        int lineCount = 0;
        boolean empty = true;
        InputStream istream = new BufferedInputStream(new FileInputStream(file));

        while ((c = istream.read()) != -1) {
            empty = false;
            if ('\n' == c) {
                ++lineCount;
            }
        }

        istream.close();
        return lineCount;
    }


    public static boolean deleteLastLine(File file, int lineCount) throws FileNotFoundException, IOException {
        boolean result = true;

        if (lineCount <= 0) {
            result = false;
        }

        int tmpChar = 0; 
        File tmpFile = new File(file.getParentFile(), ".tmp.txt");
        FileReader freader = new FileReader(file);
        FileWriter fwriter = new FileWriter(tmpFile);

        for (int i = 0; i < (lineCount - 1); i++) {
            while ((tmpChar = freader.read()) != '\n') {
                fwriter.write(tmpChar);
            }
            fwriter.write('\n');
        }

        fwriter.flush();
        fwriter.close();
        freader.close();
        file.delete();
        tmpFile.renameTo(file);

        return result;
    }


    public static void appendStringToFile(String string, File file) throws IOException {
        FileWriter out = new FileWriter(file, true);
        out.write(string);
        out.flush();
        out.close();
    }
}
