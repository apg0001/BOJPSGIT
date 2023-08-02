import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int h=input.nextInt();
		int m=input.nextInt();
		
		h=m-45<0?h-1:h;
		m=m-45<0?m+15:m-45;
		h=h<0?23:h;

		System.out.printf("%d %d\n", h, m);
	}

}