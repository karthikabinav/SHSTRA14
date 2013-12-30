import random

num_test_files = 7

def get_num(base_range, power_range):
    num = 0
    while num <= 0:
        base = random.randint(2, 10**base_range)
        power = random.randint(2, power_range)
        num = int(base**(1.0/power))**power
    return num

def main():
    T = [random.randint(10, 10000) for i in range(num_test_files)]
    base_list = [5, 9, 12, 14, 16, 5, 9, 12, 14, 16]
    power_list = [5, 10, 15, 20, 25, 3, 5, 5, 7, 7]
    for idx, sz in enumerate(T):
        with open('apowb_in_'+str(idx), 'w') as outfile:
            outfile.write(str(sz)+'\n')
            while sz >= 0:
                num = 0;
                k = random.randint(0, 9)
                # with prob = 0.4 output yes
                if k <= 3:
                    kprime = random.randint(0, 9)
                    num = get_num(base_list[kprime], power_list[kprime])
                else:
                    # Choose a range to generate the test case (uniformly)
                    kprime = random.randint(0, 9)
                    num = random.randint(2, 10**base_list[kprime])
                sz -= 1
                outfile.write(str(num) + '\n');

if __name__ == '__main__':
    main()
