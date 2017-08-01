//#include <openssl/aes.h>
//#include <openssl/md5.h>
//#include <openssl/x509.h>
//#include <openssl/objects.h>
//#include <openssl/rsa.h>
//#include <openssl/objects.h>
#include<string.h>
#include "helper.h"
#include "dialog.h"
#include "algdialog.h"
#include <QApplication>
#include <QTranslator>
#include <openssl/evp.h>




//RSA *PEM_read_bio_RSAPrivateKey(BIO *bp, RSA **rsa, pem_password_cb *cb,
//                                void *u)
//{
//    EVP_PKEY *pktmp = NULL;
//    pktmp = PEM_read_bio_PrivateKey(bp, NULL, cb, u);
//    printf("qqqq   %d\n\n\n",pktmp);
//    return pkey_get_rsa(pktmp, rsa);
//}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;//如果在dialog.h添加一些成员变量会导致程序无法运行，原因未知，但是把这三行注释掉就可以运行。注释掉后再添加变量又不能运行，再把这三行去注释就可以运行……
    translator.load(":/trans/language_zh");
    a.installTranslator(&translator);
    MyDialog w;
    w.show();
    return a.exec();



//    RSA *r = NULL;
//    r = RSA_new();
//    BIGNUM *e = BN_new();
//    BN_dec2bn(&e, "65537");
//    printf("%d\n", RSA_generate_key_ex(r, 2100, e, NULL));
//    char res[9000];
//    RSAGetPKCS1(r, res, NULL, NULL);
//    printf("%s\n",res);

