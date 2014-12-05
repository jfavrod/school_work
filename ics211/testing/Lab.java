import ics211package.Stopwatch;
import ics211package.Spy;
import ics211package.ArrayShuffler;

class Lab3 {
    static Spy[] black;

    public static void main(String[] args) {
        int numSpies = 0;
        int maxNumber = 0;
        int maxLetters = 0;

        try {
            numSpies = Integer.parseInt(args[0]);
            maxNumber = Integer.parseInt(args[1]);
            maxLetters = Integer.parseInt(args[2]);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java Lab3 numSpies maxNum maxLetters");
            System.exit(1);
        }

        Stopwatch watch = new Stopwatch();
        Spy[] white = new Spy[numSpies];
        black = new Spy[numSpies];

        for (int i = 0; i < numSpies; i++) {
            white[i] = new Spy(maxNumber,maxLetters);
        }

        System.out.println("Time to generate array: " + 
         watch.elapsedTime());
        System.out.println("Before sorting, array sorted? " +
         isSorted(white));

        System.out.println("The white spy array before: ");
        for (int i = 0; i < white.length; i++) {
            System.out.println(white[i]);
        }

        mergeSort(white, 0, (white.length - 1));
        System.out.println("The white spy array after: ");
        for (int i = 0; i < white.length; i++) {
            System.out.println(white[i]);
        }
    }

    public static void merge(Spy[] a, int low, int mid, int high) {
        System.out.print("\n[ ");
        for (int i = 0; i < high; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("]\n");
        
        
        for (int i = 0; i < high; i++) {
             black[i] = a[i];
        }
        
        int pt1 = low;
        int pt2 = mid+1;
        
        for (int i = 0; i < high; i++) {
            if (pt1 > mid) {
                a[i] = black[pt2++];
            }
            else if (pt2 > high) {
                a[i] = black[pt1++];
            }
            else if (black[pt1].compareTo(black[pt2]) < 0) {
                a[i] = black[pt1++];
            }
            else {
                a[i] = black[pt2++];
            }
        }
    }

/*    public static int partition(Spy[] a, int low, int high) {
        int pt1 = low, pt2 = high - 1;
        int pivot = a[high];
        boolean done = false;

        while (done == false) {
            //work from the first point and
            //look for spy objects greater
            //than the pivot
            while () {

            }
        }
    }
*/
    static int count = 0;

    public static void mergeSort(Spy[] a, int low, int high) {
        System.out.println("mergeSort " + count++);
        System.out.println("low: " + low + " high: " + high);
        if (low == high) {
            System.out.println("low == high: return");
            return;     
        }
        int mid = (low + high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }

/*    public static void quickSort(Spy[] a, int low, int high) {
        return;
    }
*/
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
