//***************************
//
// Yuko Honda
//
// 1. Yes. The speed of sorting were not greatly affected by the size of arguments entered. That results shows
//    the sorting is showing order of (n log(n)) performance.
// 2. No. When tested, Mergesort time did not increase by much.  Mergesort makes smaller piles of things to sort and combine
//    them together at the end, so unless the size of an array is increased, sorting does not take long.
// 3. Quicksort performance depends on the range of spyNumber but not on the spyCode, because quicksort compares one element
//    by one element and go through the process one by one, it takes longer.  It does not matter how many letters are used in
//    a code.
// 4. I was not able to sort an array of 10,000,000.  Even when I implemented -Xmx850m.  I had to shut everything down to get out
//    of it and lost my comments...  
//
//****************************
import ics211package.Stopwatch;
import ics211package.Spy;
import ics211package.ArrayShuffler;
class Lab3 {
   static Spy[] b;
   public static void main(String[] args) {
      int n = 0;
      int maxNumber = 0;
      int maxLetters = 0;
      try {
         n = Integer.parseInt(args[0]);
         maxNumber = Integer.parseInt(args[1]);
         maxLetters = Integer.parseInt(args[2]);
      }
      catch (ArrayIndexOutOfBoundsException e) {
         System.out.println("Usage: java Lab3 n maxNum maxLetters");
         System.exit(1);
      }
      Stopwatch watch = new Stopwatch();
      Spy[] spies = new Spy[n];
      b = new Spy[n];
      for (int i = 0; i < n; i++) {
         spies[i] = new Spy(maxNumber,maxLetters);
      }
      System.out.println("Time to generate array: " + 
         watch.elapsedTime());
      System.out.println("Before sorting, array sorted? " +
         isSorted(spies));
      watch = new Stopwatch();
      mergeSort(spies,0,spies.length-1);
      System.out.println("Time to mergesort: " +
         watch.elapsedTime());
      System.out.println("After Mergesort, Array sorted? " + isSorted(spies));
      watch = new Stopwatch();
      ArrayShuffler.shuffle(spies);
      System.out.println("Time to shuffle array: " +
         watch.elapsedTime());
      System.out.println("Array sorted after shuffle? " + isSorted(spies));
      watch = new Stopwatch();
      mergeSort(spies,0,spies.length-1);
      System.out.println("Time to Quicksort: " +
         watch.elapsedTime());
      System.out.println("After Quicksort, Array sorted? " + isSorted(spies));
   }
   public static void merge(Spy[] a, int low, int mid, int high) {
      for (int k = low; k <= high; k++) {
         b[k] = a[k];
      }
      int i = low;
      int j = mid+1;
      for (int k = low; k <= high; k++) {
         if (i > mid) {
            a[k] = b[j++];
         }
         else if (j > high) {
            a[k] = b[i++];
         }
         else if (b[i].compareTo(b[j]) < 0) {
            a[k] = b[i++];
         }
         else {
            a[k] = b[j++];
         }
      }
   }
   public static void mergeSort(Spy[] a, int low, int high) {
      if (low == high) {
         return;
      }
      int mid = (low + high)/2;
      mergeSort(a,low,mid);
      mergeSort(a,mid+1,high);
      merge(a,low,mid,high);
   }
   
   public static int partition(Spy[] a, int low, int high) {
      int i = low;
      int j = high--;
      Spy pivot = a[high];
      boolean done = false;
         while (i < high && a[i].compareTo(pivot) <= 0)
          i++; {
      
          while (j > low && a[j].compareTo(pivot) >= 0)
          j--; {
         
            if (i < j) {
              Spy temp = a[i];
              a[i] = a[j];
              a[j] = temp;
            }
            else 
              done = true;
          }
          a[high] = a[i];
          a[i] = pivot;
       }  
       return i;
   }
   
   
   public static void quickSort(Spy[] a, int low, int high) {
      if (low >= high)
         return;
      int pivotPos = partition(a, low, high);
      quickSort(a, low, pivotPos--);
      quickSort(a, pivotPos++, high);
   }
   private static boolean isSorted(Spy[] a) {
      boolean sorted = true;
      for (int i = 0; i < a.length - 1; i++) {
         if (a[i].compareTo(a[i+1]) > 0) {
            sorted = false;
            break;
         }
      }
      return sorted;
   }
   private static void print(Spy[] a) {
      for (Spy spy : a) {
         System.out.println(spy);
      }
      System.out.println("");
   }
}
