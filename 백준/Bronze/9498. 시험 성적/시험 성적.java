import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n=input.nextInt();
  		char c;
		if(n>=90) {
			c='A';
		}
		else if(n>=80) {
			c='B';
		}
		else if(n>=70) {
			c='C';
		}
		else if(n>=60) {
			c='D';
		}
		else {
			c='F';
		}
		
		System.out.println(c);
	}

}