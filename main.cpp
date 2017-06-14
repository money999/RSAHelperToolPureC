//#include <openssl/pem.h>
//#include <openssl/aes.h>
//#include <openssl/md5.h>
//#include <openssl/x509.h>
//#include <openssl/objects.h>
//#include <openssl/rsa.h>
//#include <openssl/bn.h>
//#include <openssl/rsa.h>
//#include <openssl/objects.h>
//#include <openssl/x509.h>
//#include<string.h>
//#include "helper.h"
#include "dialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}

//    RSA  *r=NULL , *rp= NULL;
//    int  i,bits=512;
//    unsigned long  e=RSA_F4;
//    int len=0, flen, padding;
//    EVP_PKEY *k = NULL;
//    unsigned char reee[2000], reek[2000], rekk[2000];
//    char key[]= "-----BEGIN PRIVATE KEY-----\nMIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQDJgQfODtCNz/HP"
//                                             "ZlF58boMSS95cN7tmUL/zPkXiMl1/K8Tk2N/eJHrpEG38QVopNhlaiRxNN4WOlRf"
//                "                            5DKUSoCtH+B9WobodVcyUA7TQAEm5rZkPNo14/UTDVDsql4ugW8his38Mr4n4PfUW9+VFWHpTIIFbR0V+5NT2EQiEnCHxnBYgQlSa7JvphcsxKSRsXZ/+I4DoRudDfp71nrTm4gOeiuMUVzIOF+S/lCPBGKDXyyvJAOAoxuD8dB0yeohMkn50VnvGLMG6QmLAE50GE6BAB0P+EvGj14NgsE/thLzhnDRgmK9Cfn5KODUtfmsmXCbuXSsiVveUvsKlb4WPXYVAgMBAAECggEALz+RG/D/V/FFavM78ZMLo+vZNOmRbDb+rcpbMfiB/Kd2SenKb85OsOk/+6iJMyNMFmOQDfduh9m/hQiWD410pKOP2PTMI1+4RXTeNQyR+JQqelCGfhJomcIKkqPUF6WD8GKCsDsZuXIXynSMdYGhBrpI1oriQhBOWF+igja+qickEXvAUx+r5NMr+Q6YhEZoxx3k/77sG9gvodq/GYoX7KzODiH1eaMFIgThkwO7Oswwv7IyoZ+UIb2vVm+IWW8seMzxmLAqz5N8rUZPDWRTc/G1aSpOcCD+EDglH8uehwunNWZ9fbC8HdukDX83rrMpvTABzxw7ekf6BHh+s4iglQKBgQDn7Ho+4ui8XIdF/ceegGlwbQn9vbkQnKZeg/SXP/Lnf9VxlE8CLuLzbLmA30WYjtWS2gbcNr/Ffv3w9NGoJP90y12RLU2g8lpRObLN5d2xmwRmQIF/dg+4KRteLgFfrcLuSLcj8/cfWCJX/Je4MqIHM24fVYTKqJu3EHAPSx5BtwKBgQDebCEmC8HQzNFn4LKqKVrdQB3j245i4dBR/BL76TMoBBgtpoNEsvJ0aWeV5d2SHzHD4cJOW20xpbL3za++j/BuZThr2wCaxbSD5TxN94qUOyzRs0PT9CZzvq8qS8iegRVrGBmtkLZVLhC2+IyE6esClO2cBbzOijyIfQuxF4gWkwKBgQDMY18oZJhux6x/RjPRv6EsbyvK7pRVy3fi+69mS/kpg0L7oZQvfFqN5Fdm911CIT6e+H3rPGStDEmHPHo4EMMAjuiatK4hFPP7eTnWsqk5iD/MTTTSu50G01NHIIwdYejUTkj36lzyxp0dpYGf1x9r8SsvehJY91ajcl0PXUgA6QKBgQDT4Y/GbYbJgIOvgBbTEKg1gmG28S13twO7RfVTsngAE75wpmIALLPY/5wk6J+lFkBTCJoQCPpBREbz1yYm03nHwHb6D9tIlTP8PYCwCTMjOCfe7/WaUMfclPbKxPytOeyMY536gJOhG0vi8WzzJN6yS+r6KWEOJBO8NdrQbck/LwKBgQCLR47+q+jufc6omk6CVTywvLhqBbf5lf0kvwe8HAJ0O0X9RPpaQWd8YERFUQ45WKURbnQgnTHf1VsbzGWli0zyRU4PU5xjUgGLoG8cP5qD4nRfpDVw9ZJLFdfdT37SJAXEr8LE7A0OQLIJCNEsRZqCUhPJ1QDFmV7+0ZsnT+5smg==\n-----END PRIVATE KEY-----";

