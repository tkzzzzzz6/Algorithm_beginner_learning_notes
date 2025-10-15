import time

start_time = time.time()
i = 0
for a in range(1001):
    for b in range(1001):
        for c in range(1001):
            if a+b+c == 1000 and a**2 + b**2 == c**2:
                print(f"a, b, c:({a},{b},{c})")
                used_time = time.time() - start_time
                print(f"count{i} take {used_time} seconds")
                i += 1

end_time = time.time()
print(f"Time taken: {end_time - start_time} seconds") 
print("finished")