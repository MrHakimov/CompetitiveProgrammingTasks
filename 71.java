import java.util.*;
import java.io.*;

public class lab1_C {
	public static long inversions = 0;
	public static ArrayList<Long> a = new ArrayList<Long>();
	public static ArrayList<Long> b = new ArrayList<Long>();
	
	public static void mergeArrays(int l, int r) {
		int m = (l + r) / 2, i = l, j = m, k = l;
		while (i < m && j < r) {
			if (a.get(i) <= a.get(j)) {
				b.set(k++, a.get(i++));
			} else {
				b.set(k++, a.get(j++));
				inversions += m - i;
			}
		}
		while (i < m) {
			b.set(k++, a.get(i++));
		}
		while (j < r) {
			b.set(k++, a.get(j++));
		}
		for (int p = l; p < r; p++) {
			a.set(p, b.get(p));
		}
	}
	
	public static void mergeSort(int l, int r) {
		if (r - l == 1) {
			return;
		}
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m, r);
		mergeArrays(l, r);
	}
	
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			long currentValue = input.nextLong();
			a.add(currentValue);
			b.add(currentValue);
		}
		mergeSort(0, n);
		System.out.println(inversions);
    }
}