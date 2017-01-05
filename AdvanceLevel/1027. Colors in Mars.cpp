import java.util.Scanner;

public class Main {

	public static StringBuffer solve(int a){
//		String tmp = new String("00");
		StringBuffer temp = new StringBuffer("00");
		int b = a /13 ;
		int c = a % 13;
		if(b > 9)
			temp.setCharAt(0, (char) (b - 10 + 'A'));
		else
			temp.setCharAt(0, (char) (b + '0'));
		if(c > 9)
			temp.setCharAt(1, (char) (c - 10 + 'A'));
		else
			temp.setCharAt(1, (char) (c + '0'));
		return temp;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int r,g,b;
		Scanner in = new Scanner(System.in);
		r = in.nextInt();
		g = in.nextInt();
		b = in.nextInt();
		System.out.print("#"+solve(r)+solve(g)+solve(b));
	}

	
}