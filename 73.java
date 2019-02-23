import java.util.*;
import java.util.Random.*;
import java.io.*;

public class lab1_A {
	public static int partition(ArrayList<Integer> a, int l, int r) throws IllegalArgumentException {
		Random randomObject = new Random();
		int x = randomObject.nextInt(r - l + 1) + l;
		int i = l, j = r, v = a.get(x);
		while (i <= j) {
			while (a.get(i) < v) {
				i++;
			}
			while (a.get(j) > v) {
				j--;
			}
			if (i >= j) {
				break;
			}
			a.set(i, a.get(i) + a.get(j));
			a.set(j, a.get(i) - a.get(j));
			a.set(i, a.get(i) - a.get(j));
			i++;
			j--;
		}
		return j;
	}
	
	public static ArrayList<Integer> quickSort(ArrayList<Integer> a, int l, int r) throws IllegalArgumentException {
		if (r > l) {
			int m = partition(a, l, r);
			a = quickSort(a, l, m);
			a = quickSort(a, m + 1, r);
		}
		return a;
	}
	
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int currentValue = input.nextInt();
			a.add(currentValue);
		}
		a = quickSort(a, 0, n - 1);
		for (int i = 0; i < n; i++) {
			System.out.print(a.get(i) + " ");
		}
    }
}