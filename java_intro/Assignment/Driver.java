import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;

/**
 * The purpose of this class:
 * read data from a file
 * process clients and pets in to two seperate arrays
 * using the example text file, there are 5 clients and 11 pets
 * it also prints the client and pet details in a clean format
 * 
 * @author (Sagar Shah) 
 * @version (04/25/2014)
 */
public class Driver
{
    public static void main(String[] args)throws IOException
    {
        //scanner object to accept user input
        Scanner keyboard = new Scanner(System.in);
        
        //file object to create an instance of the file
        System.out.println("Enter file name: ");
        File myFile = new File(keyboard.nextLine());//tested with "clientdata.txt"
        
        /**copy of the previous file object because 
         *StringTokenizer object had issues using the same file object for two seperate tasks
         */
        File myFile1 = myFile;
        
        //an instance of scanner that accepts the file object
        Scanner inputFile = new Scanner(myFile);
        
        //another copy of scanner becuase of the StringTOkenizer issue
        Scanner inputFile1 = new Scanner(myFile);
        StringTokenizer st;
        
        
        //variables that will be passed when a client object is created
        String firstName = "";
        String lastName = "";
        String address = "";
        String clientID = "";
        String numberOfVisits = "";
        String outstandingBalance = "";
        int petsForThisClient = -1;
        
        //variables that will be passed when a pet object is created
        String name = "";
        String type = "";
        String weight = "";
        String dateOfLastRabiesShot = "";
        String dateOfLastVisit = "";
        
        
        //this loop will count all the lines in the text to be processed
        int totalLines = 0;        
        while(inputFile.hasNextLine())
        {
            String temp = inputFile.nextLine();
            totalLines++;
        }
        String[] allLines = new String[totalLines]; // a string array to hold al the strings
        
        //this loop will pass each line to the string array
        int currentLine=0;
        while(inputFile1.hasNextLine())
        {
            allLines[currentLine]=inputFile1.nextLine();
            currentLine++;            
        }        
        
        /**
         * this for loop counts the number of clients
         * if a line has 7 tokens then it is a clients
         */ 
        int totalClients = 0;
        for(int i=0; i < totalLines; i++)
        {
            st = new StringTokenizer(allLines[i], ",");
            if(st.countTokens() == 7)
            {
                totalClients++;
            }
        }
        
        /**
         * this for loop counts the number of pets
         * if a line has 5 tokens then it is a pets
         */ 
        int totalPets = 0;//will interate until all pets are counted
        for(int i=0; i < totalLines; i++)
        {
            st = new StringTokenizer(allLines[i], ",");
            if(st.countTokens() == 5)
            {
                totalPets++;
            }
        }
        
        //iterating variables to keep track of which client or pet is being processed
        int currentClient = 0;
        int currentPet = 0;
        
        //an array which will hold all the Client objects
        Client[] allClients = new Client[totalClients];
        
        //an array which will hold all the Pet objects
        Pet[] allPets = new Pet[totalPets];
        
        /**
         * This loop will use the StringTokenizer class to split up each line,
         * then determine if it is a client or a pet.
         * If it is a client, then it create a Client object,
         * then it will pass the object to an array of Client objects.
         * If it is a pet, then it creates a Pet object,
         * then it will pas the object to an array of Pet objects.
         */
        for(int i = 0; i < totalLines; i++)
        {
            st = new StringTokenizer(allLines[i], ",");
            if(st.countTokens() == 5)
            {
                name = st.nextToken();
                type = st.nextToken();
                weight = st.nextToken();
                dateOfLastRabiesShot = st.nextToken();
                dateOfLastVisit = st.nextToken();   
                
                allPets[currentPet] = new Pet(name, type, weight, dateOfLastRabiesShot, dateOfLastVisit);
                currentPet++;
            }
            if(st.countTokens() == 7)
            {
                firstName = st.nextToken();
                lastName = st.nextToken();
                address = st.nextToken();
                clientID = st.nextToken();
                numberOfVisits = st.nextToken();
                outstandingBalance = st.nextToken();                
                petsForThisClient = Integer.valueOf(st.nextToken());
                
                //pases the Pet objects for this client to the Pet array in 
                //the Client object currently being processed
                Pet[] pets = new Pet[petsForThisClient];
                for(int x=0; x<petsForThisClient; x++)
                {
                    pets[x] = allPets[x];
                }
                
                //creates a new Client object that will be store in an array of clients
                allClients[currentClient] = new Client(firstName, lastName, address, clientID,
                numberOfVisits, outstandingBalance, petsForThisClient, pets);          
                currentClient++;
            }            
        }
        
        
        /**
         * Displays all clients.
         */
        for(int i=0; i <totalClients; i++)
        {
            System.out.println(allClients[i].toString());            
        }
        
        System.out.println("----------End of clients list----------");
        System.out.println("");
        System.out.println("-----------Start of Pets List---------");
        
        /**
         * Displays all pets.
         */
        for(int i=0; i <totalPets; i++)
        {
            System.out.println(allPets[i].toString());
        }
        System.out.println("----------End of pets list----------");
        
        /**
         * a demonstration of the equal method from the client class
         */
        System.out.println("Is client 2(Wilder, John) the same person as client 5(Smith,Jack)?");
        System.out.println(allClients[1].equals(allClients[4]));
    }
}