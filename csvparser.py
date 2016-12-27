INPATH = 'wordfreq.csv'  # input file path
SEP = ','  # separator for output files


def word_and_freq():
    f = open(INPATH)
    out = open('wf.csv', 'w')
    for line in f:
        line = line.split(',')
        wf = [line[1], line[3]]
        out.write(SEP.join(wf) + '\n')


if __name__ == '__main__':
    word_and_freq()
