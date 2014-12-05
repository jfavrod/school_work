public class Lab6
{

    public static void main(String[] args) {
        try {
            int n = Integer.parseInt(args[0]); 
            if (n == 0) System.out.println("0");
            else System.out.println(fib(n));
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(fib(45));
        }
    }

    public static int fib(int n) {
        int count = n, tmp1 = 0, tmp2 = 0;
        Stack stack = new Stack();

        for (int i = 1; i <= count; i++) {
            if (stack.size() > 1) {
                tmp2 = (int)stack.pop();
                tmp1 = (int)stack.pop();
                stack.push(tmp1 + tmp2);
            }
            else if (stack.size() == 1) {
                tmp1 = (int)stack.peek();
                stack.push(tmp1 + tmp2);
            }
            else {
                stack.push(1);
            }
        }

        return (int)stack.pop();
    }
}