//    OpenSSL_add_all_algorithms();
//    OpenSSL_add_all_ciphers();
//    OpenSSL_add_all_digests();
//    char keyxmlp[]="<RSAKeyValue><Modulus>vUy1X46LBDkyAWxNlBmbVdT1HAJ0lh+6Qku3UyqLjShIP4c+wue65fyEYGvcho+Ij7C8s9IvBKG1lQsy3Kofqbm6Odlc3mgG2eQohIFS7q+jwmudHOKu0+RhwmMQxnKOtXtHZKB1zYQTcObqf+KWmKu/NUjtJl74aXT5BcLT48ao84KHwSn95G9M+rz4lcNydEIgk8oMUz50h1wTeGmB+T0b8X3W/KhQCNx1yKO6Y7MsHn58+5v/DT9AlsE1sVjPjDx0T+bpmgbvLhiPHehPSPWCFcIp9B93qsP+nWcCPzEO7S9D0incvnlIHJs04/HAjcaAJAq+sMbXh44Xo/bhqw==</Modulus><Exponent>AQAB</Exponent><D>j9mc8pKVnY4BLAerJGIZIq6D3NcY1YQivIJhO3fXOFtmG7CgxuflpSOxTLxqhm7Ibbj2jQep5zEjlbE+42T8TrPuiktdQT14B1hUWe0UooEiRnoUmIDCLg8dIuS5OLSRMeQOqq8tFhHJ3D/971S28CmDUfCrFj+RMkJLgk89SZa8jgd7QEYzTdhzOPQ0gBS9KmzZqiXwOyRr+aaQO2E4Ponbcst9Drwx+vH4UAA5+05qeykmJWYiWPnh+UMQb/wuN2E/POVYV3QDMs99rpIz4bO8rbVw+asZ7KHnUFybdCqYqXgUpBPS8p9p78WUv5O/1Pwa+czpT3MxAcrSzpSeQQ==</D><P>50GdUl86hfaa4MdHMTFzrMJ6sdko1LUunNRmBi2y3jgv+IKdiCGx1aspMecgFqTYDpRBGpCq5tZSR71t5gSq+HamzxiRf6jC1BlldI+PEVv1q1vxLB/qfAaHClIXp9nZvQ6mU7ELs8YHfnWy5vBxRBIZZM57EhHpO/211tlQOJE=</P><Q>0Y3Z2h83Z5+izW3D0pNms70ECXA1sHjPvzMjZpckn+kNlJ7SFI1gzCSpwmKd2wRcnMF1mlouylpfVG8USB+C7W0zFL2WIoSrR5eUbxAsjKAHlqYmFNoeM/iPttrz1c0yU1bOHckCfUfCIOs5qdLuF4sWWcJaMDY52qLrlokqdHs=</Q><DP>Yp1lZBn9z+CwfQgdwMmQxWwNfEfZlJNKtFASzbGxI/gb5MJ2QPX1auNZZtFjqqRTCiyIcracWmGsprEN61e0PM4EJi4Y5bJmmqHV1NXfMYzgf1lux904VflGns0RD1/j7S4RGYFXNytMSM4SI08HTfrV31n5u2Pt7MotP9hd0DE=</DP><DQ>ZW5N5qB5hvTkLp9Uy9aBPbrd+1uPAU5Y8GlmV0ANgEGkSy3c7gnIsseETAzD78Faup2BuSaxw0yfHBVwMcDe9OGIeh+STj79UPfz5xZjGeZUBf2CLVGukOVdWtr8b56VH3XC6vPi+pUDSD/Td3obuNWgCe5jDTcSJdv6QLFAFYU=</DQ><InverseQ>Ze0NWFosukIC8PFqXh0REODutp5YFdg+sLw9s9e6el5mL/+pzLkqlNSp5LOLydaoZGTXq03R7NZEinFymYnu7UaeSxvy/YqTqYf4v9YP7H2ppXOTpuSaRm+HNipL/Q2UgdWanoZNUOZlXtwcgOKc31n0FF4twc8bUPCqoTqpP/g=</InverseQ></RSAKeyValue>";
//    char keyxml[] = "<RSAKeyValue><Modulus>ykLM2kO3l7y6184IKhVpSdSWMEbvDZeX2tuXuGPhZ9D4ZXzIYE6A4wH5neWsaXlf/tcRUb11oo7cGstNq71cFCMZk4xS6iiBIf0It185HU6/nAxTkA7c22b4ocvdf8wBOOPUGu4JSGocO4OYnxna8s10Okeow4bJ7gq1YkMX8WpnOxFyTn7RPtSmHlpU0DR7r+msuuqGAzQoUPn6ECSG/MRdp8TFf4gv/JDrNnXezXiQaOI/y5josFYvMi4frYakYS9RtUstZ0w3GqMY5PYHkiTWCcBZjF4oKY00ypTuCqyt1sv9yBhCEJBqhHjoT/hdOioaYchH2104PZnXSHw0hw==</Modulus><Exponent>AQAB</Exponent>";
//    char key[]= "-----BEGIN PRIVATE KEY-----\nMIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQDJgQfODtCNz/HP"
//                "ZlF58boMSS95cN7tmUL/zPkXiMl1/K8Tk2N/eJHrpEG38QVopNhlaiRxNN4WOlRf"
//                "                            5DKUSoCtH+B9WobodVcyUA7TQAEm5rZkPNo14/UTDVDsql4ugW8his38Mr4n4PfUW9+VFWHpTIIFbR0V+5NT2EQiEnCHxnBYgQlSa7JvphcsxKSRsXZ/+I4DoRudDfp71nrTm4gOeiuMUVzIOF+S/lCPBGKDXyyvJAOAoxuD8dB0yeohMkn50VnvGLMG6QmLAE50GE6BAB0P+EvGj14NgsE/thLzhnDRgmK9Cfn5KODUtfmsmXCbuXSsiVveUvsKlb4WPXYVAgMBAAECggEALz+RG/D/V/FFavM78ZMLo+vZNOmRbDb+rcpbMfiB/Kd2SenKb85OsOk/+6iJMyNMFmOQDfduh9m/hQiWD410pKOP2PTMI1+4RXTeNQyR+JQqelCGfhJomcIKkqPUF6WD8GKCsDsZuXIXynSMdYGhBrpI1oriQhBOWF+igja+qickEXvAUx+r5NMr+Q6YhEZoxx3k/77sG9gvodq/GYoX7KzODiH1eaMFIgThkwO7Oswwv7IyoZ+UIb2vVm+IWW8seMzxmLAqz5N8rUZPDWRTc/G1aSpOcCD+EDglH8uehwunNWZ9fbC8HdukDX83rrMpvTABzxw7ekf6BHh+s4iglQKBgQDn7Ho+4ui8XIdF/ceegGlwbQn9vbkQnKZeg/SXP/Lnf9VxlE8CLuLzbLmA30WYjtWS2gbcNr/Ffv3w9NGoJP90y12RLU2g8lpRObLN5d2xmwRmQIF/dg+4KRteLgFfrcLuSLcj8/cfWCJX/Je4MqIHM24fVYTKqJu3EHAPSx5BtwKBgQDebCEmC8HQzNFn4LKqKVrdQB3j245i4dBR/BL76TMoBBgtpoNEsvJ0aWeV5d2SHzHD4cJOW20xpbL3za++j/BuZThr2wCaxbSD5TxN94qUOyzRs0PT9CZzvq8qS8iegRVrGBmtkLZVLhC2+IyE6esClO2cBbzOijyIfQuxF4gWkwKBgQDMY18oZJhux6x/RjPRv6EsbyvK7pRVy3fi+69mS/kpg0L7oZQvfFqN5Fdm911CIT6e+H3rPGStDEmHPHo4EMMAjuiatK4hFPP7eTnWsqk5iD/MTTTSu50G01NHIIwdYejUTkj36lzyxp0dpYGf1x9r8SsvehJY91ajcl0PXUgA6QKBgQDT4Y/GbYbJgIOvgBbTEKg1gmG28S13twO7RfVTsngAE75wpmIALLPY/5wk6J+lFkBTCJoQCPpBREbz1yYm03nHwHb6D9tIlTP8PYCwCTMjOCfe7/WaUMfclPbKxPytOeyMY536gJOhG0vi8WzzJN6yS+r6KWEOJBO8NdrQbck/LwKBgQCLR47+q+jufc6omk6CVTywvLhqBbf5lf0kvwe8HAJ0O0X9RPpaQWd8YERFUQ45WKURbnQgnTHf1VsbzGWli0zyRU4PU5xjUgGLoG8cP5qD4nRfpDVw9ZJLFdfdT37SJAXEr8LE7A0OQLIJCNEsRZqCUhPJ1QDFmV7+0ZsnT+5smg==\n-----END PRIVATE KEY-----";
//    char pubkey[] = "-----BEGIN PUBLIC KEY-----\nMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAyYEHzg7Qjc/xz2ZRefG6DEkveXDe7ZlC/8z5F4jJdfyvE5Njf3iR66RBt/EFaKTYZWokcTTeFjpUX+QylEqArR/gfVqG6HVXMlAO00ABJua2ZDzaNeP1Ew1Q7KpeLoFvIYrN/DK+J+D31FvflRVh6UyCBW0dFfuTU9hEIhJwh8ZwWIEJUmuyb6YXLMSkkbF2f/iOA6EbnQ36e9Z605uIDnorjFFcyDhfkv5QjwRig18sryQDgKMbg/HQdMnqITJJ+dFZ7xizBukJiwBOdBhOgQAdD/hLxo9eDYLBP7YS84Zw0YJivQn5+Sjg1LX5rJlwm7l0rIlb3lL7CpW+Fj12FQIDAQAB\n-----END PUBLIC KEY-----";
//    RSA *r = NULL, *red = NULL;
//    char res[5000];
//    int flag;
//    //prikeyToRSA(key, &r, NULL);
//    flag = xmlkeyToRSA(keyxmlp, &r);
//    printf("%d\n", flag);
//    flag = RSAGetPriXml(r, res);
//    printf("%d\n", flag);



