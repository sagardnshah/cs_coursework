/**
 * this is the class defintion file for the pet object
 * 
 * @author Sagar Shah
 * @version 04/25/2014
 */
public class Pet
{
    /**
     * instance variable that will hold pet information
     */
    private String name;
    private String type;
    private String weight;
    private String dateOfLastRabiesShot;
    private String dateOfLastVisit;
    
    public Pet()
    {
        //empty default constructor
    }
    
    /**
     * Constructor for objects of class pet
     * it will accept values for all the instance variables
     */
    public Pet(String n, String t, String w, String DOLRS, String DOLV)
    {
        name = n;
        type = t;
        weight = w;
        dateOfLastRabiesShot = DOLRS;
        dateOfLastVisit = DOLV;
    }
    
    /**
     * Constructor for objects of class client
     * it is a copy constructor that will accept instances of pet objects
     */
    public Pet(Pet pet)
    {
        name = pet.name;
        type = pet.type;
        weight = pet.weight;
        dateOfLastRabiesShot = pet.dateOfLastRabiesShot;
        dateOfLastVisit = pet.dateOfLastVisit;
    }
    
    /**
     * overridden toString() method for the pet object
     * 
     * @param   none
     * @return  String representation of the object
     */
    public String toString()
    {
        String string = 
        "Pet info: \n"
        + "Name: " + name + "\n"
        + "Type: " + type + "\n"
		+ "Weight: " + weight + "\n"
		+ "Date of last rabies shot: " + dateOfLastRabiesShot + "\n"
		+ "Date of last Visit:: " + dateOfLastVisit + "\n";
		
		return string;
    }
}