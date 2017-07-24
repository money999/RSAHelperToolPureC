<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>Dialog</name>
    <message>
        <source>privateKey</source>
        <translation type="vanished">私钥</translation>
    </message>
    <message>
        <source>publicKey</source>
        <translation type="vanished">公钥</translation>
    </message>
    <message>
        <source>xmlFromat</source>
        <translation type="vanished">xml格式</translation>
    </message>
    <message>
        <source>chooseInputType</source>
        <translation type="vanished">选择输入类型</translation>
    </message>
    <message>
        <source>sign</source>
        <translation type="vanished">签名</translation>
    </message>
    <message>
        <source>exec</source>
        <translation type="vanished">执行</translation>
    </message>
    <message>
        <source>teT1InputText</source>
        <translation type="vanished">请在此输入公钥或私钥,支持以下格式（输入值均为base64编码）
-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----

-----BEGIN PRIVATE KEY-----
-----END PRIVATE KEY-----

&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
	&lt;D&gt;&lt;/D&gt;
	&lt;P&gt;&lt;/P&gt;
	&lt;Q&gt;&lt;/Q&gt;
	&lt;DP&gt;&lt;/DP&gt;
	&lt;DQ&gt;&lt;/DQ&gt;
	&lt;InverseQ&gt;&lt;/InverseQ&gt;
&lt;/RSAKeyValue&gt;

-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----

-----BEGIN RSA PUBLIC KEY-----
-----END RSA PUBLIC KEY-----

&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
&lt;/RSAKeyValue&gt;
</translation>
    </message>
    <message>
        <source>msgText</source>
        <translation type="vanished">请输入消息值或消息摘要
注意：若输入为摘要值也必须选择对应的算法，因为摘要算法将被写入签名中</translation>
    </message>
    <message>
        <source>keyText</source>
        <translation type="vanished">请输入私钥,使用pkcs8或pkcs1格式，若为其他格式请使用格式转换</translation>
    </message>
    <message>
        <source>prikeyText</source>
        <translation type="vanished">请输入私钥,使用pkcs8或pkcs1格式，若为其他格式请使用格式转换</translation>
    </message>
    <message>
        <source>signText</source>
        <translation type="vanished">请输入签名值（Base64编码）</translation>
    </message>
    <message>
        <source>pubkeyText</source>
        <translation type="vanished">请输入公钥,使用SubjectPublicKeyInfo结构，若为其他格式请使用格式转换，支持格式如下：
-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----</translation>
    </message>
    <message>
        <source>transFormat</source>
        <translation type="vanished">格式转换</translation>
    </message>
    <message>
        <source>noHash</source>
        <translation type="vanished">未hash</translation>
    </message>
    <message>
        <source>Hash</source>
        <translation type="vanished">已hash</translation>
    </message>
    <message>
        <source>msgIsHash</source>
        <translation type="vanished">消息值是否已是摘要</translation>
    </message>
    <message>
        <source>verify</source>
        <translation type="vanished">验签</translation>
    </message>
    <message>
        <source>priKeyInputErr</source>
        <translation type="vanished">私钥输入有误</translation>
    </message>
    <message>
        <source>pubKeyInputErr</source>
        <translation type="vanished">公钥输入有误</translation>
    </message>
    <message>
        <source>xmlKeyInputErr</source>
        <translation type="vanished">公（私）钥格式输入有误</translation>
    </message>
    <message>
        <source>contentNull</source>
        <translation type="vanished">输入内容不完整</translation>
    </message>
    <message>
        <source>signBase64</source>
        <translation type="vanished">签名后Base64编码显示</translation>
    </message>
    <message>
        <source>signHex</source>
        <translation type="vanished">签名后16进制显示</translation>
    </message>
    <message>
        <source>signErr</source>
        <translation type="vanished">签名出错</translation>
    </message>
