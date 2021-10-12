// Copyright 2013-2021 The jdh99 Authors. All rights reserved.
// tea�㷨
// Authors: jdh99 <jdh821@163.com>
// ˵��:TEA���ܽ����㷨
// TEA(Tiny Encryption Algorithm)��һ�ּ򵥸�Ч�ļ����㷨���Լ��ܽ����ٶȿ죬
// ʵ�ּ����ơ�
// �㷨�ܼ򵥣�TEA�㷨ÿһ�ο��Բ���64-bit(8-byte)������128-bit(16-byte)��Ϊkey��
// �㷨���õ�������ʽ��
// �Ƽ��ĵ���������64�֣�����32��.��ģ��ʹ��32��

#ifndef TEA_H
#define TEA_H

#include <stdint.h>

// TeaEncrypt tea����
// Ҫ�����ݱ�����8�ֽڵı���.���ܵ����ݳ��ȵ����������ݳ���
// key��16�ֽ�128λ
void TeaEncrypt(uint8_t* data, uint16_t size, uint8_t* key);

// TeaDecrypt tea����
// Ҫ�����ݱ�����8�ֽڵı���.���ܵ����ݳ��ȵ��ڼ������ݳ���
// key��16�ֽ�128λ
void TeaDecrypt(uint8_t* data, uint16_t size, uint8_t* key);

#endif
