import ics211package.Stopwatch;
import ics211package.Spy;

class Test
{
    public static void main(String[] args) {
        //lets create one spy
        Spy black = new Spy(10, 10);
        System.out.println("Black: " + black.toString());

        Spy white = new Spy(10, 10);
        System.out.println("White: " + white.toString());

        if (black.compareTo(white) < 0) {
            System.out.println("White is larger");
        }
        else {
            System.out.println("Black is larger");
        }
        //Stopwatch watch = new Stopwatch();
        //System.out.println(watch.elapsedTime());
    }
}
