import java.util.*;
class twinPrime
{
    static boolean isPrime(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n %i == 0)
                return false;
        }
        return true;
    }
    public static void twinprimeSeive(int n) {

    boolean prime[] = new boolean[n+2];
    for( int i=0;i<=n;i++) {prime[i]=true;}
    for(int i = 2; i * i <= n; i++) {
        if (prime[i] == true)
            for (int j = i * i; j <= n;j+=i) {
                prime[j] = false;

            }
    }
    
    for( int i=2;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(prime[i]==true && prime[j] == true && Math.abs(i-j)==2)
            System.out.println(i+" "+ j);
    }

    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        for( int i=2;i<n;i++){
            for(int j=i+1;j<n;j++)
                if(isPrime(i)==true && isPrime(j) == true && Math.abs(i-j)==2)
                System.out.println(i+" "+ j);
        }   
    
    // twinprimeSeive(n);
}
}