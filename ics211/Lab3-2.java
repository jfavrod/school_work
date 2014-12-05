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
    }

    public static void merge(Spy[] a, int left, int right) {

    }
}

    public static int partition(Spy[] a, int low, int high) {
       return 0;
    }

    public static void mergeSort(Spy[] a, int low, int high) {
    }

    public static void quickSort(Spy[] a, int low, int high) {
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
