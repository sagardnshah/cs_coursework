/**
 * This is the driver class that will test the methods in the Date class
 * 
 * @author (Sagar Shah) 
 * @version (0.1)
 */

public class Drive
{
    public static void main(String[] args)
    {
        //two objects with different arguments
        //adjust these dates to test all possible scenarios
        Date obj1 = new Date("January", 2, 2014);
        Date obj2 = new Date(1, 2, 2013);
        
        //this displays the overridden toString method for both objects
        System.out.println("Date 1 - "+obj1.toString());
        System.out.println("");
        System.out.println("Date 2 - "+obj2.toString());
        System.out.println("");
        
        //compares the fields in both objects by using the equals method
        System.out.println(obj1.equals(obj2));        
        
        //uses the compareTo method to see the order of the dates
        if(((obj1.compareTo(obj2))) == -1)
            System.out.println("Date 1 comes before Date 2");            
        else if(((obj1.compareTo(obj2))) == 0)
            System.out.println("Date 1 matches Date 2");
        else if(((obj1.compareTo(obj2))) == 1)
            System.out.println("Date 1 comes after Date 2");
    }
}