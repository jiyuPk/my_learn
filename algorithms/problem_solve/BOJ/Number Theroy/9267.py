def extended_euclidean(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x, y = extended_euclidean(b, a % b)
    return gcd, y, x - (a // b) * y


def eval(a, b, s):
    if a == 0 and b == 0:
        return s == 0
    if a == 0:
        return s % b == 0
    if b == 0:
        return s % a == 0

    gcd, x, y = extended_euclidean(a, b)

    if s % gcd != 0:
        return False

    x *= s // gcd
    y *= s // gcd

    for i in range(-gcd * x // b + 1, gcd * y // a + 1):
        if extended_euclidean(x + i * b // gcd, y - i * a // gcd)[0] == 1:
            return True

    return False


a, b, s = map(int, input().split())
if eval(a, b, s):
    print("YES")
else:
    print("NO")