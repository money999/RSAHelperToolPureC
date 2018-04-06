<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>AlgDialog</name>
    <message>
        <location filename="../algdialog.cpp" line="15"/>
        <source>chooseCryptoAlgorithm</source>
        <translation>请选择加密算法</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="16"/>
        <source>sure</source>
        <translation>确定</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="17"/>
        <source>cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="18"/>
        <source>oldAlg</source>
        <translation>注意：由于某些算法已被淘汰或不安全等故在使用过程中可能会出错，例如使用某些算法只能显示旧的加密格式，而无法显示新标准加密格式！</translation>
    </message>
</context>
<context>
    <name>MyDialog</name>
    <message>
        <location filename="../dialog.cpp" line="59"/>
        <location filename="../dialog.cpp" line="72"/>
        <location filename="../dialog.cpp" line="86"/>
        <location filename="../dialog.cpp" line="95"/>
        <location filename="../dialog.cpp" line="128"/>
        <source>exec</source>
        <translation>执行</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="64"/>
        <location filename="../dialog.cpp" line="767"/>
        <location filename="../dialog.cpp" line="770"/>
        <location filename="../dialog.cpp" line="773"/>
        <source>teT1InputText</source>
        <translation>请在此输入公钥或私钥,支持以下格式（输入值均为base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="64"/>
        <location filename="../dialog.cpp" line="767"/>
        <location filename="../dialog.cpp" line="798"/>
        <source>acceptPrikeyFormat</source>
        <translation>-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----

-----BEGIN PRIVATE KEY-----
-----END PRIVATE KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="74"/>
        <source>msgText</source>
        <translation>请输入消息值或消息摘要（若为消息值注意长度小于密钥长度-11）
注意：若输入为摘要值也必须选择对应的算法，因为摘要算法将被写入签名中</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="75"/>
        <source>prikeyText</source>
        <translation>请输入私钥,使用pkcs8或pkcs1格式，若为其他格式请使用格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="80"/>
        <source>signText</source>
        <translation>请输入签名值（Base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="81"/>
        <source>pubkeyText</source>
        <translation>请输入公钥,使用SubjectPublicKeyInfo结构，若为其他格式请使用格式转换，支持格式如下：
-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="82"/>
        <source>verifyMsg</source>
        <translation>请输入待验证消息值</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="88"/>
        <source>showMsg</source>
        <translation>验证消息值</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="93"/>
        <location filename="../dialog.cpp" line="795"/>
        <source>encodePrikeyFormat</source>
        <translation> -----BEGIN RSA PRIVATE KEY-----
 Proc-Type: 4,ENCRYPTED
 DEK-Info:..., ...

 ...base64 encoded data...
 -----END RSA PRIVATE KEY-----


-----BEGIN ENCRYPTED PRIVATE KEY-----
-----END ENCRYPTED PRIVATE KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="93"/>
        <location filename="../dialog.cpp" line="795"/>
        <location filename="../dialog.cpp" line="798"/>
        <source>teT4InputText</source>
        <translation>请在此输入私钥,支持以下格式（输入值均为base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="98"/>
        <location filename="../dialog.cpp" line="121"/>
        <source>inputPassText</source>
        <translation>请输入密码</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="103"/>
        <location filename="../dialog.cpp" line="130"/>
        <source>chooseAlg</source>
        <translation>变更加密算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="104"/>
        <source>cryptoAlg</source>
        <translation>加密算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="120"/>
        <source>teT5PriHint</source>
        <translation>若密码值为空则生成未加密的私钥

