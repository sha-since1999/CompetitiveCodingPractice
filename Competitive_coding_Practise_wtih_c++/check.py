#funciton to solve
def Is_Possible(N, K, S):
    k=K
    c=0
    d=''
    for i in range(len(S)):
        if S[i]=='1':
            b=''
            a=S[i:k]
            if len(a) < K:
                break
            for j in a:
                if j=='0':
                    b=b+'1'
                else:
                    b=b+'0'

            c=c+1
            d=S
            S=''
            f=i-1
            if i>=0:
                S=S+d[:i]
                S=S+b
                l=len(d)-(len(d) - len(S))
                S=S+d[l:]
            else:
                S=S+b
                # l = len(d) - (len(d) - len(S)) # donot uncomment it
                S = S +d[k:]
        k = k + 1
    if S.count('0') == N:
        return 1
    return 0

    pass

T = int(input())
for _ in range(T):
    N = int(input())
    K = int(input())
    S= str(input())    
    out_ = Is_Possible(N, K, S)
    print(out_)