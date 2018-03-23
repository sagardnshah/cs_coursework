
public class Inventory {
	int part102=0;
	int part215=0;
	int part410=0;
	int part525=0;
	int part711=0;	
	
	public Inventory(int[] intArray) {
		part102=intArray[0];
		part215=intArray[1];
		part410=intArray[2];
		part525=intArray[3];
		part711=intArray[4];
	}
	
	public int getPart102qty() {
		return part102;
	}
	
	public int getPart215qty() {
		return part215;
	}
	
	public int getPart410qty() {
		return part410;
	}
	
	public int getPart525qty() {
		return part525;
	}
	
	public int getPart711qty() {
		return part711;
	}
	
	public void addPart102qty(int a) {
		part102+=a;
	}
	
	public void addPart215qty(int b) {
		part215+=b;
	}
	
	public void addPart410qty(int c) {
		part410+=c;
	}
	
	public void addPart525qty(int d) {
		part525+=d;
	}
	
	public void addPart711qty(int e) {
		part711+=e;
	}
	
	public void subtractPart102qty(int f) {
		part102-=f;
	}
	
	public void subtractPart215qty(int g) {
		part215-=g;
	}
	
	public void subtractPart410qty(int h) {
		part410-=h;
	}
	
	public void subtractPart525qty(int i) {
		part525-=i;
	}
	
	public void subtractPart711qty(int e) {
		part711-=e;
	}

	@Override
	public String toString() {
		return "[part102=" + part102 + ", part215=" + part215 + ", part410=" + part410 + ", part525="
				+ part525 + ", part711=" + part711 + "]";
	}
	
}
