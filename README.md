# RSAHelperToolPureC

> *谨献给在兴业数金为期近四个月的实习时光*！

---


1. 签名和验签中涉及到的公私钥加解密算法所使用的填充方式为：RSA_PKCS1_PADDING。
2. 签名可以直接输入消息值（但一般都是用消息的摘要），实习时有过需要直接签名消息值的需求，故添加此功能，").arg("注意消息值的长度要小于密钥长度-11
3. 验签部分可以直接显示签名前的消息（若是消息值请对比ascii值，若为摘要则对比hex值）。由于提取了签名前的信息，所以可以选择是否与原消息值进行对比。
4. 对称加密算法列表是直接从Openssl文档中提取的，并不是都可以使用，常用算法均已测试可行。

---


> Bug：凡是在输入私钥的地方，若密钥不需要加密格式的请勿输入加密过的密钥，否则会有惊喜。
> 
> Author：本人业余程式爱好者，喜在闲时随便写些代码，由于即将正式工作所以本程序先告一段落。
