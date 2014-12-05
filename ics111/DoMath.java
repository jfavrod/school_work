/*
 * DoMath.java
 * 
 * 
 * 
 */
import java.text.DecimalFormat;

public class DoMath {
    
	public static void main (String args[]) 
	{
        int num1 = 2, num2 = 4, num3 = 5, num4 = 10;
        
        System.out.println("Raising " + num4 + " to the power of " + num2);
        System.out.println("Answer: " + DoMath.power(num4, num2));
        System.out.println("");
        
        System.out.println("Dividing the integer " + num3 + " by the integer " + num1);
        System.out.println("Answer: " + DoMath.divide(num3, num1));
        System.out.println("");
        
        System.out.println("Dividing the double " + (double)num1 + " by the double " + (double)num2);
        System.out.println("Answer: " + DoMath.divide(num1, num2));
        System.out.println("");
        
        System.out.println("The average of the 3 integers " + num4 + ", " + num3 + ", and " + num1);
        System.out.println("Answer: " + average(num4, num3, num1));
        System.out.println("");
        
        System.out.println("The Average of the 4 integers" + num1 + ", " + num2 + ", " + num3 + ", and " + num4);
        System.out.println("Answer: " + average(num1, num2, num3, num4));
	}
    
    public static double power (int coef, int deg)
    {
        double result = Math.pow((double)coef, (double)deg);
        result = format(result);
        return result;
    }

    public static double divide (int a, int b)
    {
        double result = (double)a / (double)b;
        result = format(result);
        return result;
    }

    public static double divide (double a, double b)
    {
        double result = a / b;
        result = format(result);
        return result;
    }
    
    public static double average (int a, int b, int c)
    {
        double sum = a + b + c;
        double result = sum / 3;
        result = format(result);
        return result;
    }
    
    public static double average (int a, int b, int c, int d)
    {
        double sum = a + b + c + d;
        double result = sum / 4;
        result = format(result);
        return result;
    }
    
    public static double format (double value)
    {
        DecimalFormat df = new DecimalFormat("####0.00");
        String num_string = df.format(value);
        double result = Double.parseDouble(num_string);
        return result;
    }
}

