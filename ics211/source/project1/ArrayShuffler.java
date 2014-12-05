import java.util.Random;
public class ArrayShuffler {
   private static Random random;
   
   static {
      random = new Random(System.currentTimeMillis());
   }

   public static void shuffle(Object[] a) {
        int len = a.length;
        for (int i = 0; i < len; i++) {
            int r = i + random.nextInt(len-i);     // between i and len-1
            Object temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }

}
