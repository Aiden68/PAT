import java.util.Scanner;

class student{
	 String name ="";
	 String id = "";
}

public class Main {
	
	public static void main(String[] args) {
		int n;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		int [][]arr = new int[101][n+1];
		int []cnt = new int[101];
		student []stu = new student[n];
		for (int i = 0; i < n; i++) {
			stu[i] = new student();
			stu[i].name = in.next();
			stu[i].id = in.next();
			int score = in.nextInt();
			arr[score][0]++;
			arr[score][++cnt[score]] = i;
		}
		int g1,g2,flag = 0;
		g1 = in.nextInt();
		g2 = in.nextInt();
		for (int i = g2; i >= g1; i--) {
			if(arr[i][0] != 0){
				flag = 1;
				for (int j = 0; j < arr[i][0]; j++) {
					System.out.printf("%s %s\n", stu[arr[i][j+1]].name,stu[arr[i][j+1]].id);
				}
			}
		}
		if(flag == 0){
			System.out.println("NONE");
		}
	}
}