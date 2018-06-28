### Data Folder
Here are the naming conventions for the data files:
- Files ending with **-5000** were generated from the top 5000 words in the English lanugage by 
frequency, as stored in `word-5000.csv`, while those ending with **-400k** were generated from 
the file `data400k.txt`.
- Files starting with **problem-** contain char sequences that are considered problematic in the 
context of this research.
- Files containing **two-** deal with char sequences of size 2, while files containing 
**three-** deal with char sequences of size 3.
- Files containing **seq-freq** store frequencies of char sequences
- `word-5000.csv` contains extracted words from `data5000.csv`