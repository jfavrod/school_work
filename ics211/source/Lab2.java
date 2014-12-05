/* ICS211 Lab 2
 *
 * Student: Jason Favrod
 *
 * Lab2 takes three commandline arguments. The first determines how
 * many Spy objects will be created, the second argument sets the
 * size of the int spyNumber, and the final argument provides the
 * parameters for the number of different characters in spyCode
 * starting at char 64 (A).
 *
 * With the parameters properly set, the program creates the Spies
 * according to the given arguments and then performs the following
 * activities (timed activities noted):
 *
 * *Creates a sorted array of Spy Objects, named spies[] (timed)
 * *Creates a Spy Object named key used as a search key
 * *Performs a linear search in the spies[] array for key (timed)
 * *Performs a binary search in the spies[] array for key (timed)
 * *Sorts spies array (timed).
 *
 * These activities provide the user with notification that the 
 * action was performed and the time it took (if timed).
 *
 * The linear and binary searches perform at roughly the same speed
 * while the spies array is relatively non-complex. As the spies array
 * is configured to be created with Spies of a greater and greater
 * message space binary search performs the search faster.
 *
 * Sometimes there will be a match found by linear search in a different
 * position than a match found in binary search. This is because of differing
 * methods each search employs. Linear simply starts at the begining and
 * checks if each item matchs the key. Binary search begins by bisecting the
 * array and beginning its search in the middle.
 * As the code is written, it is possible to create two identical 
 * Spy Objects, and these two or more twins must be located at different
 * positions in the spies array, therefore the linear search finds the
 * first occurance (if searching from 0) while binary search finds a key
 * in some bisection of the array later on down the line.
 *
 * e.g.
 * spies[10]
 * [key, x, x, x, x, key, x, x, x, x, x]
 *
 * with the simple example above the key would be found by linear and binary
 * search in the first comparison of either method, but binary search finds a
 * key at position 10 and linear search at position 0.
 *
 *
 * As stated above, increasting the size of the parameters of the main, spies[]
 * creating method increases the Spy objects message space, therefore each
 * spy object in the array has higher entropy and needs more computing power
 * to generate and make comparisons with (that's why spies use really big PRIME 
 * numbers).
 */
import ics211package.Stopwatch;
import ics211package.Spy;
import java.util.Arrays;

class Lab2 {

   public static void main(String[] args) {
      int n = 0;
      int maxNumber = 0;
      int maxLetter = 0;
      try {
         n = Integer.parseInt(args[0].trim());
         maxNumber = Integer.parseInt(args[1].trim());
         maxLetter = Integer.parseInt(args[2].trim());
      }
      catch (ArrayIndexOutOfBoundsException e) {
         System.out.println("Usage: java Lab2 size maxNum maxLetter");
         System.out.println("where size is the size of the array");
         System.out.println("and maxNum is the maximum number " +
                            "for the spyNumber");
         System.out.println("and maxLetter is the number of different"+
                            "letters the spyCode can consist of");
         System.exit(1);
      }
      maxNumber = Integer.parseInt(args[1]);
      maxLetter = Integer.parseInt(args[2]);
      Spy[] spies = new Spy[n];
      Stopwatch watch = new Stopwatch();
      //Lets create some Spies
      for (int i = 0; i < spies.length; i++) {
         spies[i] = new Spy(maxNumber,maxLetter);
      }
      Arrays.sort(spies);
      System.out.println("Time to create array: " +
                         watch.elapsedTime());
      Spy key = new Spy(maxNumber,maxLetter);
      System.out.println(key);
      watch.reset();
      int position = linearSearch(spies, key);
      System.out.println("Elapsed time for linear search " + 
         watch.elapsedTime());
      if (position < 0) {
         System.out.println("Key not found");
      }
      else {
         System.out.println("Key found at " + position);
         System.out.println(spies[position]);
      }
      watch.reset();
      position = binarySearch(spies, key);
      System.out.println("Elapsed time for binary search " +
              watch.elapsedTime());
      if (position < 0) {
         System.out.println("Key not found");
      }
      else {
         System.out.println("Key found at " + position);
         System.out.println(spies[position]);
      } 
      watch.reset();
      Arrays.sort(spies);
      System.out.println("Time to sort array " +
         watch.elapsedTime());
   }
   
   public static int linearSearch(Spy[] a, Spy key) {
      for (int i = 0; i < a.length; i++) {
         if (a[i].compareTo(key) == 0) {
            return i;
         }
      }
      return -1;
   }

    public static int binarySearch(Spy[] a, Spy key) {
        int start = 0, end = (a.length - 1), result = 1;

        while (result == 1) {
            int mid = (start + end)/2;
            int compVal = key.compareTo(a[mid]);
            if (compVal == 0)  {
                System.out.println("match found " + a[mid]);
                return mid;
            }
            else if (compVal < 0) {
                end = mid - 1;
            }
            else if (compVal > 0) {
                start = mid + 1;
            }
            if (start >= end) {
                result = -1;
            }
        }
        return result;
    }
}
