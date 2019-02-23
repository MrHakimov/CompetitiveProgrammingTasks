import java.util.*;
import java.io.*;

public class Main {
	public static double f(double x, double a, double vp, double vf) {
		return Math.sqrt(x * x  + (1.0d - a) * (1.0d - a)) / vp + Math.sqrt((x - 1.0d) * (x - 1.0d) + a * a) / vf;
	}
    public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double vp = input.nextDouble(), vf = input.nextDouble(), a = input.nextDouble();
		double l = 0.0d, r = 1.0d;
		for (int i = 0; i < 60; i++) {
			double m1 = l + (r - l) / 3.0d, m2 = r - (r - l) / 3.0d;
			if (f(m1, a, vp, vf) > f(m2, a, vp, vf)) {
				l = m1;
			} else {
				r = m2;
			}
		}
		System.out.println(l);
    }
}