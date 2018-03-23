/**
 * @author Sagar Shah
 */
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class Warehouses {
	public static void main (String[] args) throws FileNotFoundException{
		/**
		Setting up each inventory object per city
		Each inventory object contains an int array that holds inventory level for each part		
		**/		
		Scanner inventory = new Scanner(new FileReader("inventory.txt"));		
		String inventoryPerCity[] = new String[6];
		int z=0;
		while(inventory.hasNextLine()) {
			inventoryPerCity[z]=inventory.nextLine();
			z++;
		}		
		inventory.close();
		
		String[] a = inventoryPerCity[0].split(",");
		String[] b = inventoryPerCity[1].split(",");
		String[] c = inventoryPerCity[2].split(",");
		String[] d = inventoryPerCity[3].split(",");
		String[] e = inventoryPerCity[4].split(",");
		String[] f = inventoryPerCity[5].split(",");
		
		int[] intArray1 = new int[5];
		int[] intArray2 = new int[5];
		int[] intArray3 = new int[5];
		int[] intArray4 = new int[5];
		int[] intArray5 = new int[5];
		int[] intArray6 = new int[5];
		
		for(int i = 0; i < 5; i++) {
			intArray1[i] = Integer.parseInt(a[i].trim());
			intArray2[i] = Integer.parseInt(b[i].trim());
			intArray3[i] = Integer.parseInt(c[i].trim());
			intArray4[i] = Integer.parseInt(d[i].trim());
			intArray5[i] = Integer.parseInt(e[i].trim());
			intArray6[i] = Integer.parseInt(f[i].trim());
		}
		
		Inventory Atlanta = new Inventory(intArray1);
		Inventory Baltimore = new Inventory(intArray2);
		Inventory Chicago = new Inventory(intArray3);
		Inventory Denver = new Inventory(intArray4);
		Inventory Ely = new Inventory(intArray5);
		Inventory Fargo = new Inventory(intArray6);
		//end creating objects with initial inventory levels
		
		System.out.println("Initial inventory:");
		System.out.println("Atlanta: " + Atlanta.toString());
		System.out.println("Baltimore: " + Baltimore.toString());
		System.out.println("Chicago: " + Chicago.toString());
		System.out.println("Denver: " + Denver.toString());
		System.out.println("Ely: " + Ely.toString());
		System.out.println("Fargo: " + Fargo.toString());
		System.out.println("");
		
		//processing transactions
		Scanner transactions = new Scanner(new FileReader("transactions.txt"));
		while(transactions.hasNextLine()) {
			String currentTransaction = new String(transactions.nextLine());
			String tokens[] = currentTransaction.split(",");
			int itemNum_qty[] = new int[2];
			for(int g=0; g<tokens.length; g++) {
				tokens[g]=tokens[g].trim();
			}
			for(int h=1; h<tokens.length; h++) {
				itemNum_qty[h-1]=Integer.parseInt(tokens[h]);
			}
			if(tokens[0].equals("P")) {
				if(itemNum_qty[0]==102) {
					int min = getMin(Atlanta.getPart102qty(), Baltimore.getPart102qty(), Chicago.getPart102qty(), Denver.getPart102qty(), Ely.getPart102qty(), Fargo.getPart102qty());
					if(min==0) {
						Atlanta.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Atlanta!");
					}
					else if(min==1) {
						Baltimore.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Baltimore!");
					}
					else if(min==2) {
						Chicago.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Chicago!");
					}
					else if(min==3) {
						Denver.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Denver!");
					}
					else if(min==4) {
						Ely.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Ely!");
					}
					else if(min==5) {
						Fargo.addPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 bought for Fargo!");
					}					
				}
				else if(itemNum_qty[0]==215) {
					int min = getMin(Atlanta.getPart215qty(), Baltimore.getPart215qty(), Chicago.getPart215qty(), Denver.getPart215qty(), Ely.getPart215qty(), Fargo.getPart215qty());
					if(min==0) {
						Atlanta.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Atlanta!");
					}
					else if(min==1) {
						Baltimore.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Baltimore!");
					}
					else if(min==2) {
						Chicago.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Chicago!");
					}
					else if(min==3) {
						Denver.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Denver!");
					}
					else if(min==4) {
						Ely.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Ely!");
					}
					else if(min==5) {
						Fargo.addPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 bought for Fargo!");
					}					
				}
				else if(itemNum_qty[0]==410) {
					int min = getMin(Atlanta.getPart410qty(), Baltimore.getPart410qty(), Chicago.getPart410qty(), Denver.getPart410qty(), Ely.getPart410qty(), Fargo.getPart410qty());
					if(min==0) {
						Atlanta.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Atlanta!");
					}
					else if(min==1) {
						Baltimore.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Baltimore!");
					}
					else if(min==2) {
						Chicago.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Chicago!");
					}
					else if(min==3) {
						Denver.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Denver!");
					}
					else if(min==4) {
						Ely.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Ely!");
					}
					else if(min==5) {
						Fargo.addPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 bought for Fargo!");
					}					
				}
				else if(itemNum_qty[0]==525) {
					int min = getMin(Atlanta.getPart525qty(), Baltimore.getPart525qty(), Chicago.getPart525qty(), Denver.getPart525qty(), Ely.getPart525qty(), Fargo.getPart525qty());
					if(min==0) {
						Atlanta.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Atlanta!");
					}
					else if(min==1) {
						Baltimore.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Baltimore!");
					}
					else if(min==2) {
						Chicago.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Chicago!");
					}
					else if(min==3) {
						Denver.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Denver!");
					}
					else if(min==4) {
						Ely.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Ely!");
					}
					else if(min==5) {
						Fargo.addPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 bought for Fargo!");
					}					
				}
				else if(itemNum_qty[0]==711) {
					int min = getMin(Atlanta.getPart711qty(), Baltimore.getPart711qty(), Chicago.getPart711qty(), Denver.getPart711qty(), Ely.getPart711qty(), Fargo.getPart711qty());
					if(min==0) {
						Atlanta.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Atlanta!");
					}
					else if(min==1) {
						Baltimore.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Baltimore!");
					}
					else if(min==2) {
						Chicago.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Chicago!");
					}
					else if(min==3) {
						Denver.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Denver!");
					}
					else if(min==4) {
						Ely.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Ely!");
					}
					else if(min==5) {
						Fargo.addPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 bought for Fargo!");
					}					
				}
			}
			else if(tokens[0].equals("S")) {
				if(itemNum_qty[0]==102) {
					int max = getMax(Atlanta.getPart102qty(), Baltimore.getPart102qty(), Chicago.getPart102qty(), Denver.getPart102qty(), Ely.getPart102qty(), Fargo.getPart102qty());
					if(max==0) {
						Atlanta.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Atlanta!");
					}
					else if(max==1) {
						Baltimore.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Baltimore!");
					}
					else if(max==2) {
						Chicago.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Chicago!");
					}
					else if(max==3) {
						Denver.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Denver!");
					}
					else if(max==4) {
						Ely.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Ely!");
					}
					else if(max==5) {
						Fargo.subtractPart102qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #102 sold from Fargo!");
					}					
				}
				else if(itemNum_qty[0]==215) {
					int max = getMax(Atlanta.getPart215qty(), Baltimore.getPart215qty(), Chicago.getPart215qty(), Denver.getPart215qty(), Ely.getPart215qty(), Fargo.getPart215qty());
					if(max==0) {
						Atlanta.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Atlanta!");
					}
					else if(max==1) {
						Baltimore.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Baltimore!");
					}
					else if(max==2) {
						Chicago.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Chicago!");
					}
					else if(max==3) {
						Denver.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Denver!");
					}
					else if(max==4) {
						Ely.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Ely!");
					}
					else if(max==5) {
						Fargo.subtractPart215qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #215 sold from Fargo!");
					}					
				}
				else if(itemNum_qty[0]==410) {
					int max = getMax(Atlanta.getPart410qty(), Baltimore.getPart410qty(), Chicago.getPart410qty(), Denver.getPart410qty(), Ely.getPart410qty(), Fargo.getPart410qty());
					if(max==0) {
						Atlanta.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Atlanta!");
					}
					else if(max==1) {
						Baltimore.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Baltimore!");
					}
					else if(max==2) {
						Chicago.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Chicago!");
					}
					else if(max==3) {
						Denver.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Denver!");
					}
					else if(max==4) {
						Ely.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Ely!");
					}
					else if(max==5) {
						Fargo.subtractPart410qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #410 sold from Fargo!");
					}					
				}
				else if(itemNum_qty[0]==525) {
					int max = getMax(Atlanta.getPart525qty(), Baltimore.getPart525qty(), Chicago.getPart525qty(), Denver.getPart525qty(), Ely.getPart525qty(), Fargo.getPart410qty());
					if(max==0) {
						Atlanta.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Atlanta!");
					}
					else if(max==1) {
						Baltimore.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Baltimore!");
					}
					else if(max==2) {
						Chicago.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Chicago!");
					}
					else if(max==3) {
						Denver.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Denver!");
					}
					else if(max==4) {
						Ely.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Ely!");
					}
					else if(max==5) {
						Fargo.subtractPart525qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #525 sold from Fargo!");
					}					
				}
				else if(itemNum_qty[0]==711) {
					int max = getMax(Atlanta.getPart711qty(), Baltimore.getPart711qty(), Chicago.getPart711qty(), Denver.getPart711qty(), Ely.getPart711qty(), Fargo.getPart711qty());
					if(max==0) {
						Atlanta.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Atlanta!");
					}
					else if(max==1) {
						Baltimore.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Baltimore!");
					}
					else if(max==2) {
						Chicago.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Chicago!");
					}
					else if(max==3) {
						Denver.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Denver!");
					}
					else if(max==4) {
						Ely.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Ely!");
					}
					else if(max==5) {
						Fargo.subtractPart711qty(itemNum_qty[1]);
						System.out.println(itemNum_qty[1] + " units of item #711 sold from Fargo!");
					}					
				}
			}
		}
		transactions.close();
		
		System.out.println("");
		System.out.println("End of the day inventory:");
		System.out.println("Atlanta: " + Atlanta.toString());
		System.out.println("Baltimore: " + Baltimore.toString());
		System.out.println("Chicago: " + Chicago.toString());
		System.out.println("Denver: " + Denver.toString());
		System.out.println("Ely: " + Ely.toString());
		System.out.println("Fargo: " + Fargo.toString());
	}
	public static int getMin(int a, int b, int c, int d, int e, int f) {
		int list[] = {a, b, c, d, e, f};
		int minIndex=0;
		for(int m=0; m<list.length; m++) {
			if(list[m] < list[minIndex]) {
				minIndex=m;
			}
		}
		return minIndex;
	}
	
	public static int getMax(int a, int b, int c, int d, int e, int f) {
		int list[] = {a, b, c, d, e, f};
		int maxIndex=0;
		for(int m=0; m<list.length; m++) {
			if(list[m] > list[maxIndex]) {
				maxIndex=m;
			}
		}
		return maxIndex;
	}
}