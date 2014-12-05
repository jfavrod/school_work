class TestPlainList {
    public static void main(String[] args) {
        PlainList<String> myList = new PlainList<String>();
        System.out.println("myList empty? " + myList.isEmpty());
        String item = "cat";
        myList.append(item);
        myList.append("dog");
        System.out.println("myList empty? " + myList.isEmpty());
        System.out.println(myList);

        try {
            myList.insert("horse",0);
            System.out.println(myList);
        }
        catch (ListException e) {
            System.out.println(e.getMessage());
        }
    }
}