//    const EVP_CIPHER *tl = EVP_des_ofb();
//    int len;
//    BIO *out=BIO_new(BIO_s_mem());
//    flag = PEM_write_bio_RSAPrivateKey(out,r,tl,NULL,0,NULL,(void*)"money");
//    printf("%d\n",flag);
//    len=BIO_ctrl_pending(out);
//    BIO_read(out,res,len);
//    res[len] = '\0';
//    BIO_free(out);
//    printf("%s\n",res);

//    out=BIO_new(BIO_s_mem());
//    EVP_PKEY *k = EVP_PKEY_new();
//    EVP_PKEY_set1_RSA(k, r);
//    flag = PEM_write_bio_PKCS8PrivateKey(out,k,tl,"money",5,NULL, NULL);
//    printf("%d\n",flag);
//    len=BIO_ctrl_pending(out);
//    len = BIO_read(out,res,len);
//    res[len] = '\0';
//    EVP_PKEY_free(k);
//    BIO_free(out);
//    printf("%s\n",res);

//    flag = RSAGetPKCS1(r, res, tl, (void*)"money");
//    printf("%d\n%s\n", flag, res);

//    flag = RSAGetPKCS8(r, res, tl, (void*)"money");
//    printf("%d\n%s\n", flag, res);

//    flag = prikeyToRSA(res, &red, (void*)"money");

//    flag = RSAGetPKCS1(red, res, NULL, NULL);
//    printf("%d\n%s\n", flag, res);
//    flag = RSAGetPKCS8(red, res, NULL, NULL);
//    printf("%d\n%s\n", flag, res);