//    char keypub[]="-----BEGIN PUBLIC KEY-----\nMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAhg95T1QpdKD8OWjm5yZ2mIFV4Phe7czOzn9YtOufK1qMZ8fZEyjpoXBLq+4d+pHj6DCAX7pqZMqu8Jjr7u7yfx+CxEO0PtD4T9WPnZOcwhWLntLhzs666hjRob7iGb/T5H/if+leyVoRJir93WJLkqHl2jBW52hHsnjIl/4f5tfN/6XcaODU5Ia67TcZybXGXfYuP3VC+yYhV3CeXGtTsfIfKzgjIU/ugPrAhv26f2rDgsgAQNh0Hc91IGrbSyLy+pGcf+XYyU8/zNGRs8VSnmMR+xqmdvISDVKPGtxrvhwWOpKDyZjSKOnSxk6wM7/Oic51ggrfvlTVD41JoXMWAwIDAQAB\n-----END PUBLIC KEY-----";
//    char sign[]="FT8KEDsVvAErl4eOpcEgG5R6R+WjPrI3ieLNxrs1NGrOV88gCKCUIdO6KVFzDWv3w7PY/fv5K4lJ2/EClJPfqfSWG4MN1XdOAlMGOcOWJ2CXmksiZ6EC+2kHb4atDTnz5xC8uZTznFvxTJkh7cQbFOBNf+qSCO/0ZxoblGCYoF6u9nnxdA04JS29HrPkgG1+uCqLXNjhszDFEc6hXzfr9iIqyqGBPhxL+AGaEsNzEA9DL0x/dl0CDWKglStabmanlNPMFQ0SfXI43fYbTTr2yYBTpLkkIwAo2lakYbIoDelztv1H8TiamJ/PFg2AhqS2e3WN8z758mLhtQLEhGjrCQ==";
//    char ssss[] = "{\"flag\":2222,\"mapString\":{},\"date\":\"2017-06-09 14:28:25\",\"listDiyClass\":[],\"mapDiyClass\":{},\"listString\":[]}";

//    SHA1((unsigned char *)ssss, strlen(ssss), reee);
//    for(i=0;i<SHA_DIGEST_LENGTH;i++){
//        printf("%02x ", reee[i]);
//    }

