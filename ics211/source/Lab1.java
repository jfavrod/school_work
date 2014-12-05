/* ICS 211 Lab 1 Simple Recursion
 *
 * Author: Jason Favrod
 * public domain no rights reserved
 *
 * A CLI application that takes one integer argument that supplies the parameter
 * for the fact() method.
 * 
 * fact() uses the formula for factorial: n! = 1 x 2 x 3 x ... x (n-1) x n , and
 * returns the factorial of the supplied argument. If more than one argument is
 * given only the first is used, and will only succeed if it is an integer greater
 * than 0.
 *
 * fact(1) return 1
 *
 * If fact(>1), the n*'s in fact stack up until fact(1) returns 1 and all the n*'s
 * are multiplied by 1.
 *
 * i.e.
 * fact(3)
 * the first time through n=3,
 * 3*fact(2)
 *
 * second time now n=2 and is stacked on the 3* and multiplied by fact(1) which
 * resolves to 1,
 * 3*2*fact(1) = 6
 *
 */
class Lab1 {
    public static void main(String[] args) {
        if (args.length > 1) {
            System.out.println("I can only do one factorial at a time, processing factorial: "
                + args[0]);
        }
        else if (Integer.parseInt(args[0]) <= 0) {
            System.out.println("I can only figure factorials greater than 0");
            System.exit(0);
        }
        try {
            int x = Integer.parseInt(args[0]);
            System.out.println("fact(" + x + ") is " + fact(x));
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Lab1 requires one and only one integer as argument.");
        }
    }
    public static int fact(int n) {
        if (n == 1) {
            return 1;
        }
        else {
            int answer = n*fact(n-1);
            System.out.println("fact(" + n + ") is " + n + 
                " multiplied by fact(" + (n-1) + ") = " + answer);
            return answer;
        }
    }
}
