def multi_inverse(b, n):
    r1 = n
    r2 = b
    t1 = 0
    t2 = 1

    while(r1 > 0):
        q = int(r1/r2)
        r = r1 - q * r2
        r1 = r2
        r2 = r
        t = t1 - q * t2
        t1 = t2 
        t2 = t

        if(r1 == 1):
            inv_t = t1
            break

    return inv_t
