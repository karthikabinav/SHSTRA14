import random
import numpy

num_test_files = 7

def print_lst(outfile, lst):
    for i in range(len(lst)):
        outfile.write(str(lst[i]))
        if i == len(lst)-1:
            outfile.write('\n')
        else:
            outfile.write(' ')

def get_list(sz):
    lst = list()
    for i in range(sz):
        kprime = random.randint(1, 18)
        lst.append(random.randint(0, 10**kprime))
    return lst

def get_sec_list(sz, arr):
    lst = list()
    for i in range(sz):
        lst.append(random.randint(0, arr[i]))
    return lst

def main():
    T = [random.randint(75, 100) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        with open('grundy_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                n = random.randint(1, 2000)
                outfile.write(str(n)+'\n')
                lim = get_list(n);
                cur = get_sec_list(n, lim)
                print_lst(outfile, cur)
                print_lst(outfile, lim)
                sz -= 1
            print '%d done' % (idx+1)

if __name__ == '__main__':
    main()
