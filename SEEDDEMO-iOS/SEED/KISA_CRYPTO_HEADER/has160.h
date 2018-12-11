/*!
 * \file has160.h
 * \brief HAS160 Digest 알고리즘 (관련표준 : TTAS.KO-12.0011/R1 - 해쉬함수표준 - 제2부 : 해쉬함수알고리즘표준(HAS160))
 * \author
 * Copyright (c) 2010 by \<KISA\>
 */
#ifndef HAS160_HEADER
#define HAS160_HEADER

#ifdef  __cplusplus
extern "C" {
#endif

#define HAS160_BLOCK_SIZE		64		/*!< HAS160 블럭 크기*/
#define HAS160_DIGEST_LENGTH	20		/*!< HAS160 Digest Output 크기*/

		
	/*!
	 * \brief
	 * HAS160 Digest를 위한 HAS160 구조체
	 */
	typedef struct has160_state_st{
		unsigned int state[5];
		unsigned int length[2];
		unsigned char data[64];
	} KISA_HAS160;


	/*!
	 * \brief
	 * HAS160 Digest를 위한 구조체 초기화 함수
	 * 
	 * \param has160
	 * HAS160 Digest를 위한 구조체 지정 (미리 메모리가 할당되어 있어야 함)
	 * 
	 * \returns
	 * 초기화 성공 (1) / 메모리가 적절히 할당되지 않았을 경우 (0)
	 */
	int KISA_HAS160_init(KISA_HAS160 *has160);


	/*!
	 * \brief
	 * HAS160 알고리즘 Digest 함수
	 * 
	 * \param has160
	 * HAS160 Digest를 위한 구조체 지정 (KISA_HAS160_init으로 초기화 필요)
	 * 
	 * \param data
	 * 사용자 입력 평문
	 * 
	 * \param length
	 * 사용자 입력 평문의 길이
	 * 
	 * \returns
	 * 구동 성공 (1) / 메모리 할당 혹은 초기화가 적절히 이루어지지 않았을 경우 (0)
	 * 
	 * \remarks
	 * 사용자 입력 평문의 길이(length)는 data에 저장된 데이터의 길이와 일치해야 함
	 */
	int KISA_HAS160_update(KISA_HAS160 *has160, const unsigned char *data, unsigned int length);


	/*!
	 * \brief
	 * HAS160 알고리즘 Digest 완료 함수
	 * 
	 * \param has160
	 * HAS160 Digest를 위한 구조체 지정 (KISA_HAS160_init으로 초기화 필요)
	 * 
	 * \param md
	 * HAS160 Digest 값이 저장되는 버퍼
	 * 
	 * \returns
	 * 구동 성공 (1) / 메모리 할당 혹은 초기화가 적절히 이루어지지 않았을 경우 (0)
	 *
	 * \remarks
	 * 출력버퍼 md의 크기는 HAS160 Digest의 한 블럭(20 Bytes) 이상으로 메모리 할당이 되어 있어야 함
	 */
	int KISA_HAS160_final(KISA_HAS160 *has160, unsigned char* md);

#ifdef  __cplusplus
}
#endif

#endif