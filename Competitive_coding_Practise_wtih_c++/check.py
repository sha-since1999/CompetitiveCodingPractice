def pattern(n):
     
    for i in range(0, n):
        for j in range(n-i):
            print("  ",end="")
         
        if i%2==0:
            for j in range(2*i+1):
                print("* ",end="")
        else :
            for j in range(2*i+2):
                print("* ",end="")

        print("\r")
 
n = 4
pattern(n)
