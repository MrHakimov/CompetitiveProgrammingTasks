import java.util.*;
import java.io.*;

public class lab1_D {
	public static int heapIndex = 0;
	public static int[] heap = new int[100001];
	
	public static void insert(int x) {
		heap[heapIndex] = x;
		heapIndex++;
		int currentVertex = heapIndex - 1;
		while (currentVertex != 0 && heap[currentVertex] > heap[(currentVertex - 1) / 2]) {
			int parrent = (currentVertex - 1) / 2;
			heap[currentVertex] = heap[currentVertex] + heap[parrent];
			heap[parrent] = heap[currentVertex] - heap[parrent];
			heap[currentVertex] = heap[currentVertex] - heap[parrent];
			currentVertex = parrent;
		}
	}
	
	public static int deleteMax() {
		int returnValue = heap[0];
		heap[0] = heap[0] + heap[heapIndex - 1];
		heap[heapIndex - 1] = heap[0] - heap[heapIndex - 1];
		heap[0] = heap[0] - heap[heapIndex - 1];
		heapIndex--;
		int v = 0;
		while (2 * v + 1 < heapIndex) {
			if (heap[v] >= heap[2 * v + 1] && (2 * v + 2 >= heapIndex || heap[v] >= heap[2 * v + 2])) {
				break;
			}
			if (2 * v + 1 < heapIndex && (2 * v + 2 >= heapIndex || heap[2 * v + 1] >= heap[2 * v + 2])) {
				heap[v] = heap[v] + heap[2 * v + 1];
				heap[2 * v + 1] = heap[v] - heap[2 * v + 1];
				heap[v] = heap[v] - heap[2 * v + 1];
				v = 2 * v + 1;
			} else if (2 * v + 2 < heapIndex && heap[2 * v + 1] < heap[2 * v + 2]) {
				heap[v] = heap[v] + heap[2 * v + 2];
				heap[2 * v + 2] = heap[v] - heap[2 * v + 2];
				heap[v] = heap[v] - heap[2 * v + 2];
				v = 2 * v + 2;
			}
		}
		return returnValue;
	}
	
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			int type = input.nextInt();
			if (type == 0) {
				int currentValue = input.nextInt();
				insert(currentValue);
			} else {
				System.out.println(deleteMax());
			}
		}
    }
}