//    char *trr = "<RSAKeyValue><Modulus>sadfewerwe</Modulus><Exponent>2</Exponent><D>3</D><P>4</P><Q>5</Q><DP>6</DP><DQ>7</DQ><InverseQ>8</InverseQ></RSAKeyValue>";
//    char *xmlkey = "<RSAKeyValue><Modulus>yYEHzg7Qjc/xz2ZRefG6DEkveXDe7ZlC/8z5F4jJdfyvE5Njf3iR66RBt/EFaKTYZWokcTTeFjpUX+QylEqArR/gfVqG6HVXMlAO00ABJua2ZDzaNeP1Ew1Q7KpeLoFvIYrN/DK+J+D31FvflRVh6UyCBW0dFfuTU9hEIhJwh8ZwWIEJUmuyb6YXLMSkkbF2f/iOA6EbnQ36e9Z605uIDnorjFFcyDhfkv5QjwRig18sryQDgKMbg/HQdMnqITJJ+dFZ7xizBukJiwBOdBhOgQAdD/hLxo9eDYLBP7YS84Zw0YJivQn5+Sjg1LX5rJlwm7l0rIlb3lL7CpW+Fj12FQ==</Modulus><P>5+x6PuLovFyHRf3HnoBpcG0J/b25EJymXoP0lz/y53/VcZRPAi7i82y5gN9FmI7VktoG3Da/xX798PTRqCT/dMtdkS1NoPJaUTmyzeXdsZsEZkCBf3YPuCkbXi4BX63C7ki3I/P3H1giV/yXuDKiBzNuH1WEyqibtxBwD0seQbc=</P><Q>3mwhJgvB0MzRZ+Cyqila3UAd49uOYuHQUfwS++kzKAQYLaaDRLLydGlnleXdkh8xw+HCTlttMaWy982vvo/wbmU4a9sAmsW0g+U8TfeKlDss0bND0/Qmc76vKkvInoEVaxgZrZC2VS4QtviMhOnrApTtnAW8zoo8iH0LsReIFpM=</Q><DP>zGNfKGSYbsesf0Yz0b+hLG8ryu6UVct34vuvZkv5KYNC+6GUL3xajeRXZvddQiE+nvh96zxkrQxJhzx6OBDDAI7omrSuIRTz+3k51rKpOYg/zE000rudBtNTRyCMHWHo1E5I9+pc8sadHaWBn9cfa/ErL3oSWPdWo3JdD11IAOk=</DP><DQ>0+GPxm2GyYCDr4AW0xCoNYJhtvEtd7cDu0X1U7J4ABO+cKZiACyz2P+cJOifpRZAUwiaEAj6QURG89cmJtN5x8B2+g/bSJUz/D2AsAkzIzgn3u/1mlDH3JT2ysT8rTnsjGOd+oCToRtL4vFs8yTeskvq+ilhDiQTvDXa0G3JPy8=</DQ>"
//            "<InverseQ>i0eO/qvo7n3OqJpOglU8sLy4agW3+ZX9JL8HvBwCdDtF/UT6WkFnfGBERVEOOVilEW50IJ0x39VbG8xlpYtM8kVOD1OcY1IBi6BvHD+ag+J0X6Q1cPWSSxXX3U9+0iQFxK/CxOwNDkCyCQjRLEWaglITydUAxZle/tGbJ0/ubJo=</InverseQ>"
//            "<D>Lz+RG/D/V/FFavM78ZMLo+vZNOmRbDb+rcpbMfiB/Kd2SenKb85OsOk/+6iJMyNMFmOQDfduh9m/hQiWD410pKOP2PTMI1+4RXTeNQyR+JQqelCGfhJomcIKkqPUF6WD8GKCsDsZuXIXynSMdYGhBrpI1oriQhBOWF+igja+qickEXvAUx+r5NMr+Q6YhEZoxx3k/77sG9gvodq/GYoX7KzODiH1eaMFIgThkwO7Oswwv7IyoZ+UIb2vVm+IWW8seMzxmLAqz5N8rUZPDWRTc/G1aSpOcCD+EDglH8uehwunNWZ9fbC8HdukDX83rrMpvTABzxw7ekf6BHh+s4iglQ==</D>"
//            "<Exponent>AQAB</Exponent>"
//        "</RSAKeyValue>";

//    char *xmlpubkey = "<RSAKeyValue><Modulus>yYEHzg7Qjc/xz2ZRefG6DEkveXDe7ZlC/8z5F4jJdfyvE5Njf3iR66RBt/EFaKTYZWokcTTeFjpUX+QylEqArR/gfVqG6HVXMlAO00ABJua2ZDzaNeP1Ew1Q7KpeLoFvIYrN/DK+J+D31FvflRVh6UyCBW0dFfuTU9hEIhJwh8ZwWIEJUmuyb6YXLMSkkbF2f/iOA6EbnQ36e9Z605uIDnorjFFcyDhfkv5QjwRig18sryQDgKMbg/HQdMnqITJJ+dFZ7xizBukJiwBOdBhOgQAdD/hLxo9eDYLBP7YS84Zw0YJivQn5+Sjg1LX5rJlwm7l0rIlb3lL7CpW+Fj12FQ==</Modulus>"
//            "<Exponent>AQAB</Exponent>"
//        "</RSAKeyValue>";

//    char tmmp[2000];
//    unsigned char baseout[20000];
//    int tmpl, outl;
//    char *ss;

//    for(i=0;i<2000;i++){
//        tmmp[i]= 97;
//    }

//    printf("%d\n", decodeBase64((unsigned char *)key, baseout, &tmpl));
//    printf("%d\n", tmpl);


