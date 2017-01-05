import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int k;
		Scanner in = new Scanner(System.in);
		k = in.nextInt();
		int []arr = new int[55];
		int []re = new int[55];
		for (int i = 1; i < 55; i++) {
			arr[i] = in.nextInt();
		}
		for (int j = 1; j < 55; j++) {
			int tmp = 0;
			for (int i = 0; i < k; i++) {
				if(i == 0 ){
					tmp = arr[j];
				}
				else{
					tmp = arr[tmp];
				}
			}
			re[tmp] = j; 
		}
		for (int i = 1; i < 55; i++) {
			int shape = (re[i] - 1) / 13;
			int num = (re[i] - 1) % 13;
			switch (shape) {
			case 0:
				System.out.printf("S%d", num + 1);
				break;
			case 1:
				System.out.printf("H%d", num + 1);
				break;
			case 2:
				System.out.printf("C%d", num + 1);
				break;
			case 3:
				System.out.printf("D%d", num + 1);
				break;
			default:
				System.out.printf("J%d", num + 1);
				break;
			}
			if(i != 54){
				System.out.print(" ");
			}
		}
	}	
}