/**
 * @name sagar shah
 */

import java.util.Scanner;

public class Raffle {
	public static void main(String[] args) {
		int typeWinnerFrequency[] = {0, 0, 0};

		Scanner in = new Scanner(System.in);
		System.out.println("Enter the wining number:");
		StringBuilder winningNum  = new StringBuilder(new Scanner(System.in).nextLine());
		System.out.println("");
		StringBuilder name = new StringBuilder();
		StringBuilder ticketNum = new StringBuilder();


		boolean more = true;
		while(more){
			System.out.println("Enter the ticketholer name:");
			name = new StringBuilder(new Scanner(System.in).nextLine());
			System.out.println("");

			System.out.println("Enter the 6 digit ticket number:");
			ticketNum = new StringBuilder(new Scanner(System.in).nextLine());
			System.out.println("");

			Ticket ticket = new Ticket(name, ticketNum, winningNum);
			int typeWinner = ticket.isWinner();
			System.out.println(ticket.toString());

			if(typeWinner == 1) {
				typeWinnerFrequency[0]++;
			}
			else if(typeWinner == 2) {
				typeWinnerFrequency[1]++;
			}
			else if(typeWinner == 3) {
				typeWinnerFrequency[2]++;
			}

			System.out.println("Enter 1 to check more tickets or 0 to quit: ");
			if(in.nextInt()==0) {
				more=false;
			}
		}
		System.out.println("Number of 1st prize winners: " + typeWinnerFrequency[0]);
		System.out.println("Number of 2ns prize winners: " + typeWinnerFrequency[1]);
		System.out.println("Number of 3rd prize winners: " + typeWinnerFrequency[2]);
	}
}
