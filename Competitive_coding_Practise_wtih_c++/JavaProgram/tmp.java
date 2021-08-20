
import java.util.*;

public class tmp {
    static int solve(int x, int y) {

        return x + y;
    }

    public static void main(String a[]) {
        Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        // int ar[] = new int[8];
        // for (int i = 0; i < n; i++) {
        //     ar[i]  = sc.nextInt();

        // }

        // for (int i = 0; i < n; i++) {
        //     System.out.print(ar[i] + " ");
        // }

        // for (int k : a)          // enhance loop  for array  (for each loop)
        //     System.out.println(k);   

        // String s;
        // s = sc.nextLine();
        // System.out.println(s);

        // double d = 45.2;
        // float f = 3452.5f;
        // System.out.println(f + " " + d);
        // System.out.println( solve(5, 3));
            
        Outer obj = new Outer();
        Outer.Inner objs = obj.new Inner(); // inner class ismember class
        // Outer.Inner objs = new Outer.Inner(); // inner class is static class
        obj.show();
        objs.show();

    }
}


class Outer {
    
     String str= " outer";
     public void show ( ){
         System.out.println(str);
     }
//  static class Inner{
    class Inner{
        String str ="Inner";
        public void show(){
            System.out.println(str);

        }

     }
}


