class RecurseDemo {
   public static void main(String[] args) {
      recurse(1,20,"start");
   }
   public static void recurse(int low, int high, String state) {
      if (low == high) {
         return;
      }
      int mid = (low + high)/2;
      System.out.println("mid is " + mid + ", state is " + state);
      recurse(low,mid,"low");
      recurse(mid+1,high,"high");
   }
}
