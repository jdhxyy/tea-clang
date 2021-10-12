// Copyright 2013-2021 The jdh99 Authors. All rights reserved.
// tea�㷨
// Authors: jdh99 <jdh821@163.com>
// ˵��:TEA���ܽ����㷨
// TEA(Tiny Encryption Algorithm)��һ�ּ򵥸�Ч�ļ����㷨���Լ��ܽ����ٶȿ죬
// ʵ�ּ����ơ�
// �㷨�ܼ򵥣�TEA�㷨ÿһ�ο��Բ���64-bit(8-byte)������128-bit(16-byte)��Ϊkey��
// �㷨���õ�������ʽ��
// �Ƽ��ĵ���������64�֣�����32��.��ģ��ʹ��32��

#include "tea.h"

// encrypt ����
// v:Ҫ���ܵ�����,����Ϊ8�ֽ�.k:�����õ�key,����Ϊ16�ֽ�
static void encrypt(uint32_t* v, uint32_t* k);

// decrypt ����
// v:Ҫ���ܵ�����,����Ϊ8�ֽ�.k:�����õ�key,����Ϊ16�ֽ�
static void decrypt(uint32_t *v,uint32_t *k);

// TeaEncrypt tea����
// Ҫ�����ݱ�����8�ֽڵı���.���ܵ����ݳ��ȵ����������ݳ���
// key��16�ֽ�128λ
void TeaEncrypt(uint8_t* data, uint16_t size, uint8_t* key) {
    uint16_t i = 0;
    uint16_t num = 0;

    if (size % 8 != 0) {
        return;
    }
    
    // ����
    num = size / 8;
    for (i = 0; i < num; i++) {
        encrypt((uint32_t *)(data + i * 8), (uint32_t *)key);
    }
}

// encrypt ����
// v:Ҫ���ܵ�����,����Ϊ8�ֽ�.k:�����õ�key,����Ϊ16�ֽ�
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

// TeaDecrypt tea����
// Ҫ�����ݱ�����8�ֽڵı���.���ܵ����ݳ��ȵ��ڼ������ݳ���
// key��16�ֽ�128λ
void TeaDecrypt(uint8_t* data, uint16_t size, uint8_t* key) {
    uint16_t i = 0;
    uint16_t num = 0;
    
    // �жϳ����Ƿ�Ϊ8�ı���
    if (size % 8 != 0) {
        return;
    }
    
    // ����
    num = size / 8;
    for (i = 0; i < num; i++) {
        decrypt((uint32_t *)(data + i * 8), (uint32_t *)key);
    }
}

// decrypt ����
// v:Ҫ���ܵ�����,����Ϊ8�ֽ�.k:�����õ�key,����Ϊ16�ֽ�
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
