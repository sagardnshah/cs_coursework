/**
 * This class(Date) is used to make operations on dates.
 * i.e. check equality, convert dates to string, compare dates, add, subtract, and etc.
 * 
 * @author (Sagar Shah) 
 * @version (0.1)
 */

public class Date
{
    //three basic instance variables to hold a date
    private int month;
    private int day;    
    private int year;
    
    //this array hold strings with names of months
    //makes easier to refer months
    String[] months= {"January", "February", "March", "April", "May", "June", "July"
    , "August", "September", "October", "November", "December"};
    
    //default constructor: jan 1, 1970 recommended date
    public Date()
    {
        month = 1;
        day = 1;        
        year = 1970;
    }
    
    //constructor that accepts the date in int format
    public Date(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    
    //constructor that accepts the date as ints except the month is accepted as a string
    public Date(String m, int d, int y)
    {     
        for(int i=0; i<=11; i++)
        {
            if(m.equals(months[i]))
            this.month = i+1;
        }        
        day = d;
        year = y;
    }
    
     /**
     * toString method to represent the date object in a string format
     *
     * @return     a string representation of the date 
     */
    @Override
    public String toString()
    {
        return ("Date format: " + "mm/dd/yyyy \n" + month +"/"+ day +"/"+ year);
    }
    
    
    /**
     * compares object fields to see if they are equal
     * @param   obj
     * @return     equality boolean 
     */
    public boolean equals(Object obj)
    {
        if(this == obj)
        {
            return true;
        }
        else if(obj == null)
        {
            return false;
        }
        else
            return false;
    }
    
    /**
     * compares date objects to see which date comes before the other
     * @param   anotherDate
     * @return     a integer to determine the order of dates
     */
    public int compareTo(Date anotherDate)
    {
        int value=0;
        
        if(this.year > anotherDate.year)
        {
            value = 1;
        }
        else if(this.year == anotherDate.year)
        {
            if(this.month > anotherDate.month)
            {
                value = 1;
            }
            else if(this.month == anotherDate.year)
            {
                if(this.day > anotherDate.day)
                {
                    value = 1;
                }
                else if(this.day == anotherDate.day)
                {
                    value = 0;
                }
            }
        }
        else{value = -1;}
        return value;
    }
    
    
    /**
     * add dates
     * @param   numDays
     * @return     new date
     */ 
    public Date add(int numDays)
    {
        int m = this.month;
        int d = this.day;
        int y = this.year;
        return this;
    }
    
    
    /**
     * subtract dates
     * @param   anotherDate
     * @return     new date
     */
    public Date subtract(int numDays)
    {
        int m = this.month;
        int d = this.day;
        int y = this.year;
        return this;
    }
    
    /**
     * calulates days between two days
     * @param   anotherDate
     * @return     amount of days between
     */
    public Date daysBetween(int anotherDate)
    {
        int m = this.month;
        int d = this.day;
        int y = this.year;
        return this;
    }
    
    
}