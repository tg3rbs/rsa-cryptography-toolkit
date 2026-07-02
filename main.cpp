/*
  File: main.cpp
  Created by: Theo Gerber
  Creation Date: June 29, 2026
  Synopsis: Main driver for the RSA Cryptography Toolkit.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "include/rsa.h"
#include "include/math_utils.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    RSA rsa;
    bool keysGenerated = false;
    int choice;

    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "   RSA Cryptography Toolkit" << endl;
        cout << "==================================" << endl;
        cout << "1. Generate RSA Keys" << endl;
        cout << "2. Encrypt Message" << endl;
        cout << "3. Decrypt Message" << endl;
        cout << "4. Load Saved Keys" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            rsa.generate_keys();
            keysGenerated = true;

            cout << endl;
            cout << "Keys generated successfully!" << endl;

            rsa.print_keys();

            rsa.save_keys("keys.txt");
        }
        else if (choice == 2)
        {
            rsa.encrypt_file("examples/sample_message.txt", "encrypted.txt");
        }
        else if (choice == 3)
        {
            rsa.decrypt_file("encrypted.txt", "decrypted.txt");
        }
        else if (choice == 4)
        {
            rsa.load_keys("keys.txt");
            keysGenerated = true;
            rsa.print_keys();
        }
        else if (choice == 5)
        {
            cout << "Exiting RSA Toolkit." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}