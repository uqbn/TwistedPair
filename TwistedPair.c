/************************************************************
* ���ߣ���ҫ��              Author: Geek.Zhiyuan            *
* ��Դ���ڣ�2022��6��7��    Open Source Date: 2022-6-7      *
* ���ҳ��У��й�����        City, Country: GuangZhou, China *
************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void Usage()
{
    printf("Usage\n\tEncryption: TwistedPair -e/-E Plaintext.file Ciphertext.file Password\n\tDecryption: TwistedPair -d/-D Ciphertext.file Plaintext.file Password\n");
}

void Trinary(unsigned char *ucpTrinary,
             long long lNumeric)
{
    ucpTrinary[0] = ucpTrinary[1] = ucpTrinary[2] = ucpTrinary[3] = ucpTrinary[4] = ucpTrinary[5] =  0;

    if (lNumeric != 0)
    {
        for (long long i = 5; i > -1; --i)
        {
            ucpTrinary[i] = lNumeric % 3;

            lNumeric /= 3;
        }
    }
}

// 0 0 2
// 1 1 1
// 2 2 0

void TrinaryXOr0(unsigned char *ucpCiphertextOrPlaintext,
                 unsigned char *ucpPassword)
{
    for (long long j = 0; j < 6; ++j)
    {
        if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
        else if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
        else if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
    }
}

// 0 2 2
// 1 1 1
// 2 0 0

void TrinaryXOr2(unsigned char *ucpCiphertextOrPlaintext,
                 unsigned char *ucpPassword)
{
    for (long long j = 0; j < 6; ++j)
    {
        if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
        else if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 0 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 1 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 1;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 0)
        {
            ucpCiphertextOrPlaintext[j] = 2;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 1)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
        else if (ucpCiphertextOrPlaintext[j] == 2 && ucpPassword[j] == 2)
        {
            ucpCiphertextOrPlaintext[j] = 0;
        }
    }
}

// 2 0 0
// 1 1 1
// 0 2 2

void TrinaryXAnd0(unsigned char *ucpCiphertextOrPlaintext,
                  unsigned char *ucpPassword)
{
    for (long long k = 0; k < 6; ++k)
    {
        if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
        else if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
    }
}

// 2 2 0
// 1 1 1
// 0 0 2

void TrinaryXAnd2(unsigned char *ucpCiphertextOrPlaintext,
                  unsigned char *ucpPassword)
{
    for (long long k = 0; k < 6; ++k)
    {
        if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
        else if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
        else if (ucpCiphertextOrPlaintext[k] == 0 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 1 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 1;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 0)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 1)
        {
            ucpCiphertextOrPlaintext[k] = 0;
        }
        else if (ucpCiphertextOrPlaintext[k] == 2 && ucpPassword[k] == 2)
        {
            ucpCiphertextOrPlaintext[k] = 2;
        }
    }
}

long long main(long long argc,
               char *argv[])
{
    if (argc != 5)
    {
        Usage();
    }
    else if (*(short*)argv[1] == 0x452D || *(short*)argv[1] == 0x652D)
    {
        struct stat tStatFileSize;

        stat(argv[2], &tStatFileSize);

        unsigned long long ulFileSize = tStatFileSize.st_size;

        if (ulFileSize == 0)
        {
            printf("There is no data in file [%s], 0 byte.\n", argv[2]);

            return -1;
        }

        int fdPlaintextOrCiphertext = open(argv[2], O_BINARY | O_RDONLY, S_IREAD | S_IWRITE);

        unsigned char *ucpPlaintext = (unsigned char*)malloc(ulFileSize), ucaPlaintextOrCiphertext[6];

        read(fdPlaintextOrCiphertext, ucpPlaintext, ulFileSize);

        close(fdPlaintextOrCiphertext);

        unsigned short *uspCiphertext = (unsigned short*)malloc(2 * ulFileSize);

        unsigned char ucPasswordLength = -1;

        while(argv[4][++ucPasswordLength]);

        unsigned char *ucpPassword = (unsigned char*)malloc(6 * ucPasswordLength);

        for (unsigned char i = 0; i < ucPasswordLength; ++i)
        {
            Trinary(ucpPassword + 6 * i, argv[4][i]);
        }

        for (unsigned long long j = 0, k = 0; j < ulFileSize; ++j)
        {
            Trinary(ucaPlaintextOrCiphertext, ucpPlaintext[j]);

            TrinaryXOr0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXOr2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            /*TrinaryXOr0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXOr0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXOr2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXOr2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd0(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaPlaintextOrCiphertext, ucpPassword + 6 * k);*/

            uspCiphertext[j] = 243 * ucaPlaintextOrCiphertext[0] + 81 * ucaPlaintextOrCiphertext[1] + 27 * ucaPlaintextOrCiphertext[2] + 9 * ucaPlaintextOrCiphertext[3] + 3 * ucaPlaintextOrCiphertext[4] + ucaPlaintextOrCiphertext[5];

            k = ++k % ucPasswordLength;
        }

        fdPlaintextOrCiphertext = open(argv[3], O_BINARY | O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

        write(fdPlaintextOrCiphertext, uspCiphertext, 2 * ulFileSize);

        close(fdPlaintextOrCiphertext);

        free(uspCiphertext);

        free(ucpPlaintext);
    }
    else if (*(short*)argv[1] == 0x442D || *(short*)argv[1] == 0x642D)
    {
        struct stat tStatFileSize;

        stat(argv[2], &tStatFileSize);

        unsigned long long ulFileSize = tStatFileSize.st_size;

        if (ulFileSize == 0)
        {
            printf("There is no data in file [%s], 0 byte.\n", argv[2]);

            return -1;
        }

        int fdCiphertextOrPlaintext = open(argv[2], O_BINARY | O_RDONLY, S_IREAD | S_IWRITE);

        unsigned short *uspCiphertext = (unsigned short*)malloc(ulFileSize);

        read(fdCiphertextOrPlaintext, uspCiphertext, ulFileSize);

        close(fdCiphertextOrPlaintext);

        ulFileSize /= 2;

        unsigned char *ucpPlaintext = (unsigned char*)malloc(ulFileSize), ucaCiphertextOrPlaintext[6];

        unsigned char ucPasswordLength = -1;

        while(argv[4][++ucPasswordLength]);

        unsigned char *ucpPassword = (unsigned char*)malloc(6 * ucPasswordLength);

        for (unsigned char i = 0; i < ucPasswordLength; ++i)
        {
            Trinary(ucpPassword + 6 * i, argv[4][i]);
        }

        for (unsigned long long j = 0, k = 0; j < ulFileSize; ++j)
        {
            Trinary(ucaCiphertextOrPlaintext, uspCiphertext[j]);

            TrinaryXOr2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXOr0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            /*TrinaryXAnd0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXOr0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXOr0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXAnd0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXOr2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXOr2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXAnd2(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);

            TrinaryXAnd0(ucaCiphertextOrPlaintext, ucpPassword + 6 * k);*/

            ucpPlaintext[j] = 243 * ucaCiphertextOrPlaintext[0] + 81 * ucaCiphertextOrPlaintext[1] + 27 * ucaCiphertextOrPlaintext[2] + 9 * ucaCiphertextOrPlaintext[3] + 3 * ucaCiphertextOrPlaintext[4] + ucaCiphertextOrPlaintext[5];

            k = ++k % ucPasswordLength;
        }

        fdCiphertextOrPlaintext = open(argv[3],  O_BINARY | O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

        write(fdCiphertextOrPlaintext, ucpPlaintext, ulFileSize);

        close(fdCiphertextOrPlaintext);

        free(ucpPlaintext);

        free(uspCiphertext);
    }
    else
    {
        Usage();
    }

    return 0;
}