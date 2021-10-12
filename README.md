# tea

## 1. 介绍
tea算法。

## 2. API
```c
// TeaEncrypt tea加密
// 要求数据必须是8字节的倍数.加密的数据长度等于明文数据长度
// key是16字节128位
void TeaEncrypt(uint8_t* data, uint16_t size, uint8_t* key);

// TeaDecrypt tea解密
// 要求数据必须是8字节的倍数.解密的数据长度等于加密数据长度
// key是16字节128位
void TeaDecrypt(uint8_t* data, uint16_t size, uint8_t* key);
```
