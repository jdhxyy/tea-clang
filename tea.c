// Copyright 2013-2021 The jdh99 Authors. All rights reserved.
// tea算法
// Authors: jdh99 <jdh821@163.com>
// 说明:TEA加密解密算法
// TEA(Tiny Encryption Algorithm)是一种简单高效的加密算法，以加密解密速度快，
// 实现简单著称。
// 算法很简单，TEA算法每一次可以操作64-bit(8-byte)，采用128-bit(16-byte)作为key，
// 算法采用迭代的形式，
// 推荐的迭代轮数是64轮，最少32轮.本模块使用32轮

#include "tea.h"

// encrypt 加密
// v:要加密的数据,长度为8字节.k:加密用的key,长度为16字节
static void encrypt(uint32_t* v, uint32_t* k);

// decrypt 解密
// v:要解密的数据,长度为8字节.k:解密用的key,长度为16字节
static void decrypt(uint32_t *v,uint32_t *k);

// TeaEncrypt tea加密
// 要求数据必须是8字节的倍数.加密的数据长度等于明文数据长度
// key是16字节128位
void TeaEncrypt(uint8_t* data, uint16_t size, uint8_t* key) {
    uint16_t i = 0;
    uint16_t num = 0;

    if (size % 8 != 0) {
        return;
    }
    
    // 加密
    num = size / 8;
    for (i = 0; i < num; i++) {
        encrypt((uint32_t *)(data + i * 8), (uint32_t *)key);
    }
}

// encrypt 加密
// v:要加密的数据,长度为8字节.k:加密用的key,长度为16字节
static void encrypt(uint32_t* v, uint32_t* k) {
    uint32_t y = v[0], z = v[1], sum = 0, i;
    uint32_t delta = 0x9e3779b9;
    uint32_t a = k[0], b = k[1], c = k[2], d = k[3];

    for (i = 0; i < 32; i++) {
        sum += delta;
        y += ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
        z += ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
    }
    v[0] = y;
    v[1] = z;
}

// TeaDecrypt tea解密
// 要求数据必须是8字节的倍数.解密的数据长度等于加密数据长度
// key是16字节128位
void TeaDecrypt(uint8_t* data, uint16_t size, uint8_t* key) {
    uint16_t i = 0;
    uint16_t num = 0;
    
    // 判断长度是否为8的倍数
    if (size % 8 != 0) {
        return;
    }
    
    // 解密
    num = size / 8;
    for (i = 0; i < num; i++) {
        decrypt((uint32_t *)(data + i * 8), (uint32_t *)key);
    }
}

// decrypt 解密
// v:要解密的数据,长度为8字节.k:解密用的key,长度为16字节
static void decrypt(uint32_t *v,uint32_t *k) {
    uint32_t y = v[0], z = v[1], sum = 0xC6EF3720, i;
    uint32_t delta = 0x9e3779b9;
    uint32_t a = k[0], b = k[1], c = k[2], d = k[3];
    
    for (i = 0; i < 32; i++) {
        z -= ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
        y -= ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
        sum -= delta;
    }
    v[0] = y;
    v[1] = z;
}
