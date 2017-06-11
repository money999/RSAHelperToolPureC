#ifndef HELPER_H
#define HELPER_H

#include<openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>

int prikeyToRSA(const char *key, RSA **r);
int pubkeyToRSA(const char *key, RSA **r);
int RSAGetPKCS1(RSA *r, char res[]);
int RSAGetPKCS8(RSA *r, char res[]);
int RSAGetPub(RSA *r, char res[]);
int RSASignBase64(RSA *r, int type, const unsigned char *sour, int sourl, unsigned char res[]);
int RSAVerifyBase64(RSA *r, unsigned char *in, unsigned char out[], int *outl);
int RSAVerifyRes(RSA *r, unsigned char *in, int inl, unsigned char out[], int *outl);
int decodeBase64(const unsigned char *in, unsigned char out[], int *outl);
int RSAGetPubXml(RSA *r, char res[]);
int RSAGetPriXml(RSA *r, char res[]);

#endif // HELPER_H
