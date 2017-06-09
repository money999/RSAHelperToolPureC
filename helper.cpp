#include "helper.h"

/**
 * @brief prikeyToRSA
 * @param str 必须是pem格式,注意在头标后和尾表前保证有一个/n, pkcs1或pcks8都行
 * @param r
 * @return
 * 注意!!!调用函数一定要在外部RSA_free(r)!!!
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
 * @param str 参数要保证有足够的空间，建议2000byte,不想内部申请怕忘记释放
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
 * @param str 参数要保证有足够的空间，建议2000byte,不想内部申请怕忘记释放
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
 * @param res 获取公钥，公钥是PEM格式，头部尾部没有RSA关键字
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
 * @param res base64字符串以\0结尾, 因为密钥长度最长256，base64以后应该不会超过500
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
 * @param in  输入的不是base64，是私钥签名后的内容
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
 * @param outl 用EVP_DecodeBlock函数不会自动去掉后面的‘=’所以是3的倍数，要自己去掉‘=’的位数
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





