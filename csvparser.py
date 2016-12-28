INPATH = 'data5000.csv'  # path of top 5000 english words csv
SEP = ','  # separator for output files
DATA_DIR = 'data/'  # data folder


def word():
    f = open(INPATH)
    out = open(DATA_DIR + 'word-5000.csv', 'w')
    for line in f:
        line = line.split(',')
        out.write(line[1] + '\n')
    f.close()
    out.close()


def word_and_freq():
    f = open(INPATH)
    out = open(DATA_DIR + 'wordfreq-5000.csv', 'w')
    for line in f:
        line = line.split(',')
        wf = [line[1], line[3]]
        out.write(SEP.join(wf) + '\n')
    f.close()
    out.close()


def word_sequence_finder_output(seqout):
    f = open(seqout)
    out = open(DATA_DIR + 'word-seq-finder.csv', 'w')
    for line in f:
        line = line.split(',')
        out.write(line[0] + '\n')
    f.close()
    out.close()

if __name__ == '__main__':
    word()
