/**
 * Created by Sagar on Jul 10.
 */
public class Card {
    private String name;

    public Card(){
        name = "";
    }

    public Card(String n){
        name = n;
    }

    public String getName(){
        return name;
    }

    public boolean isExpired(){
        return false;
    }

    public String format(){
        return "Card holder: " + name;
    }

    public String toString() {
        return "[Card] " + "Name: " + name;
    }

    public boolean equals(Card obj){
        if(obj instanceof Card && obj.getName()==name) {
            return true;
        }
        return false;
    }
}
