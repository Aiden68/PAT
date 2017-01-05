import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		System.out.println("hello");
		int one,two,three;
		one = 0;
		two = 0;
		three = 0;
		double []odd = new double[3];
		int []flag = new int[3];
		Scanner in = new Scanner(System.in);
		for(int i = 0;i < 3;i++)
		{
			odd[i] = 0;
			for(int j = 0;j < 3;j++)
			{
				double temp = in.nextDouble();
				if(odd[i] < temp)
				{
					odd[i] = temp;
					flag[i] = j;
				}
			}
		}
		for(int i = 0;i < 3;i++)
		{
			switch(flag[i])
			{
				case 0:
					System.out.print("W ");
					break;
				case 1:
					System.out.print("T ");
					break;
				case 2:
					System.out.print("L ");
					break;
			}
		}
		double odds = (odd[0]*odd[1]*odd[2]*0.65-1)*2;
		odds += 0.00000001;
		System.out.printf("%.2f",odds);
//		String profit = String.format("%.2f", odds);
//		System.out.println(profit);
	}

}
