public class TestStack
{
    public static void main(String[] args) {
        Stack myStack = new Stack();

        myStack.push((int) 1);
        System.out.println(myStack);
        myStack.push((int) 10);
        myStack.push((int) 100);
        myStack.push((int) 1000);
        System.out.println(myStack);
    }

    public static int fib(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            return fib(n-1) + fib(n-2);
        }
    }
}
