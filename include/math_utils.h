#ifndef MATH_UTILS_H
#define MATH_UTILS_H

long long gcd(long long a, long long b);

long long mod_pow(long long base,
                  long long exponent,
                  long long modulus);
long long extended_gcd(long long a,
                       long long b,
                       long long &x,
                       long long &y);
long long mod_inverse(long long e,
                      long long phi);
bool is_prime(long long number);
long long generate_prime(long long min, long long max);
long long choose_e(long long phi);
bool miller_rabin(long long n, int rounds);

#endif