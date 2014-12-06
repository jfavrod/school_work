public class Test
{
    public native int intMethod(int n);
    public native boolean booleanMethod(boolean bool);
    public native String stringMethod(String text);
    public native int intArrayMethod(int[] intArray);

    public static void main(String[] args)
    {
        System.loadLibrary("Test");
        Test test = new Test();
        int square = test.intMethod(5);
        boolean bool = test.booleanMethod(true);
        String text = test.stringMethod("JAVA");
        int sum = test.intArrayMethod(new int[]{1,1,2,3,5,8,13});

        System.out.println("intMethod " + square);
        System.out.println("booleanMethod " + bool);
        System.out.println("stringMethod " + text);
        System.out.println("intArrayMethod " + sum);
    }
}
