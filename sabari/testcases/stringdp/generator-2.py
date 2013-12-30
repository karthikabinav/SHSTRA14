import random
import numpy

num_test_files = 7
MAXN = 10000
STR_SIZE = 5000
MAX_VAR = 100

def get_num(rem, is_last):
    if is_last == 0:
        return max(1, min(rem, STR_SIZE))
    num = -1
    while num <= 0 or num >= STR_SIZE:
        num = abs(numpy.random.normal(rem/is_last, MAX_VAR))
    return int(num)

def get_str(_len):
    string = ""
    for i in range(_len):
        string += str(unichr(random.randint(0, 25) + 65))
    return string

def get_kval(len1, len2):
    kprime = random.randint(0, 100)
    if kprime > 96:
        return min(len1, len2)+1
    return random.randint(0, min(len1, len2))

def main():
    T = [random.randint(2, 10) for i in range(num_test_files)]
    for idx, sz in enumerate(T):
        # To keep total length of all the string in a file < 10000
        total_len1, total_len2 = 0, 0
        with open('stringdp_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz > 0:
                len1 = get_num(MAXN-total_len1, sz)
                len2 = get_num(MAXN-total_len2, sz);
                kval = get_kval(len1, len2)
                outfile.write(str(len1)+' '+str(len2)+' '+str(kval)+'\n')
                total_len1 += len1
                total_len2 += len2
                outfile.write(str(get_str(len1))+'\n')
                outfile.write(str(get_str(len2))+'\n')
                sz -= 1

if __name__ == '__main__':
    main()
