INPATH = 'wordfreq.csv'

f = open(INPATH)
out = open('out.csv', 'w')

for line in f:
    line = line.split(',')
    line[1] = line[1][3:]
    for i in range(0, 5):
        out.write(line[i])
        if i != 4:
            out.write(',')

f.close()
out.close()

