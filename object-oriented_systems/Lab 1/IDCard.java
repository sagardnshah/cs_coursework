/**
 * Created by Sagar on Jul 10.
 */
public class IDCard extends Card{
    private String IDNumber;

    public IDCard(String n, String id) {
        super(n);
        IDNumber = id;
    }

    public String getIDnumber(){
        return IDNumber;
    }

    public String format(){
        return super.format() + ", ID: " + IDNumber;
    }

    public String toString(){
        return "[ID Card] " + "Name: " + super.getName() + ", ID: " + IDNumber;
    }

    public boolean equals(IDCard obj){
        if(obj instanceof IDCard && obj.getName()==super.getName() && obj.getIDnumber()==IDNumber){
            return true;
        }
        else return false;
    }
}
