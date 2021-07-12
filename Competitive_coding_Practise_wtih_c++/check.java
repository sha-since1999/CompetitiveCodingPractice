/* Read input from STDIN. Print your output to STDOUT*/

import java.io.*;
import java.util.*;

public class check {
    static void solv(int n, int x, int[] p) {
        for (int j = 1; j <= n; j++) {
            int a = 0;
            for (int i = j; i < x; i++) {
                a += p[i];
            }
            for (int i = x; i < j; i++) {
                a += p[i];
            }
            System.out.println(a);
        }
    }


   public static void main(String args[] ) throws Exception {
         Scanner sc = new Scanner(System.in).useDelimiter("[\\s+]");
        int n = sc.nextInt();
        int r = sc.nextInt();
        final int[] p = new int[n];
        p[0] = 0;
        for (int i = 1; i < p.length; i++) {
            sc.next();
            sc.next();
            p[i] = sc.nextInt();
        }
        int tmp = sc.nextInt();
        for (int i = 0; i < tmp; i++) {
            solv(n, sc.nextInt(), p);
        }

   }
   
}

