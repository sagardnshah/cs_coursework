import java.util.*;
import java.io.*;

public class FinalStrings
{
    public static void main(String[] args) throws IOException
    {
        Scanner keyboard = new Scanner(System.in);
            
        System.out.println("Enter the name of the file: ");
        String fileName = keyboard.nextLine();
        Scanner inputFile = new Scanner(new File(fileName));
        
        String original = "";
        
        while(inputFile.hasNextLine())
        {
            original = original + inputFile.nextLine() + "\n";
            StringConverter test = new StringConverter(original);            
        }
        
        inputFile.close();
        
        System.out.println(original);
    }
}