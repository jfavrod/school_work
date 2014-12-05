public class Spy implements Comparable<Spy> {
   private int spyNumber;
   private String spyCode;
   
   public Spy() {
      spyNumber = (int)(10000000*Math.random());
      int len = (int)(6*Math.random()) + 4;
      String temp = "";
      for (int j = 0; j < len; j++) {
         int charNum = (int)(26*Math.random()) + 65;
         char myChar = (char)charNum;
         temp += myChar;
      }
      spyCode = temp;
   }
   public String toString() {
      return "spyNumber: " + spyNumber + ", spyCode: " + spyCode;
   }
   public int compareTo(Spy s) {
      int temp = this.spyNumber - s.spyNumber;
      if (temp != 0) {
         return temp;
      }
      return this.spyCode.compareTo(s.spyCode);
   }
}
