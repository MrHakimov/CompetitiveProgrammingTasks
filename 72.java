import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] count = new int[101];
		for (int i = 0; i < 101; i++) {
			count[i] = 0;
		}
		while (input.hasNextInt()) {
			int currentNumber = input.nextInt();
			count[currentNumber]++;
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < count[i]; j++) {
				System.out.print(i + " ");
			}
		}
    }
}