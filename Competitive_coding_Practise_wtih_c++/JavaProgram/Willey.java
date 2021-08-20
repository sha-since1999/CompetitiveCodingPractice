import java.util.*;

public class Willey {
    static void moduloInverse() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 1; i < m; i++) {
            if (((a % m) * (a % i) % m) == 1)
                System.out.println(i);
        }
        System.out.println(-1);
    }

    static void countOnes() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        int x = 1;
        while (n > 0) {
            if ((n & x) == 1)

                ans++;
            n >>= 1;
        }

        System.out.println(ans);
    }

    static void swapElementOfList() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int tmp = a[0];
        a[0] = a[a.length - 1];
        a[a.length - 1] = tmp;
        System.out.println("List After Swapping");
        for (int x : a)
            System.out.print(x + " ");

    }

    public static void main(String[] args) {
        // countOnes(); /// count of 1's in number
        // swapElementOfList(); // swap first and last element of list
        // moduloInverse();
    }

}

