def for_loop(n:int)->int:
    res = 0
    for i in range(1,n+1): #这里要从 1 开始
        res += i
    return res

def while_loop(n:int)->int:
    res = 0
    i = n
    while i > 0:
        res += i
        i -= 1

    return res

def while_loopii(n):
    res = 0
    i = 1
    while i < n:
        res += i;
        i = 2*i + 2
    
    return res

def nested_for_loop(n)->str:
    res = ""
    for i in range(1,n+1):
        for j in range(1,n+1):
            res += f"{i},{j},"

    return res


def main():
    n = 5
    print(for_loop(5))
    print(while_loop(5))
    print(while_loopii(5))

    print(nested_for_loop(5))


if __name__ == "__main__":
    main()
