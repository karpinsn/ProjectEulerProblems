# Project Euler Problem 9
# A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

# a2 + b2 = c2
# For example, 32 + 42 = 9 + 16 = 25 = 52.

# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

D = 1000

for B in range(1, 500):
    Num = D * D - 2 * D * B
    Dem = 2 * D - 2 * B

    A = Num / Dem
    C = 1000 - A - B

    if A * A + B * B == C * C:
        print A * B * C
        break
