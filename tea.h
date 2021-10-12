// Copyright 2013-2021 The jdh99 Authors. All rights reserved.
// tea算法
// Authors: jdh99 <jdh821@163.com>
// 说明:TEA加密解密算法
// TEA(Tiny Encryption Algorithm)是一种简单高效的加密算法，以加密解密速度快，
// 实现简单著称。
// 算法很简单，TEA算法每一次可以操作64-bit(8-byte)，采用128-bit(16-byte)作为key，
// 算法采用迭代的形式，
// 推荐的迭代轮数是64轮，最少32轮.本模块使用32轮

#ifndef TEA_H
#define TEA_H

#include <stdint.h>

// TeaEncrypt tea加密
// 要求数据必须是8字节的倍数.加密的数据长度等于明文数据长度
// key是16字节128位
void TeaEncrypt(uint8_t* data, uint16_t size, uint8_t* key);

// TeaDecrypt tea解密
// 要求数据必须是8字节的倍数.解密的数据长度等于加密数据长度
// key是16字节128位
void TeaDecrypt(uint8_t* data, uint16_t size, uint8_t* key);

#endif
