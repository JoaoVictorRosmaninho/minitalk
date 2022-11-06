

def set_relative_bit(n, position, tf):
    mask = 1 << position; 
    if (tf):
        return n | mask 
    return n & ~mask; 

print("before: {0:b}".format(5))
print("after: {0:b}".format(set_relative_bit(5, 1, True)))

print("before: {0:b}".format(5))
print("after: {0:b}".format(set_relative_bit(5, 1, False)))
