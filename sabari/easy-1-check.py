import random
def main():
    with open('in', 'w') as outfile:
        lst = list()
        t = 10000
        outfile.write(str(t)+'\n')
        while t >= 0:
            if t < 500:
                outfile.write(str(random.randint(2, 9)**random.randint(2, 16))+'\n')
            else:
                outfile.write(str(random.randint(2, 10**16))+'\n')
            t -= 1

if __name__ == '__main__':
    main()
