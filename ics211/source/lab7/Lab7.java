/* Lab7
 * By: Jason Favrod
 *
 * Results:
 *
 *                  Number of Loops
 *                 Before 'Overflow'
 *      0    20      40      60      80      100
 *      |
 * @20% |xxxxxxxxxxxxxxxxxxxxx
 *      |
 * @40% |xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 *      |
 * @Ax4 |xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 *      |______________________________________
 *
 * The graph above shows the results of dequeuing. Dequeuing at 20%
 * the queue overflowed at ~62 runs, at 40%, ~90 runs, and when 4 items
 * were dequeued in the occurance of the 'A' char as the first char
 * of spyCode at ~85 runs.
 *
 * For me dequeuing at 40% almost double the amount of loop runs before
 * overflow. This is pretty much what I expected because I doubled the
 * amount of cases that result in a dequeuing.
 *
 * When dequeuing 4 times for each occurance of the 'A' char, the number
 * of loop runs was greater than the @20% condition, but less than @40%.
 *
 * This is as was expected because although we are decreasing the
 * probability that our dequeuing condidion will be met we are increasing
 * the number of dequequing events that happen when the condition does
 * occur thus compensating for the reduction. Yet this compensation is
 * not great enough to overcome the number of times that dequeuing
 * happens at 40% of the time.
 *
 * One reason for this is that there can be times when this condition is
 * met and there are less than 4 items in the queue.
 *
 */

import ics211package.Spy;
class Lab7
{
    public static void main(String[] args) {
        Queue myQueue = new Queue();
        int count = 0;

        while (myQueue.size() < 50) {
            String code = (new Spy(1000,10)).getSpyCode();
            myQueue.enqueue(code);
            delay(500);
            myQueue.print();
            char start = code.charAt(0);
            // use a switch() statement to control dequeuing

            switch(start) {
                case('A'):
                    myQueue.dequeue();
                    myQueue.dequeue();
                    myQueue.dequeue();
                    myQueue.dequeue();
                    break;
            }

            System.out.println("");
            count++;
        }

        System.out.println("Queue overflowed at " + count);
    }
    
    private static void delay(int n) {
        try {
            Thread.sleep(n);
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
