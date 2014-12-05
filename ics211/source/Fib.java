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
        int r = 0;
        if (n == 0 || n == 1) {
            r = 1;
        }
        else {
            r = fib(n-1) + fib(n-2);
        }
        return r;
    }
}
