<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>AlgDialog</name>
    <message>
        <location filename="../algdialog.cpp" line="16"/>
        <source>chooseCryptoAlgorithm</source>
        <translation>请选择加密算法</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="17"/>
        <source>sure</source>
        <translation>确定</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="18"/>
        <source>cancel</source>
        <translation>取消</translation>
    </message>
    <message>
        <location filename="../algdialog.cpp" line="19"/>
        <source>oldAlg</source>
        <translation>注意：由于某些算法已被淘汰或不安全等故在使用过程中可能会出错，例如使用某些算法只能显示旧的加密格式，而无法显示新标准加密格式！</translation>
    </message>
</context>
<context>
    <name>MyDialog</name>
    <message>
        <location filename="../dialog.cpp" line="56"/>
        <location filename="../dialog.cpp" line="69"/>
        <location filename="../dialog.cpp" line="83"/>
        <location filename="../dialog.cpp" line="92"/>
        <location filename="../dialog.cpp" line="125"/>
        <source>exec</source>
        <translation>执行</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="61"/>
        <location filename="../dialog.cpp" line="701"/>
        <location filename="../dialog.cpp" line="704"/>
        <location filename="../dialog.cpp" line="707"/>
        <source>teT1InputText</source>
        <translation>请在此输入公钥或私钥,支持以下格式（输入值均为base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="61"/>
        <location filename="../dialog.cpp" line="701"/>
        <location filename="../dialog.cpp" line="732"/>
        <source>acceptPrikeyFormat</source>
        <translation>-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----

-----BEGIN PRIVATE KEY-----
-----END PRIVATE KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="71"/>
        <source>msgText</source>
        <translation>请输入消息值或消息摘要（若为消息值注意长度小于密钥长度-11）
注意：若输入为摘要值也必须选择对应的算法，因为摘要算法将被写入签名中</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="72"/>
        <source>prikeyText</source>
        <translation>请输入私钥,使用pkcs8或pkcs1格式，若为其他格式请使用格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="77"/>
        <source>signText</source>
        <translation>请输入签名值（Base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="78"/>
        <source>pubkeyText</source>
        <translation>请输入公钥,使用SubjectPublicKeyInfo结构，若为其他格式请使用格式转换，支持格式如下：
-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="79"/>
        <source>verifyMsg</source>
        <translation>请输入待验证消息值</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="85"/>
        <source>showMsg</source>
        <translation>验证消息值</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="90"/>
        <location filename="../dialog.cpp" line="729"/>
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
        <location filename="../dialog.cpp" line="90"/>
        <location filename="../dialog.cpp" line="729"/>
        <location filename="../dialog.cpp" line="732"/>
        <source>teT4InputText</source>
        <translation>请在此输入私钥,支持以下格式（输入值均为base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="95"/>
        <location filename="../dialog.cpp" line="118"/>
        <source>inputPassText</source>
        <translation>请输入密码</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="100"/>
        <location filename="../dialog.cpp" line="127"/>
        <source>chooseAlg</source>
        <translation>变更加密算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="101"/>
        <source>cryptoAlg</source>
        <translation>加密算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="117"/>
        <source>teT5PriHint</source>
        <translation>若密码值为空则生成未加密的私钥

若模数位数过大需要一定时间等待</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="151"/>
        <source>privateKey</source>
        <translation>私钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="156"/>
        <source>publicKey</source>
        <translation>公钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="160"/>
        <source>xmlFromat</source>
        <translation>xml格式</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="165"/>
        <source>chooseInputType</source>
        <translation>选择输入类型</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="186"/>
        <source>transFormat</source>
        <translation>格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="195"/>
        <location filename="../dialog.cpp" line="236"/>
        <source>noHash</source>
        <translation>未hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="200"/>
        <location filename="../dialog.cpp" line="241"/>
        <source>Hash</source>
        <translation>已hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="567"/>
        <source>sourMsgAscii</source>
        <translation>原消息值(ascii)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="569"/>
        <source>sourMsgHex</source>
        <translation>原消息值(hex)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="88"/>
        <location filename="../dialog.cpp" line="204"/>
        <source>msgIsHash</source>
        <translation>消息值是否已是摘要</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="122"/>
        <source>setBySelf</source>
        <translation>自定义(16-6939)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="225"/>
        <source>sign</source>
        <translation>签名</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="266"/>
        <source>verify</source>
        <translation>验签</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="276"/>
        <source>decodeprikey</source>
        <translation>私钥去密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="281"/>
        <source>encodeprikey</source>
        <translation>私钥加密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="285"/>
        <source>chooseProgram</source>
        <translation>选择操作</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="294"/>
        <location filename="../dialog.cpp" line="325"/>
        <source>inputPass</source>
        <translation>输入密码</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="316"/>
        <source>prikeyEnOrDecode</source>
        <translation>私钥加密或去密</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="331"/>
        <source>cryptoOption</source>
        <translation>加密操作</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="343"/>
        <source>modulus bits</source>
        <translation>模数(n)位数</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="355"/>
        <source>public exponent</source>
        <translation>公钥指数</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="384"/>
        <source>generateRSA</source>
        <translation>生成RSA公私钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="394"/>
        <source>copyRight</source>
        <translation>Copyright@2017, fzj</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="406"/>
        <source>about</source>
        <translation>关于</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="449"/>
        <location filename="../dialog.cpp" line="489"/>
        <location filename="../dialog.cpp" line="653"/>
        <source>priKeyInputErr</source>
        <translation>私钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="457"/>
        <location filename="../dialog.cpp" line="557"/>
        <source>pubKeyInputErr</source>
        <translation>公钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="469"/>
        <source>xmlKeyInputErr</source>
        <translation>公（私）钥格式输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="484"/>
        <location filename="../dialog.cpp" line="548"/>
        <location filename="../dialog.cpp" line="552"/>
        <location filename="../dialog.cpp" line="640"/>
        <location filename="../dialog.cpp" line="656"/>
        <source>contentNull</source>
        <translation>输入内容不完整</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="528"/>
        <source>signBase64</source>
        <translation>签名后Base64编码显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="530"/>
        <source>signHex</source>
        <translation>签名后16进制显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="534"/>
        <source>signErr</source>
        <translation>签名出错</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="571"/>
        <source>signAlgorithm</source>
        <translation>签名算法</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="606"/>
        <source>inputMsgHex</source>
        <translation>输入消息值(hex)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="612"/>
        <source>inputMsgAscii</source>
        <translation>输入消息值(ascii)</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="619"/>
        <source>inputMsgEqualsourMsg</source>
        <translation>输入消息值与原消息值相同，验签成功</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="621"/>
        <source>inputMsgUnequalsourMsg</source>
        <translation>输入消息值与原消息值不同，验签失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="626"/>
        <source>verifyErr</source>
        <translation>验签失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="645"/>
        <source>passErrOrKeyErr</source>
        <translation>密码或私钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="676"/>
        <source>bitsOutLimit</source>
        <translation>模数位数不符合要求</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="704"/>
        <source>acceptPubkeyFormat</source>
        <translation>-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----

-----BEGIN RSA PUBLIC KEY-----
-----END RSA PUBLIC KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="707"/>
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
        <location filename="../dialog.cpp" line="830"/>
        <source>showCryPKCS8PemErr</source>
        <translation>显示加密PKCS8格式失败</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="838"/>
        <source>showCryPKCS1PemErr</source>
        <translation>显示加密旧格式失败</translation>
    </message>
</context>
</TS>
