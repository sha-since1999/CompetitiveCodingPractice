import java.util.*;
public class MyClass {
    public static void main(String args[]) {
      Scanner sc = new Scanner( System.in);
        int n = sc.nextInt();
        int ll[] = new int[n];
        
        for( int i=0;i<n;i++){
            int x = sc.nextInt();
            ll[i]=x;
        }
         int fmx=0, smx=0;
         for( int i=0;i<n;i++){
             if( fmx<ll[i] )
                { 
                    smx=fmx;
                    fmx= ll[i];
                }
             if (smx<ll[i] && fmx>ll[i]){
                 smx=ll[i];
             }
             
            
         }
        System.out.println(smx);
    }
}


SELECT sal FROM emp 
WHERE sal< (SELECT MAX(sal) FROM emp);




