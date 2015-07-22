#ifndef RSAENCDEC_H
#define RSAENCDEC_H


class RSAEncDec
{
    public:
        RSAEncDec(int,int);
        string encrypt(string);
        string decrypt(string);
    protected:
    private:
        int p,q,e,d;
        int chooseEncryptionKey();
        int generateDecryptionKey();
        int encryptEachCharacter(int);
        int decryptEachCharacter(int);
};

#endif // RSAENCDEC_H
