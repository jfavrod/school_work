/**
 *
 * @author Noel Niles
 */
public class Diamond {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String x = " ";//empty spaces
        String y = "*";//asterisks form the shape
        int rows = 7;//height of top triangle; larger value is taller
        
        //print the top half of the diamond(AKA a triangle)
        for(int j = 0; j < rows; j++) {
            String space = string_repeat(x, rows - j - 1);
            String star = string_repeat(y, 2 * j + 1);
            System.out.println(space + star);
        }
        //print the bottom half of the diamond
        for(int h = rows-2; h >= 0; h--) {
            String space = string_repeat(x, rows - h - 1);
            String star = string_repeat(y, 2 * h + 1);
            System.out.println(space + star);       
        }    
    }
    
    /**
     * Utility functions to multiply strings like in python
     * 
     * usage: string_repeat(String [str], int [multiple])
     * ex: string_repeat('foo', 3)
     *  >>>foofoofoo
     */
    
    public static String string_repeat(String str, int length) {
        
        StringBuilder outputBuffer;
        outputBuffer = new StringBuilder(length);//sets the compacity of the secquence of characters
        
        for (int i = 0; i < length; i++){
            outputBuffer.append(str);
        }
        return outputBuffer.toString();
    }   
}
