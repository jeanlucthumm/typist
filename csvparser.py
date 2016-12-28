INPATH = 'wordfreq.csv'  # input file path
SEP = ','  # separator for output files


def word():
    f = open(INPATH)
    out = open('w.csv', 'w')
    for line in f:
        line = line.split(',')
        out.write(line[1] + '\n')
    f.close()
    out.close()


def word_and_freq():
    f = open(INPATH)
    out = open('wf.csv', 'w')
    for line in f:
        line = line.split(',')
        wf = [line[1], line[3]]
        out.write(SEP.join(wf) + '\n')
    f.close()
    out.close()


def word_sequence_finder_output(seqout):
    f = open(seqout)
    out = open('w-s.csv', 'w')
    for line in f:
        line = line.split(',')
        out.write(line[0] + '\n')
    f.close()
    out.close()

if __name__ == '__main__':
    # word_sequence_finder_output('two-seq-freq.csv')
    word()
    # word_and_freq()
