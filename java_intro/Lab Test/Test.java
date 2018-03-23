/**
 * This class will be used to test the credit card objects
 * 
 * @author (Sagar Shah) 
 * @version (04/09/2015)
 */

//imports the scanner class
import java.util.Scanner;

public class Test
{
    public static void main(String[] args)
    {
        //scanner object to accpet user input
        Scanner keyboard = new Scanner(System.in);
        
        //rquired amount of cards that is a constant
        final int NUM_CARDS = 3;
        
        //an array with 3 object refrences
        CreditCard[] cards = new CreditCard[NUM_CARDS];
        
        //variables to hold user input for each card
        String accountID;
        String accountType;
        int creditLimit;
        double balance;
        
        //way to display which card the data belongs to
        int card;
        
        
        //this loop accepts user input, and creates a new credit card objct each time until the last
        //object in the cards array has been initialized
        for(int index=0; index < cards.length; index++)
        {   
            card = index + 1;
            System.out.println("Enter information for card #" + card);
            
            System.out.print("Please enter account ID(i.e. 123): ");
            accountID = keyboard.next();
           
            System.out.print("Please enter account type(Visa, MasterCard, Anerican Express or Discover): ");
            accountType = keyboard.next();
            
            System.out.print("Please enter credit limit(i.e. 3000): $");
            creditLimit = keyboard.nextInt();
            
            System.out.print("Please enter balance(i.e. 900.50): $");
            balance = keyboard.nextDouble();
            
            System.out.println("");
            
            cards[index] = new CreditCard(accountID, accountType, creditLimit, balance);
        }
        
        
        //this is a loop that will use the toString method for each object in the cards array 
        //until all objects are displayed in a neat formar
        for(int index=0; index<cards.length; index++)
        {
            card = index + 1;
            System.out.println("");
            System.out.println("Details for card #" + card + ":");
            System.out.println(cards[index].toString());
            System.out.println("");
        }
        
        //tests and displays the results of the equals method on card 2, qne 3.
        if((cards[1].equals(cards[2]) == true))
        {
            System.out.println("Card 2 equals Card 3 since they have same ID!");
        }
        else if((cards[1].equals(cards[2]) == false))
        {
            System.out.println("Card 2 does not equal Card 3 since they have different ID!");
        }
        
        System.out.println("");
        
        
        //tests and displays the result of the compareTo method on card 1, and card 3
        if((cards[0].compareTo(cards[2]) == -1))
        {
            System.out.print("Card 1 has a lower balance than card 3!");
        }
        else if((cards[0].compareTo(cards[2]) == 0))
        {
            System.out.print("Card 1 has the same balance as card 3!");
        }
        else if((cards[0].compareTo(cards[2]) == 1))
        {
            System.out.print("Card 1 has a higher balance than card 3!");
        }
    }
}