</context>
<context>
    <name>MyDialog</name>
    <message>
        <location filename="../dialog.cpp" line="33"/>
        <location filename="../dialog.cpp" line="45"/>
        <location filename="../dialog.cpp" line="58"/>
        <source>exec</source>
        <translation type="unfinished">执行</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="37"/>
        <source>teT1InputText</source>
        <translation type="unfinished">请在此输入公钥或私钥,支持以下格式（输入值均为base64编码）
-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----

-----BEGIN PRIVATE KEY-----
-----END PRIVATE KEY-----

&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
	&lt;D&gt;&lt;/D&gt;
	&lt;P&gt;&lt;/P&gt;
	&lt;Q&gt;&lt;/Q&gt;
	&lt;DP&gt;&lt;/DP&gt;
	&lt;DQ&gt;&lt;/DQ&gt;
	&lt;InverseQ&gt;&lt;/InverseQ&gt;
&lt;/RSAKeyValue&gt;

-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----

-----BEGIN RSA PUBLIC KEY-----
-----END RSA PUBLIC KEY-----

&lt;RSAKeyValue&gt;
	&lt;Modulus&gt;&lt;/Modulus&gt;
	&lt;Exponent&gt;&lt;/Exponent&gt;
&lt;/RSAKeyValue&gt;
</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="46"/>
        <source>msgText</source>
        <translation type="unfinished">请输入消息值或消息摘要
注意：若输入为摘要值也必须选择对应的算法，因为摘要算法将被写入签名中</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="47"/>
        <source>prikeyText</source>
        <translation type="unfinished">请输入私钥,使用pkcs8或pkcs1格式，若为其他格式请使用格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="52"/>
        <source>signText</source>
        <translation type="unfinished">请输入签名值（Base64编码）</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="53"/>
        <source>pubkeyText</source>
        <translation type="unfinished">请输入公钥,使用SubjectPublicKeyInfo结构，若为其他格式请使用格式转换，支持格式如下：
-----BEGIN PUBLIC KEY-----
-----END PUBLIC KEY-----</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="54"/>
        <source>verifyMsg</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="59"/>
        <source>showMsg</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="80"/>
        <source>privateKey</source>
        <translation type="unfinished">私钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="85"/>
        <source>publicKey</source>
        <translation type="unfinished">公钥</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="89"/>
        <source>xmlFromat</source>
        <translation type="unfinished">xml格式</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="94"/>
        <source>chooseInputType</source>
        <translation type="unfinished">选择输入类型</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="115"/>
        <source>transFormat</source>
        <translation type="unfinished">格式转换</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="124"/>
        <source>noHash</source>
        <translation type="unfinished">未hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="129"/>
        <source>Hash</source>
        <translation type="unfinished">已hash</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="133"/>
        <source>msgIsHash</source>
        <translation type="unfinished">消息值是否已是摘要</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="154"/>
        <source>sign</source>
        <translation type="unfinished">签名</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="184"/>
        <location filename="../dialog.cpp" line="195"/>
        <source>verify</source>
        <translation type="unfinished">验签</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="225"/>
        <location filename="../dialog.cpp" line="265"/>
        <source>priKeyInputErr</source>
        <translation type="unfinished">私钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="233"/>
        <location filename="../dialog.cpp" line="331"/>
        <source>pubKeyInputErr</source>
        <translation type="unfinished">公钥输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="245"/>
        <source>xmlKeyInputErr</source>
        <translation type="unfinished">公（私）钥格式输入有误</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="260"/>
        <location filename="../dialog.cpp" line="322"/>
        <location filename="../dialog.cpp" line="326"/>
        <source>contentNull</source>
        <translation type="unfinished">输入内容不完整</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="302"/>
        <source>signBase64</source>
        <translation type="unfinished">签名后Base64编码显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="304"/>
        <source>signHex</source>
        <translation type="unfinished">签名后16进制显示</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="308"/>
        <source>signErr</source>
        <translation type="unfinished">签名出错</translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="339"/>
        <source>sourMsg</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="341"/>
        <source>signAlgorithm</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../dialog.cpp" line="366"/>
        <source>verifyErr</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
