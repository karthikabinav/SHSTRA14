import random

num_test_files = 7
MAXN = 18

def get_lower_bound(n, _type):
    kprime = random.randint(0, 10)
    if _type==0 or _type==5: return n*n
    if _type==1 or _type==6: return n*n-n
    if _type==2: return n*(n-1)/2
    if _type==3: return min(n*n, n+n/2)
    return min(n+1, n*n)

def main():
    T = [random.randint(13, 15) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        print 'Starting %d' % (idx)
        with open('bipartite_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                n = random.randint(1, MAXN)
                m = random.randint(get_lower_bound(n, idx), n*n)
                outfile.write(str(n) + ' ' + str(m)+'\n')
                vis = [[False for i in range(n)] for j in range(n)]
                # vertices are numbered 0 to n-1
                for i in range(m):
                    a, b = 0, 0
                    while vis[a][b]:
                        a = random.randint(0, n-1)
                        b = random.randint(0, n-1)
                    vis[a][b] = True
                    outfile.write(str(a) + ' '+str(b+n)+'\n')
                sz -= 1

if __name__ == '__main__':
    main()
