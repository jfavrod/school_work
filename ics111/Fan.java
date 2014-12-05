/////////////////////////////////////////////////////////////////////////
// Class:         Fan
// Description:   Template for Fan objects
// Attributes:    Speed (limited to slow, medium, or fast)
//                On/Off
//                Radius
//                Color
// Actions:       Set values of all attributes
//                Retrieve values of all attributes
//                Display values of all attributes
/////////////////////////////////////////////////////////////////////////
public class Fan 
{
   // Attributes
   private enum eSpeed {SLOW, MEDIUM, FAST}  // possible speeds	
	private eSpeed speed;                     // speed setting of fan   
	private boolean on;                       // fan on or off
	private double radius;                    // radius of fan
	private String color;                     // color of fan
	
   // Default Constructor
	public Fan()
	{
		speed = eSpeed.SLOW;
		on = false;
		radius = 5.0;
		color = "Gray";
	}
	
	//Accessor methods
	public String getSpeed()
	{
		return speed.toString();
	}
	
	public boolean getOn()
	{
		return on;
	}
	
	public double getRadius()
	{
		return radius;
	}
	
	public String getColor()
	{
		return color;	
	}
	
	//Mutator methods
	public void setSpeed(int newSpeed)
	{
		if (newSpeed == 1) {
         speed = eSpeed.SLOW;
         on = true;
      }
      else if (newSpeed == 2) {
         speed = eSpeed.MEDIUM;
         on = true;
      }
      
      else if (newSpeed == 3) {
         speed = eSpeed.FAST;
         on = true;
      }
      else
         System.out.println("That is not a valid speed.  Please enter 1, 2, or 3");
	}
	
	public void setOn(boolean newOn)
	{
		on = newOn;
	}
	
	public void setRadius(double newRadius)
	{
		newRadius = radius;
	}
	
	public void setColor(String newColor)
	{
		color = newColor;
	}
	
	public String toString()
	{
		String description;
		if(on)
		{
			description =  "Speed: " + speed.toString() + "\n";
			description += "Color: " + color + "\n";
			description += "Radius: " + radius + "\n";
		}
		else
		{
			description =  "Fan is off\n";
			description += "Color: " + color + "\n";
			description += "Radius: " + radius + "\n";
		}
		return description;
	}
}
