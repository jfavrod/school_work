/* Project 2
 * By: Jason Favrod
 *
 * 1) My sorting alogrithm is on the order of n^2. This is because the method
 *    needs to loop through a set of elements for each element in the set to be
 *    sorted.
 *
 *  2) A person who knows what they are doing with basic sorting algorithms will
 *     perform less steps than an automatic sort because an auto sort will need to
 *     analyse what is to be sorted before choosing a sorting method, where as the
 *     programmer who knows will just go ahead and apply the best algo for the job.
 *
 *  3) Link list are more suitable storage structures when data is intended to be
 *     often inserted and removed and order needs to maintained; And in java,
 *     where the size needs to be dynamic.
 *
 *  4) An array is more suitable when iterating over the contents is desired. If
 *     the benefits of a linked list are not required, an array is quicker and
 *     and more simple to implement (it's a primative!). Furthermore, the fixed
 *     size of arrays in java may be needed.
 */
import java.util.*;
import java.util.regex.*;

public class Project2
{
    static Queue q = new Queue();
    static Stack s = new Stack();
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        boolean quit = false;

        while(!quit) {
            //validate user input
            switch(menu(kb)) {
                case(1):
                    System.out.println("Enter numbers separated by commas:");
                    String csv = kb.next();
                    //validate user input
                    setQueue(csv);
                    break;
                case(2):
                    rotateQueue();
                    break;
                case(3):
                    dequeueToStack();
                    break;
                case(4):
                    popToQueue();
                    break;
                case(5):
                    sortQueue();
                    break;
                case(6):
                    quit = true;
                    break;
            }
        }
    }

    private static int menu(Scanner kb) {
        int selection = 0;
        String opt1 = "1 - Set queue to be sorted";
        String opt2 = "2 - Rotate queue";
        String opt3 = "3 - Dequeue and push to stack";
        String opt4 = "4 - Pop from stack and enqueue";
        String opt5 = "5 - Sort it for me";
        String opt6 = "6 - End Program";

        while(selection == 0) {
            System.out.printf("%-30s  %-30s\n", opt1, opt2);
            System.out.printf("%-30s  %-30s\n", opt3, opt4);
            System.out.printf("%-30s  %-30s\n", opt5, opt6);
            System.out.println("Enter the number for your choice: ");
            try {
                selection = kb.nextInt();
            }
            catch (InputMismatchException e) {
                kb.nextLine();
                System.out.println("Useage");
            }
        }
        return selection;
    }

    private static void setQueue(String csv) {
        Scanner s = new Scanner(csv).useDelimiter("\\s*,\\s*");
        while(s.hasNext()) {
            q.enqueue(s.next());
        }
        System.out.print("Queue is: "); q.print();
    }

    private static void rotateQueue() {
        Queue tempQ = new Queue();
        String temp = ""; 

        temp = q.dequeue();
        while(q.size() > 0) {
            tempQ.enqueue(q.dequeue());
        }
        tempQ.enqueue(temp);

        while(!tempQ.isEmpty()) {
            q.enqueue(tempQ.dequeue());
        }

        System.out.print("Queue is: "); q.print();
    }

    private static void dequeueToStack() {
        if(!q.isEmpty()) {
            s.push(q.dequeue());
            s.toString();
        }
        else {
            System.out.println("Queue is empty.");
        }
        System.out.print("Queue is: "); q.print();
        System.out.println("Stack is: "); s.print();
    }

    private static void popToQueue() {
        if(!s.isEmpty()) {
            q.enqueue(s.pop());
            System.out.print("Queue is: "); q.print();
            System.out.println("Stack is: "); s.print();
        }
        else {
            System.out.println("Stach is empty.");
        }
    }

    private static void sortQueue() {
        Queue tempQ = new Queue();
        String temp1 = "", temp2 = "";

        while(!q.isEmpty()) {
            tempQ.enqueue(q.dequeue());
        }

        do {
            for(int i = (tempQ.size() - 1); i > 0; i--) {
                if(temp1 == "") {
                    temp1 = tempQ.dequeue();
                }
                
                if(temp2 == "") {
                    temp2 = tempQ.dequeue();
                }

                if(Integer.parseInt(temp1) > Integer.parseInt(temp2)) {
                    tempQ.enqueue(temp1);
                    temp1 = "";
                }
                else {
                    tempQ.enqueue(temp2);
                    temp2 = "";
                }
            }
            
            
            if(temp1 == "") {
                q.enqueue(temp2);
                temp2 = "";
            }
            else {
                q.enqueue(temp1);
                temp1 = "";
            }
            
            if(tempQ.size() == 1) {
                q.enqueue(tempQ.dequeue());
            }
        } while(!tempQ.isEmpty());

        q.print();
    }
}
