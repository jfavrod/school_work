public class scratch 
{
    public static void main (String args[])
    {
        String[] array = new String[4];
        array[0] = "palce0";
        array[1] = "palce1";
        array[2] = "palce2";
        array[3] = "palce3";
        
        for (int i = 0; i< array.length; i = i+2) {
            System.out.printf("%30s %30s \n", array[i], array[i+1]);
        }
    }
}

