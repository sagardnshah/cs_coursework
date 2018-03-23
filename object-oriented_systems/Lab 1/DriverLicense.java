import java.time.Year;

/**
 * Created by Sagar on Jul 10.
 */
public class DriverLicense extends Card {
    private String expYear;

    public DriverLicense(String n, String e) {
        super(n);
        expYear=e;
    }

    public boolean isExpired(){
        int year = Integer.parseInt(expYear);
        if(year<Year.now().getValue()){
            return true;
        }
        else return false;
    }

    public String getExpYear(){
        return expYear;
    }

    public String format(){
        return super.format() + ", Expiration Year: " + expYear;
    }

    public String toString(){
        return "[Driver License] " + "Name: " + super.getName() + ", Expiration Year: " + expYear;
    }

    public boolean equals(DriverLicense obj){
        if(obj instanceof DriverLicense && obj.getName()==super.getName() && obj.getExpYear()==expYear){
            return true;
        }
        else return false;
    }
}