//    printf("%d\n", xmlkeyToRSA(xmlkey, &r));
//    RSAGetPub(r, tmmp);
//    printf("%s\n", tmmp);

//    RSAGetPubPKCS1(r, tmmp);
//    printf("%s\n", tmmp);

//    BIGNUM *ret1,*ret2;
//    ret1=BN_new();
//    BN_bin2bn((unsigned char *)"242424ab",8, ret1);
//    ret2=BN_bin2bn((unsigned char *)"242424ab",8,NULL);
//    int kt = BN_bn2bin(ret1, baseout);
//    printf("%d\n", kt);
//    BN_free(ret1);
//    BN_free(ret2);

//    pubkeyToRSA(keypub, &r);
//    printf("%x", r->d);

//    xmlkeyToRSA(xmlkey, &r);
//    tmpl = RSA_check_key(r);
//    printf("%d\n", tmpl);


//    prikeyToRSA(key, &r);

//    RSAGetPubXml(r, tmmp);
//    printf("%s\n", tmmp);

//    RSAGetPriXml(r, tmmp);
//    printf("%s\n", tmmp);



    //pubkeyToRSA(keypub, &r);
    //r = RSA_generate_key(2048, RSA_F4,NULL,NULL);

    //RSA_print_fp(stdout,r,11);

//    RSAGetPub(r, (char*)reee);
//    printf("%s\n", reee);

//    RSAGetPKCS8(r, (char*)reee);
//    printf("%s\n", reee);

    //printf("%d\n", strlen(key));






//    puts("\n");
//    char *kkk = NULL;

//    outl = BN_bn2bin(r->n, baseout);
//    for(i=0;i<outl;i++){
//        printf("%02x:", baseout[i]);
//        if((i+1)%15==0)
//            puts("");
//    }
//    puts("");

//    kkk = BN_bn2hex(r->n);
//    printf("%s", kkk);

//    OPENSSL_free(kkk);
//    puts("");
//    reek[0]= 0;
//    for(i=0;i<outl+1;i++){
//        printf("%02x:", reek[i]);
//        if((i+1)%15==0)
//            puts("");
//    }
//    puts("");

//    EVP_EncodeBlock(reee, baseout, outl);
//    printf("%s\n", reee);

//    EVP_EncodeBlock(rekk, reek+1, outl);
//    printf("%s\n", rekk);



    //RSAGetPKCS1(r, (char*)tmmp);
