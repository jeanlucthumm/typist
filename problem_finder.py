INPATH = 'w-s.csv'

"""
FINGER DATA
"""
data = dict()
data['a'] = 1
data['b'] = 4
data['c'] = 4
data['d'] = 3
data['e'] = 3
data['f'] = 4
data['g'] = 4
data['h'] = 5
data['i'] = 6
data['j'] = 5
data['k'] = 6
data['l'] = 7
data['m'] = 5
data['n'] = 5
data['o'] = 7
data['p'] = 8
data['q'] = 1
data['r'] = 4
data['s'] = 2
data['t'] = 4
data['u'] = 5
data['v'] = 4
data['w'] = 2
data['x'] = 2
data['y'] = 5
data['z'] = 1
data['\''] = 8
data['\"'] = 8


def is_same_finger(a, b):
    return data[a] == data[b]


def find_same_finger(seqListPath):
    f = open(seqListPath)
    out = open('problem-seq-400k.csv', 'w')

    # Loop through each substring
    for line in f:
        sub, freq = line.split(',')
        try:
            if is_same_finger(sub[0], sub[1]):
                out.write(sub + "," + freq)
        except KeyError:
            print('no data for seq:', sub)

    f.close()
    out.close()


if __name__ == '__main__':
    find_same_finger('two-seq-freq-400k.csv')
    # find_same_finger('two-seq-freq.csv')