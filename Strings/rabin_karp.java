import java.util.Scanner;
public class rabin_karp{
	public final static int d = 256;
	public final static int q = 101;
	public static void StringMatch(String mainstring,String pattern){
		
		int m = mainstring.length();
		int n = pattern.length();
		int t=0;int p=0;
		int h=1;
		for(int i=0;i<n-1;i++){
			h = d*h%q;
		}
		for(int i=0;i<n;i++){
			t = (d*t+mainstring.charAt(i))%q;
			p = (d*p+pattern.charAt(i))%q;
		}
		for(int i=0;i<=m-n;i++){
			if(p==t){
				int j=0;
				for(j=0;j<pattern.length();j++){
					if(mainstring.charAt(i+j)!=pattern.charAt(j))
						break;
				}
				if(j==n){
					System.out.println("Pattern found at position "+i);
				}
				
			}
			if(i<(m-n)){
				t = (d*(t-mainstring.charAt(i)*h)+mainstring.charAt(i+n))%q;
			}
			if(t<0)
			t = t+q;
			System.out.println(t);
		}
	}
	public static void main(String args[]){
		Scanner inp = new Scanner(System.in);
		int test = inp.nextInt();
		inp.nextLine();
		for(int i=0;i<test;i++){
			String mainstring = inp.nextLine();
			String pattern = inp.nextLine();
			System.out.println(mainstring);
			System.out.println(pattern);
			StringMatch(mainstring,pattern);
		}
	}
}
