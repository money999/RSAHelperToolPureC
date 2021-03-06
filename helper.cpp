#include "helper.h"

/**
 * @brief prikeyToRSA
 * @param str 必须是pem格式,注意在头标后和尾表前保证有一个/n, pkcs1或pcks8都行
 * @param r 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * @return
 * 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * 需调用OpenSSL_add_all_algorithms()
 */
int prikeyToRSA(const char *key, RSA **r, void* pass){
    BIO *keybio = BIO_new_mem_buf(key, -1);
    *r = PEM_read_bio_RSAPrivateKey(keybio, r, NULL, pass);
    BIO_free(keybio);
    if(*r == NULL) return 0;
    return 1;
}

/**
 * @brief pubkeyToRSA
 * @param key
 * @param r 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * @return
 * 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * 需调用OpenSSL_add_all_algorithms()
 */
int pubkeyToRSA(const char *key, RSA **r)
{
    BIO *keybio = BIO_new_mem_buf(key, -1);
    *r = PEM_read_bio_RSA_PUBKEY(keybio, r, NULL, NULL);
    BIO_free(keybio);
    if(*r == NULL) return 0;
    return 1;
}

/**
 * @brief pubPKCS1keyToRSA
 * @param key
 * @param r 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * @return
 * 注意!!!调用函数一定要在外部RSA_free(r)!!!
 */
int pubPKCS1keyToRSA(const char *key, RSA **r)
{
    BIO *keybio = BIO_new_mem_buf(key, -1);
    *r = PEM_read_bio_RSAPublicKey(keybio, r, NULL, NULL);
    BIO_free(keybio);
    if(*r == NULL) return 0;
    return 1;
}

/**
 * @brief RSAGetPKCS1
 * @param r
 * @param res 参数要保证有足够的空间，建议6000byte,不想内部申请怕忘记释放
 * @return
 */
int RSAGetPKCS1(RSA *r, char res[], const EVP_CIPHER* enc, void* pass){
    if(r == NULL || RSA_check_key(r) == 0) return 0;

    int len;
    BIO *out=BIO_new(BIO_s_mem());
    if(PEM_write_bio_RSAPrivateKey(out,r,enc,NULL,0,NULL,pass) == 0) return 0;
    len=BIO_ctrl_pending(out);
    BIO_read(out,res,len);
    res[len] = '\0';
    BIO_free(out);

    return 1;
}

/**
 * @brief RSAGetPKCS8
 * @param r
 * @param res 参数要保证有足够的空间，建议6000byte,不想内部申请怕忘记释放
 * @return
 * 需调用OpenSSL_add_all_algorithms()
 */
