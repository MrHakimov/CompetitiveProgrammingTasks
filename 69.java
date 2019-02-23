import java.util.*;
import java.io.*;

public class lab1_K {
	public static int n, k;
	public static Stone[] stones;
	
	public static boolean check(double m) {
		Arrays.sort(stones, new Comparator<Stone>() {
			public int compare(Stone s1, Stone s2) {
				return (int) -Math.signum((s1.v - m * s1.w) - (s2.v - m * s2.w));
			}
		});
		double sumAll = 0.0d;
		for (int i = 0; i < k; i++) {
			sumAll += stones[i].v - m * stones[i].w;
		}
		return (sumAll >= 0.0d);
	}
	
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("kbest.in"));
		n = input.nextInt();
		k = input.nextInt();
		stones = new Stone[n];
		for (int i = 0; i < n; i++) {
			stones[i] = new Stone();
			stones[i].v = input.nextInt();
			stones[i].w = input.nextInt();
			stones[i].ind = i + 1;
		}
		double L = 0.0d, R = 10000000.0d;
		for (int i = 0; i < 100; i++) {
			double mid = (L + R) / 2.0d;
			if (check(mid)) {
				L = mid;
			} else {
				R = mid;
			}
		}
		check(L);
		FileWriter output = new FileWriter("kbest.out");
		for (int i = 0; i < k; i++) {
			output.write(String.valueOf(stones[i].ind) + "\n");
		}
		output.close();
    }
	
	static public class Stone {
		public double v, w;
		public int ind;
	}
}