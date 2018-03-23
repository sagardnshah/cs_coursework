/**
 * Created by Sagar on Jul 10.
 */
public class CallingCard extends Card{
    private String cardNum;
    private String PIN;

    public CallingCard(String n, String cn, String p) {
        super(n);
        n = cn;
        PIN = p;
    }

    public String getCardNum(){
        return cardNum;
    }

    public String getPIN(){
        return PIN;
    }

    public String format(){
        return super.format() + ", CardName: " + cardNum + ", PIN: " + PIN;
    }

    public String toString(){
        return "[Calling Card] " + "Name: " + super.getName() + ", CardName: " + cardNum + ", PIN: " + PIN;
    }

    public boolean equals(CallingCard obj){
        if(obj instanceof CallingCard && obj.getName()==super.getName() && obj.getCardNum()==cardNum && obj.getPIN()==PIN){
            return true;
        }
        else return false;
    }
}