//    unsigned char tmmp[] = "MIIEpQIBAAKCAQEAyYEHzg7Qjc/xz2ZRefG6DEkveXDe7ZlC/8z5F4jJdfyvE5Njf3iR66RBt/EFaKTYZWokcTTeFjpUX+QylEqArR/gfVqG6HVXMlAO00ABJua2ZDzaNeP1Ew1Q7KpeLoFvIYrN/DK+J+D31FvflRVh6UyCBW0dFfuTU9hEIhJwh8ZwWIEJUmuyb6YXLMSkkbF2f/iOA6EbnQ36e9Z605uIDnorjFFcyDhfkv5QjwRig18sryQDgKMbg/HQdMnqITJJ+dFZ7xizBukJiwBOdBhOgQAdD/hLxo9eDYLBP7YS84Zw0YJivQn5+Sjg1LX5rJlwm7l0rIlb3lL7CpW+Fj12FQIDAQABAoIBAC8/kRvw/1fxRWrzO/GTC6Pr2TTpkWw2/q3KWzH4gfyndknpym/OTrDpP/uoiTMjTBZjkA33bofZv4UIlg+NdKSjj9j0zCNfuEV03jUMkfiUKnpQhn4SaJnCCpKj1Belg/BigrA7GblyF8p0jHWBoQa6SNaK4kIQTlhfooI2vqonJBF7wFMfq+TTK/kOmIRGaMcd5P++7BvYL6HavxmKF+yszg4h9XmjBSIE4ZMDuzrMML+yMqGflCG9r1ZviFlvLHjM8ZiwKs+TfK1GTw1kU3PxtWkqTnAg/hA4JR/LnocLpzVmfX2wvB3bpA1/N66zKb0wAc8cO3pH+gR4frOIoJUCgYEA5+x6PuLovFyHRf3HnoBpcG0J/b25EJymXoP0lz/y53/VcZRPAi7i82y5gN9FmI7VktoG3Da/xX798PTRqCT/dMtdkS1NoPJaUTmyzeXdsZsEZkCBf3YPuCkbXi4BX63C7ki3I/P3H1giV/yXuDKiBzNuH1WEyqibtxBwD0seQbcCgYEA3mwhJgvB0MzRZ+Cyqila3UAd49uOYuHQUfwS++kzKAQYLaaDRLLydGlnleXdkh8xw+HCTlttMaWy982vvo/wbmU4a9sAmsW0g+U8TfeKlDss0bND0/Qmc76vKkvInoEVaxgZrZC2VS4QtviMhOnrApTtnAW8zoo8iH0LsReIFpMCgYEAzGNfKGSYbsesf0Yz0b+hLG8ryu6UVct34vuvZkv5KYNC+6GUL3xajeRXZvddQiE+nvh96zxkrQxJhzx6OBDDAI7omrSuIRTz+3k51rKpOYg/zE000rudBtNTRyCMHWHo1E5I9+pc8sadHaWBn9cfa/ErL3oSWPdWo3JdD11IAOkCgYEA0+GPxm2GyYCDr4AW0xCoNYJhtvEtd7cDu0X1U7J4ABO+cKZiACyz2P+cJOifpRZAUwiaEAj6QURG89cmJtN5x8B2+g/bSJUz/D2AsAkzIzgn3u/1mlDH3JT2ysT8rTnsjGOd+oCToRtL4vFs8yTeskvq+ilhDiQTvDXa0G3JPy8CgYEAi0eO/qvo7n3OqJpOglU8sLy4agW3+ZX9JL8HvBwCdDtF/UT6WkFnfGBERVEOOVilEW50IJ0x39VbG8xlpYtM8kVOD1OcY1IBi6BvHD+ag+J0X6Q1cPWSSxXX3U9+0iQFxK/CxOwNDkCyCQjRLEWaglITydUAxZle/tGbJ0/ubJo=";
//    printf("%s\n", tmmp);
//    decodeBase64(tmmp, baseout, &outl);
//    for(i=0;i<outl;i++){
//        printf("%02x ", baseout[i]);
//    }


//    pubkeyToRSA(keypub, &r);

//    RSA_print_fp(stdout,r,11);

//    RSAVerifyBase64(r, (unsigned char*)sign, baseout, &outl);
//        for(i=0;i<outl;i++){
//            printf("%02x",baseout[i]);
//        }
//        puts("");


//    prikeyToRSA(key, &r);
//    RSAGetPub(r, reee);

//    pubkeyToRSA(reee, &rp);

//    RSAGetPub(rp, reek);
//    printf("%s\n", reek);

//    unsigned char in[]="KY4u6JdBTc5nwjrawC6WxEM7&20170524140000&POST&/api/test/sayHello&flag=1";
//    unsigned char money[]="money";
//    unsigned char out[2000];
//    unsigned char baseout[2000];
//    unsigned char tmmp[2000];
//    char *ss;
//    unsigned char res[50] = {0};
//    int outl,tmpl;



//    RSASignBase64(r, NID_sha1, in, strlen((const char*)in), out);
//    printf("%s  %d\n", out, strlen((const char*)out));

//    decodeBase64(out, tmmp, &tmpl);

//    RSAVerifyRes(rp, tmmp, tmpl, baseout, &outl);

//    for(i=0;i<outl;i++){
//        printf("%02x",baseout[i]);
//    }
//    puts("");

//    len = RSA_verify(NID_sha1, baseout, outl, tmmp, tmpl, rp);
//    printf("%d\n", len);



//    char *from;
//    char *to;
//    char *res;

//        flen=RSA_size(r);
//        for(i=0;i<20;i++)
//            memset(&from[i],i%26+97,1);
//        from[10] = 0;
//        for(i=0;i<20;i++)
//            printf("%c", from[i]);
//        puts("");

//        printf("\nsdfaadf !\n");

//        len=RSA_public_encrypt(20,(unsigned char *)from,(unsigned char *)to,r,RSA_PKCS1_PADDING);

//        printf("%d\n",len);

//        len=RSA_private_decrypt(len, (unsigned char *)to, (unsigned char *)res, r, RSA_PKCS1_PADDING);

