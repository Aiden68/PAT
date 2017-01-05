import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String num = new String();
		char []tmp = new char[20];
		double input = 0;
		Scanner in = new Scanner(System.in);
		num = in.next();
		int []count = new int[10];
		for(int i = 0;i < num.length();i++)
		{
			count[num.charAt(i)-'0']++;
		}
		int flag = 0;
		int flag1 = 0;
		for(int i = num.length()-1;i >= 0;i--)
		{
			int temp = (num.charAt(i)-'0') * 2 +flag;
			if(temp >= 10)
			{
				flag = 1;
				temp -= 10;
			}
			else
			{
				flag = 0;
			}
			if(i == 0&&flag==1)
			{
				flag1 = 1;
			}
			tmp[i] = (char) (temp + '0');
		}
		String r1 = new String(tmp);
		String r = r1.substring(0, num.length());
		for(int i = 0;i < num.length();i++)
		{
			input = input * 10 + (num.charAt(i)-'0');
		}
		for(int i = 0;i < num.length();i++)
		{
			count[r.charAt(i)-'0']--;
		}
		if(flag == 1)
		{
			System.out.println("No");
			System.out.print('1');
		}
		else
		{
			for(int i = 0;i < 10;i++)
			{
				if(count[i] != 0)
				{
					System.out.println("No");
					break;
				}
				if(i == 9)
				{
					System.out.println("Yes");
				}
			}
		}	
		System.out.println(r);
	}

}
