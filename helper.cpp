#include "helper.h"

/**
 * @brief prikeyToRSA
 * @param str ������pem��ʽ,ע����ͷ����β��ǰ��֤��һ��/n, pkcs1��pcks8����
 * @param r
 * @return
 * ע��!!!���ú���һ��Ҫ���ⲿRSA_free(r)!!!
 */
int prikeyToRSA(const char *key, RSA **r){
    BIO *keybio = BIO_new_mem_buf(key, -1);
    *r = PEM_read_bio_RSAPrivateKey(keybio, r,NULL, NULL);
    BIO_free(keybio);
    return 1;
}

/**
 * @brief pubkeyToRSA
 * @param key
 * @param r
 * @return
 */
int pubkeyToRSA(const char *key, RSA **r)
{
    BIO *keybio = BIO_new_mem_buf(key, -1);
    *r = PEM_read_bio_RSA_PUBKEY(keybio, r, NULL, NULL);
    BIO_free(keybio);
    return 1;
}

/**
 * @brief RSAGetPKCS1
 * @param r
 * @param str ����Ҫ��֤���㹻�Ŀռ䣬����2000byte,�����ڲ������������ͷ�
 * @return
 */
int RSAGetPKCS1(RSA *r, char res[]){
    int len;
    BIO *out=BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(out,r,NULL,NULL,0,NULL,NULL);
    len=BIO_ctrl_pending(out);
    BIO_read(out,res,len);
    res[len] = '\0';

    BIO_free(out);

    return 1;
}

/**
 * @brief RSAGetPKCS8
 * @param r
 * @param str ����Ҫ��֤���㹻�Ŀռ䣬����2000byte,�����ڲ������������ͷ�
 * @return
 */
int RSAGetPKCS8(RSA *r, char res[]){
    int len;
    BIO *out=BIO_new(BIO_s_mem());
    EVP_PKEY *k = EVP_PKEY_new();
    EVP_PKEY_set1_RSA(k, r);
    PEM_write_bio_PKCS8PrivateKey(out,k,NULL,NULL,NULL,NULL,NULL);
    len=BIO_ctrl_pending(out);
    len = BIO_read(out,res,len);
    res[len] = '\0';

    EVP_PKEY_free(k);
    BIO_free(out);

    return 1;
}

/**
 * @brief RSAGetPub
 * @param r
 * @param res ��ȡ��Կ����Կ��PEM��ʽ��ͷ��β��û��RSA�ؼ���
 * @return
 */
int RSAGetPub(RSA *r, char res[])
{
    int len;
    BIO *out=BIO_new(BIO_s_mem());
    PEM_write_bio_RSA_PUBKEY(out, r);
    len=BIO_ctrl_pending(out);
    len = BIO_read(out,res,len);
    res[len] = '\0';
    BIO_free(out);

    return 1;
}

/**
 * @brief RSASignBase64
 * @param r
 * @param type
 * @param sour
 * @param sourl
 * @param res base64�ַ�����\0��β, ��Ϊ��Կ�����256��base64�Ժ�Ӧ�ò��ᳬ��500
 * @return
 */
int RSASignBase64(RSA *r, int type, const unsigned char *sour, int sourl, unsigned char res[]){

    unsigned char hashStr[100], f[300];
    unsigned int flen;
    int resl;

    switch (type){
    case NID_sha1:
        SHA1(sour, sourl, hashStr);
        RSA_sign(NID_sha1, hashStr, SHA_DIGEST_LENGTH, f, &flen, r);
        resl = EVP_EncodeBlock(res, f, flen);
        res[resl]='\0';
        break;
    default:
        return 0;
        break;
    }

    return 1;
}

/**
 * @brief RSAVerifyRes
 * @param r
 * @param in  ����Ĳ���base64����˽Կǩ���������
 * @param inl
 * @param out
 * @param outl
 * @return
 */
int RSAVerifyRes(RSA *r, unsigned char *in, int inl, unsigned char out[], int *outl){

    X509_SIG *sig = NULL;
    unsigned char *s;
    int len;

    s = (unsigned char *)malloc((unsigned int)inl);
    len = RSA_public_decrypt(inl, in, s, r, RSA_PKCS1_PADDING);
    sig = d2i_X509_SIG(NULL, (const unsigned char**)&s, (long)len);
    *outl = sig->digest->length;
    memcpy(out, sig->digest->data, *outl);
    free(s);
    return 1;
}

int RSAVerifyBase64(RSA *r, unsigned char *in, unsigned char out[], int *outl)
{
    unsigned char tmp[500];
    int tmpl;
    decodeBase64(in, tmp, &tmpl);
    RSAVerifyRes(r, tmp, tmpl, out, outl);
}


/**
 * @brief decodeBase64
 * @param in
 * @param out
 * @param outl ��EVP_DecodeBlock���������Զ�ȥ������ġ�=��������3�ı�����Ҫ�Լ�ȥ����=����λ��
 * @return
 */
int decodeBase64(const unsigned char *in, unsigned char out[], int *outl){

    int tmpl, inl;
    inl = strlen((const char*)in);
    tmpl = EVP_DecodeBlock(out, in, inl);
    while(in[--inl] == '=') tmpl--;
    *outl = tmpl;
    return 1;
}





