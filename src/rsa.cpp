#include "../include/rsa.h"
#include "../include/math_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

RSA::RSA()
{
    p = 0;
    q = 0;
    n = 0;
    phi = 0;
    e = 0;
    d = 0;
}

void RSA::generate_keys()
{
    cout << "Generating prime p..." << endl;
    p = generate_prime(50, 200);
    cout << "Found p = " << p << endl;

    cout << "Generating prime q..." << endl;
    q = generate_prime(50, 200);
    while (q == p)
    {
        q = generate_prime(50, 200);
    }
    cout << "Found q = " << q << endl;

    cout << "Computing RSA parameters..." << endl;
    n = p * q;
    phi = (p - 1) * (q - 1);

    e = choose_e(phi);

    cout << "Computing modular inverse..." << endl;
    d = mod_inverse(e, phi);

    cout << "RSA key generation complete!" << endl;
}

void RSA::print_keys()
{
    cout << endl;
    cout << "========== RSA Key Generation ==========" << endl;

    cout << "Prime p: " << p << endl;
    cout << "Prime q: " << q << endl;

    cout << endl;

    cout << "n = p * q = " << n << endl;

    cout << "phi(n) = (p - 1)(q - 1) = "
         << phi << endl;

    cout << endl;

    cout << "Public exponent (e): "
         << e << endl;

    cout << "Private exponent (d): "
         << d << endl;

    cout << endl;

    cout << "Public Key: ("
         << e
         << ", "
         << n
         << ")" << endl;

    cout << "Private Key: ("
         << d
         << ", "
         << n
         << ")" << endl;

    cout << "========================================" << endl;
}

long long RSA::encrypt(long long message)
{
    return mod_pow(message, e, n);
}

long long RSA::decrypt(long long cipher)
{
    return mod_pow(cipher, d, n);
}
void RSA::encrypt_file(const std::string& inputFile,
                       const std::string& outputFile)
{
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input)
    {
        cout << "Error: Could not open " << inputFile << endl;
        return;
    }

    if (!output)
    {
        cout << "Error: Could not open " << outputFile << endl;
        return;
    }

    char letter;

    while (input.get(letter))
    {
        long long encrypted =
            encrypt(static_cast<long long>(letter));

        output << encrypted << " ";
    }

    input.close();
    output.close();

    cout << "Encrypted file saved to " << outputFile << endl;
}
void RSA::decrypt_file(const std::string& inputFile,
                       const std::string& outputFile)
{
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input)
    {
        cout << "Error: Could not open " << inputFile << endl;
        return;
    }

    if (!output)
    {
        cout << "Error: Could not open " << outputFile << endl;
        return;
    }

    long long cipher;

    while (input >> cipher)
    {
        long long decrypted = decrypt(cipher);
        output << static_cast<char>(decrypted);
    }

    input.close();
    output.close();

    cout << "Decrypted file saved to " << outputFile << endl;
}
void RSA::save_keys(const std::string& filename)
{
    ofstream output(filename);

    if (!output)
    {
        cout << "Error opening " << filename << endl;
        return;
    }

    output << p << endl;
    output << q << endl;
    output << n << endl;
    output << phi << endl;
    output << e << endl;
    output << d << endl;

    output.close();

    cout << "Keys saved to " << filename << endl;
}
void RSA::load_keys(const std::string& filename)
{
    ifstream input(filename);

    if (!input)
    {
        cout << "Error opening " << filename << endl;
        return;
    }

    input >> p;
    input >> q;
    input >> n;
    input >> phi;
    input >> e;
    input >> d;

    input.close();

    cout << "Keys loaded from " << filename << endl;
}