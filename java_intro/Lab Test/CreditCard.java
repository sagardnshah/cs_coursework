/**
 * This is a class definiton that will be used to create card objects.
 * It can also be used to verify file equality, and compare fields.
 * 
 * @author (Sagar Shah) 
 * @version (04/09/2015)
 */

public class CreditCard
{
    //instance variables for the object to hold data
    private String accountID;
    private String accountType;
    private int creditLimit;
    private double balance;
    
    /*
     * default construcot that accepts no arguments
     */
    public CreditCard()
    {
        
    }
    
    /*
     * overloaded constructor that will accpet data for all
     * four instance variables
     */
    public CreditCard(String ID, String type, int limit, double balance)
    {
        this.accountID = ID;
        this.accountType = type;
        this.creditLimit = limit;
        this.balance = balance;
    }
    
    
    /**
     * this is a custom toString method that will be used to
     * describe the object in readable format
     *  
     * @return     returns the object in string format
     */
    public String toString()
    {
        return ("Acccount ID: " + accountID + "\n"
               +"Account Type: " + accountType + "\n"
               +"Credit Limit " + creditLimit + "\n"
               +"Balance: " + balance);
    }
    
    /**
     * custom equal method that accepts the credit card object.
     * It will compare the account ID field between two objects
     * and return a boolean
     * 
     * @param  obj   CreditCard object
     * @return     boolean value that hold the value of equality 
     */
    public boolean equals(CreditCard obj)
    {
        boolean value = false;
        
        if(this.accountID.equals(obj.accountID))
        {
            value = true;
        }
        else if((this.accountID.equals(obj.accountID) == false))
        {
            value = false;
        }
        
        return value;
    }
    
    /**
     * this compareTo method will test if the balance in two creditCard
     * objects, and reutrn an int value to determine which balance is higher
     * 
     * @param  ocj   Creditcard Obj
     * @return     -1,0,1
     */
    public int compareTo(CreditCard obj)
    {
        int value = 2;
        
        if(this.balance > obj.balance)
        {
            value = 1;
        }
        else if(this.balance == obj.balance)
        {
            value = 0;
        }
        else if(this.balance < obj.balance)
        {
            value = -1;
        }
        
        return value;
    }
}