//    flag = RSAGetPKCS8(r, res, EVP_des_ede3_cbc(), (void*)"money");
//    printf("%d\n%s\n", flag ,res);

//    char *kkk[] = {"AES-128-CBC", "AES-128-ECB", "AES-128-CFB", "AES-128-OFB","AES-192-CBC", "AES-192-ECB", "AES-192-CFB", "AES-192-OFB","AES-256-CBC", "AES-256-ECB", "AES-256-CFB", "AES-256-OFB","DES-CBC", "DES-ECB", "DES-CFB", "DES-OFB","DES-EDE-CBC", "DES-EDE", "DES-EDE-OFB", "DES-EDE-CFB","DES-EDE3-CBC", "DES-EDE3", "DES-EDE3-OFB", "DES-EDE3-CFB","DESX-CBC","RC4","RC4-40","IDEA-CBC", "IDEA-ECB", "IDEA-CFB", "IDEA-OFB","RC2-CBC", "RC2-ECB", "RC2-CFB", "RC2-OFB","RC2-40-CBC", "RC2-64-CBC","BF-CBC", "BF-ECB", "BF-CFB", "BF-OFB","CAST5-CBC", "CAST5-ECB", "CAST5-CFB", "CAST5-OFB","id-aes128-GCM", "id-aes192-GCM", "id-aes256-GCM","AES-128-OCB", "AES-192-OCB", "AES-256-OCB","id-aes128-CCM", "id-aes192-CCM", "id-aes256-CCM","ChaCha20","ChaCha20-Poly1305","RC5-32-12-16-CBC", "RC5-32-12-16-ECB", "RC5-32-12-16-CFB", "RC5-32-12-16-OFB"};

//    int nidd = EVP_CIPHER_nid(EVP_aes_128_cbc());
//    printf("%d\n", nidd);
//    printf("%s\n",OBJ_nid2sn(nidd));



//    for(int i=0;i<60;i++)
//    {
//        const EVP_CIPHER *tt = EVP_get_cipherbyname(kkk[i]);
//        if(tt!=NULL)
//            printf("%d\n", EVP_CIPHER_nid(tt));
//        else{
//            printf("%s\n", kkk[i]);
//        }
//    }

    return 1;
}



////puts("d");
//int dd = prikeyToRSA(key, &r, NULL);
////printf("%d\n", dd);
////unsigned char ttt[]="rkYJN7bhaRtKN4GHW2n+YYXJn5oIypTv1FAAAVVS2f5s0PsbdowbB+z7ZNcd5Lv4zJuK/Dh9ZGeol26T0fcbmjh6M1r2SV4M9sjNXnZ36Ck5Wpg8Vzea2WyjoYMDYhYTVXHZy6GoPMlVdkMO6EkTyTIRMjwvhUkO+BkdsNku6NAtVH5x2V4ZgkA19N2rFlZnY/uHXHS+7QSmr8vzAwpWo/WYdd9xu0mU6kk3BLc9laVpNBALJ3qv1AiFE/gyCgOHt3/NW2N9kP8szglewxLrBib5MVKW2ro9eEMVo92OIFTF5gqONwA57HX84FVYd3osBI7DP7/VGKPhwk4g0QF4JA==";

//// r = RSA_generate_key(512, RSA_3, NULL, NULL);

//OpenSSL_add_all_algorithms();
//char res[5000];
//int len;
//BIO *out=BIO_new(BIO_s_mem());
////PEM_write_bio_RSAPrivateKey(out,r,EVP_des_ede3_cbc, (unsigned char*)"hello", 5, NULL, NULL);
//EVP_PKEY *evpk = EVP_PKEY_new();
//int flag = EVP_PKEY_set1_RSA(evpk, r);
//printf("%d\n",flag);
//flag = PEM_write_bio_PKCS8PrivateKey(out, evpk, EVP_des_ede3_cbc(), NULL, 0, 0, (char*)"hello");
//printf("%d\n",flag);
//len=BIO_ctrl_pending(out);
//BIO_read(out,res,len);
//res[len] = '\0';
//BIO_free(out);
//EVP_PKEY_free(evpk);


//printf("%s", res);
//if(r){RSA_free(r); r=NULL;}

