import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt(), k = input.nextInt();
		ArrayList<Integer> m1 = new ArrayList<Integer>();
		ArrayList<Integer> m2 = new ArrayList<Integer>();
		m1.add(0);
		m2.add(0);
		int currentValue;
		for (int i = 0; i < n; i++) {
			currentValue = input.nextInt();
			m1.add(currentValue);
		}
		for (int i = 0; i < k; i++) {
			currentValue = input.nextInt();
			m2.add(currentValue);
		}
		for (int j = 1; j <= k; j++) {
			int i = m2.get(j);
			int l = 0;
			int r = n;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (m1.get(m) >= i) {
					r = m;
				} else {
					l = m;
				}
			}
			if (r != 1 && Math.abs(m1.get(l) - i) <= Math.abs(m1.get(r) - i)) {
				r = l;
			}
			System.out.println(m1.get(r));
		}
    }
}