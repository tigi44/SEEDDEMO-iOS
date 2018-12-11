/*!
 * \file seed.h
 * \brief SEED 암호 알고리즘 (관련표준 : TTAS.KO-12.0004 : 128비트 블록암호알고리즘(SEED))
 * \author
 * Copyright (c) 2011 by \<KISA\>
 */
#ifndef KISA_SEED_H
#define KISA_SEED_H

#ifdef  __cplusplus
extern "C" {
#endif

#define SEED_BLOCK_SIZE 16			/*!< SEED 블럭 크기*/
#define SEED_ENCRYPT	1			/*!< SEED 암호화 모드*/
#define SEED_DECRYPT	0			/*!< SEED 복호화 모드*/

	/*!
	 * \brief
	 * SEED 내부 엔진 암호화를 위한 SEED Key 구조체
	 * \remarks
	 * unsigned int key_data[32] 자료형
	 */
	typedef struct kisa_seed_key_st {
		unsigned int key_data[32];
	} KISA_SEED_KEY;

	/*!
	* \brief
	* SEED 초기화를 위한 암호화키 지정 함수
	* \param user_key
	* 사용자가 지정하는 입력 키 (16 bytes)
	* \param ks
	* 사용자가 지정하는 키가 저장되는 키 구조체
	* \remarks
	* const unsigned char *user_key의 크기는 반드시 16 bytes 가 입력되어야 하고 키구조체(KISA_SEED_KEY *ks)는 메모리 할당이 되어있어야 함
	*/
	void KISA_SEED_init(const unsigned char *user_key, KISA_SEED_KEY *ks);

	/*!
	* \brief
	* SEED 알고리즘 단일 블럭 암호화 함수
	* \param in
	* 사용자 입력 평문(16 bytes)
	* \param out
	* 사용자 입력에 대한 출력 암호문(16 bytes)
	* \param ks
	* KISA_SEED_init로 사용자 키가 설정된 KISA_SEED_KEY 구조체
	* \remarks
	* -# 사용자 입력 평문(const unsigned char *in)의 크기는 반드시 16 bytes 를 입력
	* -# 출력 암호문(unsigned char *out)는 16 bytes 이상 메모리 할당이 되어 있어야 하며, 16 bytes 암호문에 저장됨
	*/
	void KISA_SEED_encrypt_block(const unsigned int *in, unsigned int *out, const KISA_SEED_KEY *ks);


	/*!
	* \brief
	* SEED 알고리즘 단일 블럭 복호화 함수
	* \param in
	* 사용자 입력 암호문(16 bytes)
	* \param out
	* 사용자 입력에 대한 출력 평문(16 bytes)
	* \param ks
	* KISA_SEED_init로 사용자 키가 설정된 KISA_SEED_KEY 구조체
	* \remarks
	* -# 사용자 입력 암호문(const unsigned char *in)의 크기는 반드시 16 bytes 를 입력
	* -# 출력 평문(unsigned char *out)는 16 bytes 이상 메모리 할당이 되어 있어야 하며, 16 bytes 평문에 저장됨
	*/
	void KISA_SEED_decrypt_block(const unsigned int *in, unsigned int *out, const KISA_SEED_KEY *ks);
	
	unsigned int* chartoint32(unsigned char *in, int inLen);
	unsigned char* int32tochar(unsigned int *in, int inLen);

	void KISA_SEED_BLOCK_ENCRYPT(unsigned char *user_key,unsigned char *in,unsigned char *out);
	
	void KISA_SEED_BLOCK_DECRYPT(unsigned char *user_key,unsigned char *in,unsigned char *out);
	

#ifdef  __cplusplus
}
#endif


#endif /* HEADER_SEED_H */