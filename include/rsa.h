#ifndef RSA_H
#define RSA_H
#include <string>

class RSA
{
private:

    long long p;
    long long q;

    long long n;
    long long phi;

    long long e;
    long long d;

public:

    RSA();

    void generate_keys();

    long long encrypt(long long message);

    long long decrypt(long long cipher);

    void encrypt_file(const std::string& inputFile,
                  const std::string& outputFile);

    void decrypt_file(const std::string& inputFile,
                  const std::string& outputFile);

    void print_keys();
    
    void save_keys(const std::string& filename);

    void load_keys(const std::string& filename);
};
#endif