#include "../include/math_utils.h"
#include <cstdlib>
#include <random>

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}
long long mod_pow(long long base,
                  long long exponent,
                  long long modulus)
{
    long long result = 1;

    base %= modulus;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }

        exponent /= 2;
        base = (base * base) % modulus;
    }

    return result;
}
long long extended_gcd(long long a,
                       long long b,
                       long long &x,
                       long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1;
    long long y1;

    long long gcd = extended_gcd(b,
                                 a % b,
                                 x1,
                                 y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}
long long mod_inverse(long long e,
                      long long phi)
{
    long long x;
    long long y;

    long long gcd = extended_gcd(e, phi, x, y);

    if (gcd != 1)
    {
        return -1;
    }

    if (x < 0)
    {
        x += phi;
    }

    return x;
}
bool is_prime(long long number)
{
    if (number < 2)
    {
        return false;
    }

    for (long long i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
bool miller_rabin(long long n, int rounds)
{
    if (n < 2)
    {
        return false;
    }

    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0)
    {
        return false;
    }

    long long d = n - 1;
    int r = 0;

    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    for (int i = 0; i < rounds; ++i)
    {
        static std::mt19937 rng(std::random_device{}());

        std::uniform_int_distribution<long long> dist(2, n - 2);

        long long a = dist(rng);

        long long x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1)
        {
            continue;
        }

        bool probablyPrime = false;

        for (int j = 0; j < r - 1; ++j)
        {
            x = mod_pow(x, 2, n);

            if (x == n - 1)
            {
                probablyPrime = true;
                break;
            }
        }

        if (!probablyPrime)
        {
            return false;
        }
    }

    return true;
}
long long generate_prime(long long min, long long max)
{
    long long candidate;

    do
    {
        candidate = min + rand() % (max - min + 1);
   } while (!miller_rabin(candidate, 5));

    return candidate;
}
long long choose_e(long long phi)
{
    for (long long e = 3; e < phi; e += 2)
    {
        if (gcd(e, phi) == 1)
        {
            return e;
        }
    }

    return -1;
}