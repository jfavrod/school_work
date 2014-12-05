package ics211package;

public class Stopwatch
{
    private long time;
    
    public void Stopwatch() {
        this.time = System.currentTimeMillis();
    }  

    public void reset() {
        this.time = System.currentTimeMillis();
    }

    public double elapsedTime() {
        long now = System.currentTimeMillis();
        return (now - time)/1000.0;
    }
}