//        printf("%d\n",len);

//        for(i=0;i<len;i++){
//            printf("%c", res[i]);
//        }
//        puts("");
//        printf("%d %d\n", flen, len);

//    if(r!=NULL){
//        RSA_free(r);
//    }
//    if(from)
//        free(from);
//    if(to)
//        free(to);
//    if(res)
//        free(res);




//unsigned char in[]="money";
//unsigned char out[500];
//char *ss;
//unsigned char res[50] = {0};
//MD5(in, strlen((const char*)in), out);
//for(i=0;i<16;i++){
//    printf("%02x",out[i]);
//    res[i]=out[i];
//}
//puts("");
//printf("%s\n%d\n",res, strlen((const char*)res));

//r = RSA_generate_key(bits,e,NULL,NULL);

//printf("dfdd\n");
//len = RSA_sign(NID_md5, res, strlen((const char*)res), out, (unsigned int*)&flen, r);

//for(i=0;i<flen;i++){
//    printf("%x",out[i]);
//}
//puts("");


//X509_SIG *sig = NULL;
//unsigned char *s;
//s = (unsigned char *)OPENSSL_malloc((unsigned int)flen);

//len = RSA_public_decrypt(flen, out, s, r, RSA_PKCS1_PADDING);

//sig = d2i_X509_SIG(NULL, (const unsigned char**)&s, (long)len);
//unsigned char *sss = sig->digest->data;
//printf("%s\n",sss);
//for(i=0;i<strlen((const char*)sss);i++){
//    printf("%02x",sss[i]);
//}
//puts("");

//len = RSA_verify(NID_md5, res, strlen((const char*)res), out, flen, r);
//printf("%d\n", len);
//_________________________________________________________________________

//BIO  *out,*in,*out8, *outp, *outp2, *outpp;
//RSA  *r;
//int  i,bits=1024;
//unsigned long  e=RSA_3;
//char *str=NULL, *str8=NULL, *strp=NULL, *strp2=NULL;
//int len=0;
//EVP_PKEY *k;

//k = EVP_PKEY_new();
//out=BIO_new(BIO_s_mem());
//out8=BIO_new(BIO_s_mem());
//outp=BIO_new(BIO_s_mem());
//outp2=BIO_new(BIO_s_mem());
//outpp=BIO_new(BIO_s_mem());

//r = RSA_generate_key(bits, e, NULL, NULL);


//PEM_write_bio_RSAPublicKey(outp,r);
//PEM_write_bio_RSA_PUBKEY(outp2,r);

//PEM_write_bio_RSAPrivateKey(out,r,NULL,NULL,0,NULL,NULL);

//EVP_PKEY_set1_RSA(k, r);
//PEM_write_bio_PKCS8PrivateKey(out8,k,NULL,NULL,NULL,NULL,NULL);

//PEM_write_bio_PUBKEY(outpp, k);



//len=BIO_ctrl_pending(out);
//str=(char *)malloc(len);
//len=BIO_read(out,str,len);
//printf("%s\n",str);

//len=BIO_ctrl_pending(out8);
//str8=(char *)malloc(len);
//len=BIO_read(out8,str8,len);
//printf("%s\n",str8);

//len=BIO_ctrl_pending(outp);
//strp=(char *)malloc(len);
//len=BIO_read(outp,strp,len);
//printf("%s\n",strp);

//len=BIO_ctrl_pending(outp2);
//strp2=(char *)malloc(len);
//len=BIO_read(outp2,strp2,len);
//printf("%s\n",strp2);

//len=BIO_ctrl_pending(outpp);
//strp2=(char *)malloc(len);
//len=BIO_read(outpp,strp2,len);
//printf("%s\n",strp2);

//free(str);
//BIO_free(out);
//free(str8);
//BIO_free(out8);
//free(strp);
//BIO_free(outp);
//free(strp2);
//BIO_free(outp2);
//RSA_free(r);

//----------------------base64
//unsigned char in[]="money";
//unsigned char out[2000];
//char *ss;
//unsigned char res[50] = {0};
//int outl;

//outl = EVP_EncodeBlock(out, in, strlen((const char*)in));
//printf("%s     %d\n",out, outl);
