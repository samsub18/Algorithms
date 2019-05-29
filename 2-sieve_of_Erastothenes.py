sieve = set(range(2, 101)) # Set of all numbers from 2 to 100
                           # Python is so easy !! 
                           # C is a bit complex and a bit tricky

while sieve:
    m = min(sieve)
    print(m)
    sieve = sieve - set(range(m, 101, m))
