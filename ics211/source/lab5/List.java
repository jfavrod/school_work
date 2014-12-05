/**
 * This interface will be implemented with the List class.  The
 * List class is a list of Objects that allows duplicates.  The
 * first item on the List is in position 0.  The List can be visualized
 * as a vertical list with position 0 at the top.  Moving to a bigger
 * position is moving down the List.
 */
public interface List<T> {

   /**
    * This method will add an item to the end of the list and
    * returns an int that holds the end position (i.e. the 
    * bottom of the list).
    * @param item the item to be added to the end of the list
    * @return the integer signifying the new end of the list
    */
   public int append(T item);
   
   /**
    * This method will add an item at the position specified by pos.
    * All subsequent items will be moved down the list.  This method
    * will throw a ListException if the position is invalid.  The
    * range of valid positions is (0..length()).  If the position
    * is equal to length(), this is equivalent to the append()
    * method.
    * @param item the item to be added
    * @param pos the position to add the item at
    */
   public void insert(T item, int pos) throws ListException;
   
   /**
    * This method will remove the item specified at the position 
    * specified by pos.  When the item is removed, all subsequent
    * items (if any) will move up.  This method will throw a 
    * ListException if the position is invalid.  Valid positions 
    * range from (0..length()-1)
    * @param pos The position to remove the object from.
    * @throws ListException if position is invalid.
    */
   public T remove(int pos) throws ListException;
   
   /**
    * This method will remove all occurrences of the item and
    * return the number of items removed. All subsequent items are 
    * moved up.  If the item is not found, this method will return 
    * a -1.
    * @param item The item to remove
    * @return the int number of items removed or
    * -1 if the item is not found.
    */
   public int remove(T item);
   
   /**
    * This method will search for the item.  If found, it will 
    * return the position of the first occurence on the list.  
    * If not found, it will return 0.
    * @param item The item to search for.
    * @return the int denoting the number of items removed
    */
   public int find(T item);
   
   /**
    * This method will return the item found at the position specified 
    * by pos. The item is not removed so the list is left unchanged by 
    * this operation.  This method will throw a ListException if the 
    * position is invalid.  The valid range for position is 
    * (0..length()-1)
    * @param pos The int denoting the position to retrieve the 
    * item from
    * @return the item at the position specified by pos
    * @throws ListException if position is invalid
    */
   public T retrieve(int pos) throws ListException;
   
   /**
    * This method will return the number of items on the list.
    * @return the number of items on the list
    */
   public int length();
   
   /**
    * This method will return a copy of the list
    * @return a copy of the entire list.
    */
   public List<T> copy();
   
   /**
    * This method will return true if the list is empty and false if
    * the list is not empty.
    * @return true if list is empty, false otherwise.
    */
   public boolean isEmpty();
   
   /**
    * This method will return true if the calling list and the
    * passed list are equal.
    * @param list The list to be compared with this list
    * @return true if the lists are equal, false otherwise.
    */
   public boolean equals(Object list);
   
   /**
    * This method will replace the list element specified by pos
    * with the item.
    * @param item The new item to replace the old item
    * @param pos The int specifying the position of the item to 
    * replace.
    */
   public void replace(T item, int pos) throws ListException;
   
   /**
    * This method will combine the current list with the passed
    * list by adding the passed list to the end of the current list.
    * The method will return the combined list.
    * @param list2 The list to be added to the end of the current list.
    * @return the combined list.
    */
   public List<T> combine(List<T> list2);
    
   /**
    * This method will return a list that has the items of
    * the current list in reversed order.  The existing list
    * is unchanged.
    * @return the reversed list.
    */
   public List<T> reverse();
}
