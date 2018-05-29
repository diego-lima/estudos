# encoding: utf-8

def count(limit):
    """Acha todos os números a,b,c tais que a² + b² = c²
    :param limit: número máximo até onde vamos procurar a, b e c
    """
    result = 0
    for a in range(1, limit + 1):
        for b in range(a + 1, limit + 1):
            for c in range(b + 1, limit + 1):
                if c * c > a * a + b * b:
                    break

                if c * c == (a * a + b * b):
                    result += 1
    return result