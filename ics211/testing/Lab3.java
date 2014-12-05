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

}

    public static void merge(Spy[] a, int low, int mid, int high) {
        System.out.println("merging;");
        System.out.println("low: " + low + " mid: " + mid + " high: " + high);

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

    static int count = 0;

    public static void mergeSort(Spy[] a, int low, int high) {
        System.out.println("\nmergeSort " + count++);
        System.out.println("low: " + low + " high: " + high);

        if (low == high) {
            System.out.println("low == high");
            return;
        }

        int mid = (low + high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
