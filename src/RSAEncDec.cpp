#include "RSAEncDec.h"
#include "calculateCoefficients.h"
#include <cmath>

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

RSAEncDec::RSAEncDec(int p1,int p2)
{
    //ctor
    p=p1;
    q=p2;
    e=chooseEncryptionKey();
    d=generateDecryptionKey();
}


/** @brief encrypt
  *
  * @todo: document this function
  */
string RSAEncDec::encrypt(string str)
{
    for(int i=0;i<str.length();i++){
        str[i]=encryptEachCharacter(str[i]);
    }
    return str;
}

/** @brief decrypt
  *
  * @todo: document this function
  */
string RSAEncDec::decrypt(string)
{
    for(int i=0;i<str.length();i++){
        str[i]=decryptEachCharacter(str[i]);
    }
    return str;
}

/** @brief chooseEncryptionKey
  *
  * @todo: document this function
  */
int RSAEncDec::chooseEncryptionKey()
{
    int enc;
    for(i=(p-1)*(q-1)-1;i>=2;i--){
        enc=gcd((p-1)*(q-1),i);
    }
    return enc;
}

/** @brief generateDecryptionKey
  *
  * @todo: document this function
  */
int RSAEncDec::generateDecryptionKey()
{
    int a[1][2];
    a=calculateCoefficients(e,(p-1)*(q-1));
    return a[0][1];
}

/** @brief encryptEachCharacter
  *
  * @todo: document this function
  */
int RSAEncDec::encryptEachCharacter(int ch)
{
    return ((int)pow(ch,e))%(p)*(q);
}

/** @brief decryptEachCharacter
  *
  * @todo: document this function
  */
int RSAEncDec::decryptEachCharacter(int)
{
    return ((int)pow(ch,d))%(p)*(q);
}