若模数位数过大需要一定时间等待</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="154"/>
        <source>privateKey</source>
        <translation>私钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="159"/>
        <source>publicKey</source>
        <translation>公钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="163"/>
        <source>xmlFromat</source>
        <translation>xml格式</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="168"/>
        <source>chooseInputType</source>
        <translation>选择输入类型</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="189"/>
        <source>transFormat</source>
        <translation>格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="198"/>
        <location filename="../dialog.cpp" line="239"/>
        <source>noHash</source>
        <translation>未hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="203"/>
        <location filename="../dialog.cpp" line="244"/>
        <source>Hash</source>
        <translation>已hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="633"/>
        <source>sourMsgAscii</source>
        <translation>原消息值(ascii)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="635"/>
        <source>sourMsgHex</source>
        <translation>原消息值(hex)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="91"/>
        <location filename="../dialog.cpp" line="207"/>
        <source>msgIsHash</source>
        <translation>消息值是否已是摘要</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="125"/>
        <source>setBySelf</source>
        <translation>自定义(16-6939)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="228"/>
        <source>sign</source>
        <translation>签名</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="269"/>
        <source>verify</source>
        <translation>验签</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="279"/>
        <source>decodeprikey</source>
        <translation>私钥去密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="284"/>
        <source>encodeprikey</source>
        <translation>私钥加密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="288"/>
        <source>chooseProgram</source>
        <translation>选择操作</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="297"/>
        <location filename="../dialog.cpp" line="328"/>
        <source>inputPass</source>
        <translation>输入密码</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="319"/>
        <source>prikeyEnOrDecode</source>
        <translation>私钥加密或去密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="334"/>
        <source>cryptoOption</source>
        <translation>加密操作</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="346"/>
        <source>modulus bits</source>
        <translation>模数(n)位数</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="358"/>
        <source>public exponent</source>
        <translation>公钥指数</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="387"/>
        <source>generateRSA</source>
        <translation>生成RSA公私钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="397"/>
        <source>copyRight</source>
        <translation>Copyright@2017, money999</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="404"/>
        <source>copyRightReserve</source>
        <translation>All rights reserved.</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="474"/>
        <source>about</source>
        <translation>关于</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="517"/>
        <location filename="../dialog.cpp" line="557"/>
        <location filename="../dialog.cpp" line="719"/>
        <source>priKeyInputErr</source>
        <translation>私钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="525"/>
        <location filename="../dialog.cpp" line="623"/>
        <source>pubKeyInputErr</source>
        <translation>公钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="537"/>
        <source>xmlKeyInputErr</source>
        <translation>公（私）钥格式输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="552"/>
        <location filename="../dialog.cpp" line="614"/>
        <location filename="../dialog.cpp" line="618"/>
        <location filename="../dialog.cpp" line="706"/>
        <location filename="../dialog.cpp" line="722"/>
        <source>contentNull</source>
        <translation>输入内容不完整</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="594"/>
        <source>signBase64</source>
        <translation>签名后Base64编码显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="596"/>
        <source>signHex</source>
        <translation>签名后16进制显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="600"/>
        <source>signErr</source>
        <translation>签名出错</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="637"/>
        <source>signAlgorithm</source>
        <translation>签名算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="672"/>
        <source>inputMsgHex</source>
        <translation>输入消息值(hex)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="678"/>
        <source>inputMsgAscii</source>
        <translation>输入消息值(ascii)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="685"/>
        <source>inputMsgEqualsourMsg</source>
        <translation>输入消息值与原消息值相同，验签成功</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="687"/>
        <source>inputMsgUnequalsourMsg</source>
        <translation>输入消息值与原消息值不同，验签失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="692"/>
        <source>verifyErr</source>
        <translation>验签失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="711"/>
        <source>passErrOrKeyErr</source>
        <translation>密码或私钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="742"/>
        <source>bitsOutLimit</source>
        <translation>模数位数不符合要求</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="770"/>
        <source>acceptPubkeyFormat</source>
        <translation>-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----

-----BEGIN RSA PUBLIC KEY-----
-----END RSA PUBLIC KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="773"/>
        <source>acceptXmlkeyFormat</source>
        <translation>&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
	&lt;D&gt;&lt;/D&gt;
	&lt;P&gt;&lt;/P&gt;
	&lt;Q&gt;&lt;/Q&gt;
	&lt;DP&gt;&lt;/DP&gt;
	&lt;DQ&gt;&lt;/DQ&gt;
	&lt;InverseQ&gt;&lt;/InverseQ&gt;
&lt;/RSAKeyValue&gt;

&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
&lt;/RSAKeyValue&gt;</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="895"/>
        <source>showCryPKCS8PemErr</source>
        <translation>显示加密PKCS8格式失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="903"/>
        <source>showCryPKCS1PemErr</source>
        <translation>显示加密旧格式失败</translation>
    </message>
</context>
</TS>