////char res[]="-----BEGIN RSA PRIVATE KEY-----\nProc-Type: 4,ENCRYPTED\nDEK-Info: DES-EDE3-CBC,14CADC30D1240753\n\nM0VFabcTwQKvmNvzAulRfd1TrtPURl8hGCU7ILxudJw//HNVz2OwIH2JourLffm1yD+/zoTPRUD/WlmGyxla4T3ZSyZ7jGFR+9lTENu0f+4tjqpSguNltmOlsiZ/U+cposnb++D0uGswB03M5sffiDWkqc7YHuye9+twikjQzhLczLzm8olGDYmatgeNzZtoK2ChHikm0Vvc13aGaMoQoFDbsOV8LjVF19UQXBHR0mGiu3V9ZpVwXXZ3In02VBKJid5iURoDh9aWlaiLs6zsZHvVR+5q0dUq8IU3m2n4vvVp/vkhnFgPCH8MGhzRERn7X5uWkCfZMxSe0OLrxmXtlZM3as+XbKjyI1+7m2R8WLRP42OIgNuOAJJvDE8lmEwbx8OicBGY1m7gHh42t91py1vE0Ctr+Ytui4z2gcUCF7f3p2SmQiaRKhNlWyK8Um3r+P7IIxcBE8P7vCbu5/7KQQompFrcMvX09v2rx6qTD4OLOEKgOfHyNXz0n7sli1zWq7zKAYAkyvv8ZrzFlJpEAvQT36hS3qHbOVsbW7gWLeu5wFQ74vF/73qyaSXnQQiV1AY/Fqfd5HeRziwyVwJYWinbcQ4vR036dVndiKClq5DU0UtlE9xCPbHjR425aL8H2gPqTERz2eAfQWHsHTCNxP0CyuG0JFA8/qUnI9my8mbAw8Qz7Q5xzvLt9unp8tNwzIivTKBqmPp05hdQwd0SZGQFIkzGkpNDvqGWOmob/03sRUXzlkhm202K8erFLeoZMqi1OpPgHcEgwmLFqFtog1aIRHwrqoveZn4dZbVvv68bYJCXChT9FRKdEAXTsa/+ByYZQEwc9tWfeA4UonIyyys9/AiXDkicOp5dcnAyZOHvocKcb/JNbIsh9Rk8il/8AvGOhqn7V78SuagwoRGGfBuAA0ivzMujNCYBPHMKnlgVdE5W6acx6uPjY2sjdpnrKBlpqZOOw8mKghcNrX55DXgQq10vtYhm7A1Y5I9WErkLQk3NajsmAoKaSZ1aAF7xGLl2Wc9SHRokxmnsFU/M6MsGUaj1epFc5Ug3w4Q4t70TKYSS8suf3ZhVWFXwBB/y4KyxofF9ByPqJkZpqahFm78vTeCHpAHQ3ZtiWi3TRMfAx82/6Ebl4drsSFXrx5JrheYsSBPUVBeyos7ngi3paokmLavksmCbCxoTWfXDNti4TJLJ89l4qzWJRn5P+C6hoaUyh7FLzmgqGxJi+F0Dhu+dIGZQtZeMb4xfwrRMyF2KJ1Rm9mmCSiTHyjKFbWL/LEYWv0hPDBZmImCfHC5xff33vP4R6X9CLCFozxIwC7pe+4E3sF9AxpNsuP5bZMLCgCom844s9Xt9G3HlngXw1ufB/EhReRRxgTPcfYUiU1bxh3U1VnSpL1qdvqNVZGqVgYw4sFdmjPMkPWwHTOCffpvPcv3pOFQOC9ez0oqE6uB0N62T5qKOU21hFGYc8BOPexBustBX/B6IUs1Q9W2j7kplqrrY4VymsVlu7RD0YDGl9ZDLEZq6lm9XW9/k0DBx0JCYfh9/Bwp7JiP1b1L75MHCUZVULgm90Ip98xbSGajVd3FRqzT7ln1Qjn7LtVQS\n-----END RSA PRIVATE KEY-----";

//char kkk[5000];
//BIO *keybio = BIO_new_mem_buf(res, -1);
//printf("%d\n\n\n", keybio);
//RSA *rr = PEM_read_bio_RSAPrivateKey(keybio, NULL, NULL, (void *)"hello");
//if(rr==NULL){printf("asdlkf");}


//RSAGetPKCS8(rr, kkk, NULL, NULL);
//printf("%s", kkk);

//BIO_free(keybio);
//if(rr){RSA_free(rr); rr=NULL;}
//-----------------------------------------------------------------------------------------------------------------
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
