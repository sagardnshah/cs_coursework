/**
 * @name sagar shah
 */

public class Ticket {
	StringBuilder name;
	StringBuilder ticketNum;
	StringBuilder winningNum;
	String ticketNumString;
	String winningNumString;
	int typeWinner = -1;
	
	public Ticket(StringBuilder name, StringBuilder ticketNum, StringBuilder winningNum) {
		this.ticketNum = ticketNum;
		this.winningNum = winningNum;
		this.name=name;
		ticketNumString = ticketNum.toString();
		winningNumString = winningNum.toString();
	}
	
	public int isWinner() {
		if(firstPrice()) {
			typeWinner=1;
			return 1;
		}
		else if(secondPrice()) {
			typeWinner=2;
			return 2;
		}
		else if(thirdPrice()) {
			typeWinner=3;
			return 3;
		}
		else return -1;
	}
	
	private boolean firstPrice() {
		if(ticketNum.toString().equals(winningNum.toString())) {
			return true;
		}
		else return false;
	}
	
	private boolean secondPrice() {
		if(ticketNum.reverse().toString().equals(winningNum.toString())){
			return true;
		}
		else return false;
	}
	
	private boolean thirdPrice() {
		if(ticketNumString.substring(0,3).equals(winningNumString.substring(0,3))) {
			return true;
		}
		else if(ticketNumString.substring(1,4).equals(winningNumString.substring(1,4))) {
			return true;
		}
		else if(ticketNumString.substring(2,5).equals(winningNumString.substring(2,5))) {
			return true;
		}
		else if(ticketNumString.substring(3,6).equals(winningNumString.substring(3,6))) {
			return true;
		}
		else return false;
	}
	
	public String toString() {
		if(typeWinner==1) {
			return name + ": first prize!";
		}
		else if(typeWinner==2) {
			return name + ": second prize!";
		}
		else if(typeWinner==3) {
			return name + ": third prize!";
		}
		else {
			return name + ": not a winner!";
		}
	}
}