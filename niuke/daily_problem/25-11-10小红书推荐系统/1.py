import sys
from collections import Counter

# read one line
line = sys.stdin.readline().strip()

# split words by space
word = line.split()
counts = Counter(word) # count the frequency of each word

keywords = []

# filter words that appear at least 3 times
for word,count in counts.items():
    if count >= 3:
        keywords.append((word,count))

# sort by the counts by descending order
keywords.sort(key = lambda x:(-x[1],x[0]))

for word,count in keywords:
    print(word)