class TestLinkedList
{
    static int line = 0;

    public static void main(String[] args){
        LinkedList<String> myList = new LinkedList<String>();
        myList.append("cat");
        System.out.println(line++ + ": " + myList);
        myList.append("dog");
        System.out.println(line++ + ": " + myList);

        try {
            myList.insert("horse", 2);
            System.out.println(line++ + ": " + myList);
            myList.insert("gecko", 0);
            System.out.println(line++ + ": " + myList);
            myList.insert("cow", 2);
            System.out.println(line++ + ": " + myList);
        }
        catch (ListException e) {
            e.printStackTrace();
        }

        try {
            String item = myList.remove(2);
            System.out.println("Removed item: " + item);
            System.out.println(line++ + ": " + myList);
        }
        catch (ListException e) {
            e.printStackTrace();
        }

        System.out.println("Looking for horse");
        int pos = myList.find("horse");
        if (pos < 0) {
            System.out.println("Not found");
        }
        else {
            System.out.println("Horse found at: "  + pos);
        }
 
        System.out.println("Removing cat");
        myList.remove("cat");
        System.out.println(myList);   
    }
}
