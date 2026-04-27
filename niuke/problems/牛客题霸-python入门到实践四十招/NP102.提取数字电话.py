# @nc app=nowcoder id=6e25b95632e6433db4b5053f91138cb5 topic=314 question=10060019 lang=Python3
# 2026-04-27 23:07:03
# https://www.nowcoder.com/practice/6e25b95632e6433db4b5053f91138cb5?tpId=314&tqId=10060019
# [NP102] 提取数字电话

# @nc code=start

import sys

for line in sys.stdin:
    a = line.split()
    print(int(a[0]) + int(a[1]))


# @nc code=end