int RSAGetPKCS8(RSA *r, char res[], const EVP_CIPHER* enc, void* pass){
    if(r == NULL || RSA_check_key(r) == 0) return 0;

    int len;
    BIO *out=BIO_new(BIO_s_mem());
    EVP_PKEY *k = EVP_PKEY_new();
    EVP_PKEY_set1_RSA(k, r);
    if(PEM_write_bio_PKCS8PrivateKey(out,k,enc,NULL,0,NULL,pass) == 0) return 0;
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
 * @param res 建议大小6000。获取公钥，公钥是PEM格式，头部尾部没有RSA关键字, SubjectPublicKeyInfo structure
 * @return
 */
int RSAGetPub(RSA *r, char res[]){
    if(RSAPubCheck(r) == 0) return 0;

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
 * @brief RSAGetPubPKCS1
 * @param r
 * @param res 建议大小6000
 * @return
 */
int RSAGetPubPKCS1(RSA *r, char res[]){
    if(RSAPubCheck(r) == 0) return 0;
    int len;
    BIO *out=BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(out, r);
    len=BIO_ctrl_pending(out);
    len = BIO_read(out,res,len);
    res[len] = '\0';
    BIO_free(out);

    return 1;
}

/**
 * @brief RSASignBase64
 * @param r
 * @param type hash类型
 * @param sour 待签名数据, 未hash
 * @param sourl
 * @param res base64字符串以\0结尾, 因为密钥长度最长768，base64以后应该不会超过6000
 * @return
 */
int RSASignBase64(RSA *r, int type, const unsigned char *sour, int sourl, unsigned char res[]){
    if(r == NULL || RSA_check_key(r) == 0) return 0;

    unsigned char hashStr[100], f[6000];
    unsigned int flen;
    int resl;

    switch (type){
    case NID_sha1:
        SHA1(sour, sourl, hashStr);
        RSA_sign(NID_sha1, hashStr, SHA_DIGEST_LENGTH, f, &flen, r);
        break;
    case NID_sha224:
        SHA224(sour, sourl, hashStr);
        RSA_sign(NID_sha224, hashStr, SHA224_DIGEST_LENGTH, f, &flen, r);
        break;
    case NID_sha256:
        SHA256(sour, sourl, hashStr);
        RSA_sign(NID_sha256, hashStr, SHA256_DIGEST_LENGTH, f, &flen, r);
        break;
    case NID_sha384:
        SHA384(sour, sourl, hashStr);
        RSA_sign(NID_sha384, hashStr, SHA384_DIGEST_LENGTH, f, &flen, r);
        break;
    case NID_sha512:
        SHA512(sour, sourl, hashStr);
        RSA_sign(NID_sha512, hashStr, SHA512_DIGEST_LENGTH, f, &flen, r);
        break;
    case NID_md5:
        MD5(sour, sourl, hashStr);
        RSA_sign(NID_md5, hashStr, MD5_DIGEST_LENGTH, f, &flen, r);
        break;
    default:
        return 0;
        break;
    }
    resl = EVP_EncodeBlock(res, f, flen);
    res[resl]='\0';
    return 1;
}

/**
 * @brief RSASignHashBase64,默认输入的值已是摘要
 * @param r
 * @param type
 * @param sourHash
 * @param res
 * @return
 */
int RSASignHashBase64(RSA *r, int type, const unsigned char *sourHash, int sourl, unsigned char res[])
{
    if(r == NULL || RSA_check_key(r) == 0) return 0;

    unsigned char f[6000];
    unsigned int flen;
    int resl;

    RSA_sign(type, sourHash, sourl, f, &flen, r);
    resl = EVP_EncodeBlock(res, f, flen);
    res[resl]='\0';
    return 1;
}

/**
 * @brief RSAVerifyRes
 * @param r
 * @param in  私钥签名后的内容，未经base64编码
 * @param inl
 * @param out 获取签名前的hash值，可将文本hash后对比是否一致
 * @param outl
 * @return
 */
int RSAVerifyRes(RSA *r, unsigned char *in, int inl, unsigned char out[], int *outl, int *type){
    if(RSAPubCheck(r) == 0) return 0;

    X509_SIG *sig = NULL;
    unsigned char *s;
    int len;
    s = (unsigned char *)malloc((unsigned int)inl);
    len = RSA_public_decrypt(inl, in, s, r, RSA_PKCS1_PADDING);
    if(len == -1){
        free(s);
        return 0;
    }
    sig = d2i_X509_SIG(NULL, (const unsigned char**)&s, (long)len);
    X509_ALGOR *palg;
    ASN1_OCTET_STRING *pdigest;
    X509_SIG_getm(sig, &palg, &pdigest);
    *outl = pdigest->length;
    memcpy(out, pdigest->data, *outl);
    if(type != NULL){        
        *type = OBJ_obj2nid(palg->algorithm);
    }
    free(s);
    if(sig){X509_SIG_free(sig); sig = NULL;}
    return 1;
}

/**
 * @brief RSAVerifyBase64
 * @param r
 * @param in 私钥签名后的内容，经base64编码
 * @param out
 * @param outl 获取签名前的hash值，可将文本hash后对比是否一致
 * @return
 */
int RSAVerifyBase64(RSA *r, unsigned char *in, unsigned char out[], int *outl, int *type){
    if(RSAPubCheck(r) == 0) return 0;

    unsigned char tmp[6000];
    int tmpl;
    decodeBase64(in, tmp, &tmpl);
    return RSAVerifyRes(r, tmp, tmpl, out, outl, type);
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
    if(tmpl == -1) return 0;
    while(in[--inl] == '=') tmpl--;
    *outl = tmpl;
    return 1;
}

/**
 * @brief RSAGetPubXml
 * @param r
 * @param res 建议大小6000
 * @return
 */
int RSAGetPubXml(RSA *r, char res[])
{
    if(RSAPubCheck(r) == 0) return 0;
    unsigned char tmp[2][6000];
    int tmpl[2];
    const BIGNUM *n, *e, *d;
    RSA_get0_key(r, &n, &e, &d);
    tmpl[0] = BN_bn2bin(n, tmp[0]);
    tmpl[1] = BN_bn2bin(e, tmp[1]);
    unsigned char blo[2][6000];
    EVP_EncodeBlock(blo[0], tmp[0], tmpl[0]);
    EVP_EncodeBlock(blo[1], tmp[1], tmpl[1]);
    sprintf(res, "<RSAKeyValue><Modulus>%s</Modulus><Exponent>%s</Exponent></RSAKeyValue>", blo[0], blo[1]);
    return 1;
}

/**
 * @brief RSAGetPriXml
 * @param r
 * @param res 建议大小2000~6000
 * @return
 */
int RSAGetPriXml(RSA *r, char res[])
{
    if(r == NULL || RSA_check_key(r) == 0) return 0;
    unsigned char tmp[8][6000];
    int tmpl[8];
    const BIGNUM *n=NULL, *e=NULL, *d=NULL, *p=NULL, *q=NULL, *dmp1=NULL, *dmq1=NULL, *iqmp=NULL;
    RSA_get0_key(r, &n, &e, &d);
    RSA_get0_factors(r, &p, &q);
    RSA_get0_crt_params(r, &dmp1, &dmq1, &iqmp);
    tmpl[0] = BN_bn2bin(n, tmp[0]);
    tmpl[1] = BN_bn2bin(e, tmp[1]);
    tmpl[2] = BN_bn2bin(d, tmp[2]);
    tmpl[3] = BN_bn2bin(p, tmp[3]);
    tmpl[4] = BN_bn2bin(q, tmp[4]);
    tmpl[5] = BN_bn2bin(dmp1, tmp[5]);
    tmpl[6] = BN_bn2bin(dmq1, tmp[6]);
    tmpl[7] = BN_bn2bin(iqmp, tmp[7]);
    unsigned char blo[8][6000];
    for(int i=0;i<8;i++)
        EVP_EncodeBlock(blo[i], tmp[i], tmpl[i]);
    sprintf(res, "<RSAKeyValue><Modulus>%s</Modulus><Exponent>%s</Exponent><D>%s</D><P>%s</P><Q>%s</Q><DP>%s</DP><DQ>%s</DQ><InverseQ>%s</InverseQ></RSAKeyValue>",
            blo[0], blo[1], blo[2], blo[3], blo[4], blo[5], blo[6], blo[7]);
    return 1;
}

/**
 * @brief xmlkeyToRSA
 * @param key
 * @param r 注意!!!调用函数一定要在外部RSA_free(r)!!!
 * @return
 * 注意!!!调用函数一定要在外部RSA_free(r)!!!
 */
int xmlkeyToRSA(const char *key, RSA **r)
{
    char s[8][15] = {"Modulus", "Exponent", "D", "P", "Q", "DP", "DQ", "InverseQ"};
    char res[6000];
    unsigned char resdec[8][6000];
    int resdecl[8];
    int i;
    for(i=0; i<8; i++){resdecl[i] = 0;}
    for(i=0; i<8; i++){
        if(parseXml(s[i], key, res) == 0)
            break;
        decodeBase64((unsigned char*)res, resdec[i], &resdecl[i]);
    }
    if(i!=2 && i!=8){return 0;}
    if(*r == NULL){
        *r = RSA_new();
    }
    BIGNUM *n=NULL, *e=NULL, *d=NULL, *p=NULL, *q=NULL, *dmp1=NULL, *dmq1=NULL, *iqmp=NULL;
    n = BN_new();
    BN_bin2bn(resdec[0], resdecl[0], n);
    e = BN_new();
    BN_bin2bn(resdec[1], resdecl[1], e);

    if(i == 2){
        RSA_set0_key(*r, n, e, d);
        return 2;
    }

    d = BN_new();
    BN_bin2bn(resdec[2], resdecl[2], d);
    p = BN_new();
    BN_bin2bn(resdec[3], resdecl[3], p);
    q = BN_new();
    BN_bin2bn(resdec[4], resdecl[4], q);
    dmp1 = BN_new();
    BN_bin2bn(resdec[5], resdecl[5], dmp1);
    dmq1 = BN_new();
    BN_bin2bn(resdec[6], resdecl[6], dmq1);
    iqmp = BN_new();
    BN_bin2bn(resdec[7], resdecl[7], iqmp);


    RSA_set0_key(*r, n, e, d);
    RSA_set0_factors(*r, p, q);
    RSA_set0_crt_params(*r, dmp1, dmq1, iqmp);//函数内部会把自身bn给free掉，然后直接指向现在开辟的空间，故此次不能free，这些函数连续调用两次必然出错……
    return 1;
}


/**
 * @brief parseXml
 * @param keyword 标签值无需带尖括号
 * @param str 待查串
 * @param res 建议大小6000,因为6144/8=768位的编成64不会超过6000
 * @return 取标签值中间的值返回
 */
int parseXml(const char* keyword, const char *str, char res[]){
    char st[19], et[19];
    sprintf(st, "<%s>", keyword);
    sprintf(et, "</%s>", keyword);
    char *ds = strstr(str, st);
    if(ds == NULL){return 0;}
    ds += strlen(st);
    char *de = strstr(str, et);
    if(de == NULL){return 0;}
    strncpy(res, ds, de - ds);
    res[de-ds] = '\0';//源码显示strncpy当n先走完时不会自动加\0,除非source先走完才会加\0
    return 1;
}

/**
 * @brief RSAPubCheck
 * @param r
 * @return 简单验证公钥正确返回1
 */
int RSAPubCheck(RSA *r)
{
    const BIGNUM *n=NULL, *e=NULL, *d=NULL;
    if(r == NULL) return 0;
    RSA_get0_key(r, &n, &e, &d);
    if(n == NULL || e == NULL) return 0;
    return 1;
}
