#ifndef HELPER_H
#define HELPER_H

#include<openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>
#include <openssl/err.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

int prikeyToRSA(const char *key, RSA **r, void *pass);
int pubkeyToRSA(const char *key, RSA **r);
int pubPKCS1keyToRSA(const char *key, RSA **r);
int xmlkeyToRSA(const char *key, RSA **r);
int RSAGetPKCS1(RSA *r, char res[], const EVP_CIPHER *enc, void *pass);
int RSAGetPKCS8(RSA *r, char res[], const EVP_CIPHER *enc, void *pass);
int RSAGetPubPKCS1(RSA *r, char res[]);
int RSAGetPub(RSA *r, char res[]);
int RSAGetPubXml(RSA *r, char res[]);
int RSAGetPriXml(RSA *r, char res[]);
int RSASignBase64(RSA *r, int type, const unsigned char *sour, int sourl, unsigned char res[]);
int RSASignHashBase64(RSA *r, int type, const unsigned char *sourHash, int sourl, unsigned char res[]);
int RSAVerifyBase64(RSA *r, unsigned char *in, unsigned char out[], int *outl, int *type);
int RSAVerifyRes(RSA *r, unsigned char *in, int inl, unsigned char out[], int *outl, int *type);
int decodeBase64(const unsigned char *in, unsigned char out[], int *outl);
int parseXml(const char *keyword, const char* str, char res[]);

#endif // HELPER_H
