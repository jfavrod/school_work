class Fib {
    public static void main(String[] args) {
        int n = 0;
        try {
            n = Integer.parseInt(args[0]);
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Usage: java Fib n");
            System.out.println("where n is the number fot the series");
            System.exit(1);
        }
        for (int i = 0; i < n; i++) {
            System.out.print(fib(i) + " ");
        }
        System.out.println("");
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
