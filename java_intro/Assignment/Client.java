/**
 * this is the class defintion file for the client object
 * 
 * @author Sagar Shah
 * @version 04/25/2014
 */
public class Client
{
    /**
     * instance variable that will hold client information
     */
    private String firstName;
    private String lastName;
    private String address;
    private String clientID;
    private String numberOfVisits;
    private String outstandingBalance;
    private int numOfPets;
    
    //an array of pets of object to hold pets for this instance of client object
    private Pet[] pets;
    
    public Client()
    {
        //empty default constructor
    }

    /**
     * Constructor for objects of class client
     * it will accept values for all the instance variables and the pets array
     */
    public Client(String fn, String ln, String addr, String ID, String NOV, String bal, int numOfPets, Pet[] pets) 
    {
        firstName = fn;
        lastName = ln;
        address = addr;
        clientID = ID;
        numberOfVisits = NOV;
        outstandingBalance = bal;
        this.numOfPets = numOfPets;
        this.pets = pets;
    }
    
    
    /**
     * overridden toString() method for the client object
     * 
     * @param   none
     * @return  String representation of the object
     */
    public String toString()
    {
        String string;
        
        string = "Client info: \n" + "Name: " + firstName + " " + lastName +"\n"
        + "Address: " + address + "\n"
        + "Client ID: " + clientID + "\n"
        + "Number of visits: " + numberOfVisits + "\n"
        + "Outstanding balance: " + outstandingBalance + "\n"
        + "Number of pets: " + numOfPets + "\n"
        + "Pets details: " + "\n"
        + pets + "\n";
        return string;
    }
    
    
    /**
     * a mathod to compare two clients by comparing their clientID fields
     * 
     * @param  Client clie
     * @return     a boolean value for true/false
     */
    public boolean equals(Client client)
    {        if(this.clientID.equals(client.clientID))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}