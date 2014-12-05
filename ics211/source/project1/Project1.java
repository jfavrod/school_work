/**Project1.
 * 
 * 1. Insertions sort ran much quicker on the sorted list.
 *    When I ran merge sort and quick sort on a sorted list the first time the sort
 *    time is notably greater than on an unsorted list. If I run either on the sorted
 *    list again the sort time drops to single digit ms. The story changed after I
 *    increased the stack size and made large Spy arrays (~10000 elements).
 *
 *   With large arrays merge sort ran a bit faster on an already sorted array and
 *   quick sort ran - as in Lab3 - about 10x slower.
 *
 *   With large arrays merge sort ran a bit faster on an already sorted array and
 *   quick sort ran - as in Lab3 - about 10x slower.
 * 
 *   So, I'd used the java Arrays sorting method if I didn't know or want to
 *   take the time to analyse or control the data that was to be sorted - it's a
 *   good default. If I knew the elements could vary in number and could be sorted or
 *   unsorted I'd use merge sort. If I knew the elements were to be numerous and were
 *   for sure going to be unsorted I'd use quick sort, but with the same elements that
 *   could be either sorted or unsorted I'd use insertion sort.
 *
 * 2. To increase the stack size with the command line argument -Xss[new stack size].
 *
 * 3. I don't think the Arrays sort does the same alogrithm for all arrays - Java is
 *    open source so I could look at the code. I think the Arrays sort first does some
 *    anaylsis simialr to my summary in question 1 before choosing how to proceed.
 */ 

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Project1
{
    static Spy[] spies;
    static int numSpies = 0;
    static Stopwatch watch;
    static Scanner keyboard;
    
    public static void main(String[] args) {
        Random rand = new Random();
        keyboard = new Scanner(System.in);
        
        int maxNumber = 0;
        int maxLetters = 0;

        try {
            numSpies   = Integer.parseInt(args[0]);
            maxNumber  = Integer.parseInt(args[1]);
            maxLetters = Integer.parseInt(args[2]);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java Project1 numSpies maxNum maxLetters");
            System.exit(1);
        }

        spies = new Spy[numSpies];

        for (int i = 0; i < numSpies; i++) {
            spies[i] = new Spy(maxNumber,maxLetters);
        }
        
        //printSpies();
        String again = "n";

        do {
            if (regen()) {
                ArrayShuffler.shuffle(spies);
                //printSpies();
            }
            
            System.out.println("\nHow would you like to sort the spy array?");
            System.out.println("0. Insertion Sort");
            System.out.println("1. Merge Sort");
            System.out.println("2. Quick Sort");
            System.out.println("3. java.util.Arrays.sort");
            
            int sort = keyboard.nextInt();
            keyboard.nextLine();
            
            switch (sort) 
            {
                case 0:
                    watch = new Stopwatch();
                    insertionSort(spies);
                    System.out.println("sort time: " + (watch.elapsedTime()*1000) + "ms");
                    //printSpies();
                    break;
                
                case 1:
                    watch = new Stopwatch();
                    mergeSort(spies, 0, (spies.length - 1));
                    System.out.println("sort time: " + (watch.elapsedTime()*1000) + "ms");
                    //printSpies();
                    break;
                
                case 2:
                    watch = new Stopwatch();
                    quickSort(spies, 0, (spies.length - 1));
                    System.out.println("sort time: " + (watch.elapsedTime()*1000) + "ms");
                    //printSpies();
                    break;
                
                case 3:
                    watch = new Stopwatch();
                    Arrays.sort(spies);
                    System.out.println("sort time: " + (watch.elapsedTime()*1000) + "ms");
                    //printSpies();
                    break;
            }

            System.out.println("Go again? [y/n]");
            again = keyboard.nextLine();
        } while (again.equalsIgnoreCase("y"));
    }

    public static void insertionSort(Spy[] a) {
        for (int i = 1; i < a.length; i++) {
            int pos = i;
            Spy temp = a[pos];

            while (pos > 0 && (temp.compareTo(a[pos-1]) < 0)) {
                a[pos] = a[pos-1];
                pos--;
            }
            
            a[pos] = temp;
        }
    }
    
    public static void merge(Spy[] a, int low, int mid, int high) {
        Spy[] temp = new Spy[a.length];
        
        for (int k = low; k <= high; k++) {
            temp[k] = a[k];
        }

        int i = low;
        int j = mid+1;

        for (int k = low; k <= high; k++) {
            if (i > mid) {
                a[k] = temp[j++];
            }
            else if (j > high) {
                a[k] = temp[i++];
            }
            else if (temp[i].compareTo(temp[j]) < 0) {
                a[k] = temp[i++];
            }
            else {
                a[k] = temp[j++];
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
        int j = high - 1;
        Spy pivot = a[high];
        boolean done = false;

        while (!done) {
            while (i < high && a[i].compareTo(pivot) <= 0)
                i++; 

            while (j > low && a[j].compareTo(pivot) >= 0)
                j--;

            if (i < j) {
                Spy temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else {
                done = true;
            }
        }
        
        a[high] = a[i];
        a[i] = pivot; 
        return i;
    }

    public static void quickSort(Spy[] a, int low, int high) {
        if (low >= high) return;

        int pivotPos = partition(a, low, high);
        quickSort(a, low, pivotPos - 1);
        quickSort(a, pivotPos++, high);
    }
    
    public static void printSpies() {
        System.out.print("[ ");
        for (int i = 0; i < numSpies; i++) {
            System.out.print(spies[i].getSpyNumber());
            if (i != numSpies - 1) {
                System.out.print(", ");
            }
        }
        System.out.println(" ]");
    }

    private static boolean regen() {
        boolean shuff = false;

        if (isSorted(spies)) {
            System.out.println("The array is already sorted, would you"+
                    "like to shuffle it [y/n]");
            String input = keyboard.nextLine();
            if (input.equalsIgnoreCase("y")) {
                shuff = true;
            }
        }
        return shuff;
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
}
