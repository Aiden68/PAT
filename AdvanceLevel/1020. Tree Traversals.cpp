import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


class Location{
	int pl;
	int pr;
	int il;
	int ir;
}

public class Main {
	public static void main(String[] args) {
		Queue<Integer> q = new LinkedList<Integer>();
		Queue<Location> l = new LinkedList<Location>();
		int n;
		int space = 0;
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		int []postArr = new int[n];
		int []inArr = new int [n];
		for(int i = 0; i < n; i++){
			postArr[i] = in.nextInt();
		}
		for(int i = 0; i < n; i++){
			inArr[i] = in.nextInt();
		}
		if( n == 1){
			System.out.print(postArr[n - 1]);
			return;
		}
		else{
			Location temp = new Location();
			temp.pl = 0;
			temp.pr = n;
			temp.il = 0;
			temp.ir = n;
			l.offer(temp);
		}
		while(!l.isEmpty()){
			Location tmpl = l.poll();
			if(tmpl.pr - tmpl.pl ==1){
				if(space == 0){
					space++;
				}
				else{
					System.out.print(" ");
				}
				System.out.print(postArr[tmpl.pr - 1]);
			}
			else if(tmpl.pr - tmpl.pl > 1){
				if(space == 0){
					space++;
				}
				else{
					System.out.print(" ");
				}
				System.out.print(postArr[tmpl.pr - 1]);
				for(int i = tmpl.il; i < tmpl.ir; i++){
					if(inArr[i] == postArr[tmpl.pr-1]){
						Location temp2 = new Location();
						Location temp3 = new Location();
						temp2.pl = tmpl.pl;
						temp2.pr = tmpl.pl +i -tmpl.il;
						temp2.il = tmpl.il;
						temp2.ir = i;
						l.offer(temp2);
						temp3.pl = tmpl.pl + i -tmpl.il;
						temp3.pr = tmpl.pr - 1;
						temp3.il = i + 1;
						temp3.ir = tmpl.ir;
						l.offer(temp3);
						break;
					}
				}
			}
		}
	}
}