/*!
 * \file seed.h
 * \brief SEED ��ȣ �˰��� (����ǥ�� : TTAS.KO-12.0004 : 128��Ʈ ��Ͼ�ȣ�˰���(SEED))
 * \author
 * Copyright (c) 2011 by \<KISA\>
 */
#ifndef KISA_SEED_H
#define KISA_SEED_H

#ifdef  __cplusplus
extern "C" {
#endif

#define SEED_BLOCK_SIZE 16			/*!< SEED �� ũ��*/
#define SEED_ENCRYPT	1			/*!< SEED ��ȣȭ ���*/
#define SEED_DECRYPT	0			/*!< SEED ��ȣȭ ���*/

	/*!
	 * \brief
	 * SEED ���� ���� ��ȣȭ�� ���� SEED Key ����ü
	 * \remarks
	 * unsigned int key_data[32] �ڷ���
	 */
	typedef struct kisa_seed_key_st {
		unsigned int key_data[32];
	} KISA_SEED_KEY;

	/*!
	* \brief
	* SEED �ʱ�ȭ�� ���� ��ȣȭŰ ���� �Լ�
	* \param user_key
	* ����ڰ� �����ϴ� �Է� Ű (16 bytes)
	* \param ks
	* ����ڰ� �����ϴ� Ű�� ����Ǵ� Ű ����ü
	* \remarks
	* const unsigned char *user_key�� ũ��� �ݵ�� 16 bytes �� �ԷµǾ�� �ϰ� Ű����ü(KISA_SEED_KEY *ks)�� �޸� �Ҵ��� �Ǿ��־�� ��
	*/
	void KISA_SEED_init(const unsigned char *user_key, KISA_SEED_KEY *ks);

	/*!
	* \brief
	* SEED �˰��� ���� �� ��ȣȭ �Լ�
	* \param in
	* ����� �Է� ��(16 bytes)
	* \param out
	* ����� �Է¿� ���� ��� ��ȣ��(16 bytes)
	* \param ks
	* KISA_SEED_init�� ����� Ű�� ������ KISA_SEED_KEY ����ü
	* \remarks
	* -# ����� �Է� ��(const unsigned char *in)�� ũ��� �ݵ�� 16 bytes �� �Է�
	* -# ��� ��ȣ��(unsigned char *out)�� 16 bytes �̻� �޸� �Ҵ��� �Ǿ� �־�� �ϸ�, 16 bytes ��ȣ���� �����
	*/
	void KISA_SEED_encrypt_block(const unsigned int *in, unsigned int *out, const KISA_SEED_KEY *ks);


	/*!
	* \brief
	* SEED �˰��� ���� �� ��ȣȭ �Լ�
	* \param in
	* ����� �Է� ��ȣ��(16 bytes)
	* \param out
	* ����� �Է¿� ���� ��� ��(16 bytes)
	* \param ks
	* KISA_SEED_init�� ����� Ű�� ������ KISA_SEED_KEY ����ü
	* \remarks
	* -# ����� �Է� ��ȣ��(const unsigned char *in)�� ũ��� �ݵ�� 16 bytes �� �Է�
	* -# ��� ��(unsigned char *out)�� 16 bytes �̻� �޸� �Ҵ��� �Ǿ� �־�� �ϸ�, 16 bytes �򹮿� �����
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