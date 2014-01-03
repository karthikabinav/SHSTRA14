import random

num_test_files = 7
MAXN = 2*(10**2)
MAXE = (10**4)
LIM1 = 1000000000
LIM = 100

MAXK = 10**9

def get_lower_bound(n, _type):
    if _type < 3: return n*(n-1)/2
    if _type < 8: return min(n*(n-1)/2, max(n*(n-1)/2 - n, n+1))
    return 0

def main():
    T = [random.randint(10,10) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        print 'Starting %d' % (idx)
        with open('karp_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                n = random.randint(1, MAXN)
                m = min(MAXE, random.randint(get_lower_bound(n, idx), n*(n-1)/2))
                K = random.randint(1, MAXK)
                outfile.write(str(n) + ' ' + str(m)+ ' ' + str(K)+'\n')
                vis = [[False for i in range(n+1)] for j in range(n+1)]
                # vertices are numbered 0 to n-1
                for i in range(m):
                    a, b = 0, 0
                    while a == b or vis[a][b]:
                        a = random.randint(1, n)
                        b = random.randint(1, n)
                    vis[a][b] = True

                    a_arr = -1*random.randint(0, LIM1)
                    b_arr = random.randint(1, LIM)
                    c_arr = random.randint(-LIM1, LIM1)
                    d_arr = -1*random.randint(1, LIM)
                    outfile.write("%d %d %d %d %d %d\n" % (a, b, a_arr, b_arr, c_arr, d_arr));
                sz -= 1

if __name__ == '__main__':
    main()
