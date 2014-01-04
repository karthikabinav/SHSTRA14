import random

num_test_files = 7
MAXN = 5*(10**2)
MAXE = (MAXN*MAXN/2)

def get_lower_bound(n, _type):
    if _type < 6: return n*(n-1)/2
    if _type < 12: return min(n*(n-1)/2, max(n*(n-1)/2 - n, n+1))
    return 0

def const_complete(outfile, strt_idx, nNode):
    vis = [[False for i in range(nNode+1)] for j in range(nNode+1)]
    edges = nNode*(nNode-1)/2
    for i in range(edges):
        a, b = 0, 0
        while a == b or vis[a][b]:
            a = random.randint(1, nNode)
            b = random.randint(1, nNode)
        vis[a][b] = True
        outfile.write("%d %d\n" % (a+strt_idx,b+strt_idx))


def main():
    T = [random.randint(20,20) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        print 'Starting %d' % (idx+1)
        with open('kanpur_in_'+str(idx+1), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                n = random.randint(1, MAXN)
                m = min(MAXE, random.randint(get_lower_bound(n, idx), n*(n-1)/2))

                kprime = random.randint(0, 3)
                if kprime < 4:
                    Comp1 = random.randint(0, n)
                    Comp2 = random.randint(0, n-Comp1)
                    Comp3 = n - Comp1 - Comp2

                    m = Comp1*(Comp1-1)/2 + Comp2*(Comp2-1)/2
                    comp3_m = random.randint(0, min(min(MAXE-m, max(Comp1, Comp2)), Comp3))
                    m += comp3_m

                    outfile.write(str(n) + ' ' + str(m)+'\n')
                    if Comp1 != 0: const_complete(outfile, 0, Comp1)
                    if Comp2 != 0: const_complete(outfile, Comp1, Comp2)
                    if Comp3 == 0: continue

                    vis = [[False for i in range(Comp3+1)] for j in range(Comp1+Comp2+1)]
                    mainvis = [[False for i in range(2)] for j in range(Comp3+1)]

                    vis[0][0] = True
                    for i in range(comp3_m):
                        a, b = 0, 0
                        t = 0
                        while vis[a][b] or mainvis[b][t]:
                            b = random.randint(1, Comp3)
                            if mainvis[b][0] and Comp2 != 0:
                                a = random.randint(Comp1+1, Comp2 + Comp1)
                            elif mainvis[b][1] and Comp1 != 0:
                                a = random.randint(1, Comp1)
                            else:
                                a = random.randint(1, Comp1+Comp2)
                            if a > Comp1: t = 1
                            else: t = 0
                        vis[a][b] = True
                        mainvis[b][t] = True
                        outfile.write("%d %d\n" % (a, b+Comp1+Comp2))
                else:
                    vis = [[False for i in range(n+1)] for j in range(n+1)]
                    for i in range(m):
                        a,b = 0, 0
                        while a == b or vis[a][b]:
                            a = random.randint(1, n)
                            b = random.randint(1, n)
                        vis[a][b] = True
                        outfile.write("%d %d\n" % (a,b))
                sz -= 1

if __name__ == '__main__':
    main()
