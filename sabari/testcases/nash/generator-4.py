import random

num_test_files = 7
MAXN = 300

def get_num(low_lim=0, up_lim=9):
    return random.randint(low_lim, 10**random.randint(1, up_lim))

def main():
    T = [random.randint(50, 75) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        print 'Starting %d' % (idx)
        with open('nash_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                n = random.randint(1, MAXN)
                m = random.randint(1, MAXN)
                outfile.write(str(n) + ' ' + str(m)+'\n')
                outfile.write(str(get_num()) + ' ' +str(get_num()) + ' ' + str(get_num())+ ' ')
                outfile.write(str(get_num()) + ' ' +str(get_num(3, 5)) + '\n')
                sz -= 1

if __name__ == '__main__':
    main()
