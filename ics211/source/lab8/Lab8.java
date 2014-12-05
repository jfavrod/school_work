/* Lab8
 * By: Jason Favrod
 *
 * 1) The heap sort algorithm is on the order O(N(log N)). This is because
 *    the method loops through each element in the data set, but then only
 *    performs operations with respect to nodes in the tree that have
 *    children, which is a smaller subset.
 *
 *  2) Because merge sort is a recursive algorithm, it probably requires more
 *     memory to run, thus heap sort would be more approprate with larger data
 *     sets where memory is a concern.
 *
 *  3) Heap sort would be better utilized to sort elements where there are
 *     multiple duplicates, rather than using quicksort.
 */
import ics211package.Spy;
import ics211package.Stopwatch;

class Lab8 
{
    public static void main(String[] args) {
        int size = 0;

        try {
            size = Integer.parseInt(args[0]);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java Lab8 n");
            System.out.println("where n = array size"); 
            System.exit(1);
        }

        Spy[] spies = new Spy[size];
        int spies_len = spies.length;

        for (int i = 0; i < size; i++) {
            spies[i] = new Spy(1000,10);
        }

        //heapify
        for (int i = ((spies_len - 2)/2); i >= 0; i--) {
            sink(spies, i, spies_len);
        }
        
        //heapsort
        Stopwatch watch = new Stopwatch();
        int end = spies_len;
        while (end > 0) {
            //swap
            Spy temp = spies[end - 1];
            spies[end - 1] = spies[0];
            spies[0] = temp;

            end--;
            sink(spies,0,end);
        }
        double t = watch.elapsedTime();

        if (isSorted(spies)) {
            System.out.println("Array now sorted:");
            System.out.println("Sort took: " + t + "ms");
        }
        
    }

    public static void swim(Spy[] a, int pos) {
        int parent = 0;

        while (pos > 0) {
            parent = (pos - 1)/2;
            if (a[pos].getSpyNumber() > a[parent].getSpyNumber()) {
                Spy temp = a[pos];
                a[pos] = a[parent];
                a[parent] = temp;
                pos = parent;
            }
            else {
                break;
            }
        }
    }

    public static void sink(Spy[] a, int pos, int count) {
        int leftIndex = 0, rightIndex = 0;
        int greater = 0;

        while (pos < count/2) {
            leftIndex = 2*pos + 1;
            greater = leftIndex;

            if (leftIndex < count - 1) {
                rightIndex = leftIndex + 1;
                
                if (a[rightIndex].compareTo(a[leftIndex]) > 0) {
                    greater = rightIndex;
                }
            }

            if (a[greater].compareTo(a[pos]) > 0) {
                Spy temp = a[pos];
                a[pos] = a[greater];
                a[greater] = temp;
            }
            pos = greater;
        }
    }

    public static boolean isSorted(Spy[] a) {
        boolean sorted = true;

        for (int i = 0; i < a.length - 1; i++) {
            if (a[i].compareTo(a[i+1]) > 0) {
                sorted = false;
            }
        }

        return sorted;
    }

    public static void print(Spy[] a) {
        System.out.print("[ ");
        for (Spy s : a) {
            System.out.print(s.getSpyNumber() + " ");
        }
        System.out.println("]");
    }
}
