//
//  SeedUtil.m
//  SEEDDemo_app
//
//  Created by tigi on 2018. 5. 28..
//  Copyright © 2018년 tigi. All rights reserved.
//

#import "SeedUtil.h"
#import "seedcbc.h"
//#import "sha256.h"
#import "NSData+SHA256.h"

@implementation SeedUtil


#pragma mark - base64

NSString *base64EncodeWithData(NSData *data){
    data = [data base64EncodedDataWithOptions:0];
    NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    return str;
}

NSData *base64DecodeToData(NSString *str){
    NSData *data = [[NSData alloc] initWithBase64EncodedString:str options:NSDataBase64DecodingIgnoreUnknownCharacters];
    return data;
}


#pragma mark - seedKey / seedIv

//+(NSData *)seedKey:(NSString *)aKey
//{
//    NSData *sKeyData = [aKey dataUsingEncoding:NSUTF8StringEncoding];
//
//    unsigned char output[32];
//    KISA_SHA256_MD((unsigned char *)[sKeyData bytes], (int)[sKeyData length], output);
//    sKeyData = [NSData dataWithBytes:output length:strlen((const char *)output)];
//
//    unsigned char sKey[16];
//    [sKeyData getBytes:sKey range:NSMakeRange(0, 16)];
//    return [NSData dataWithBytes:sKey length:sizeof(sKey)];
//}
//+(NSData *)seedIv:(NSString *)aKey
//{
//    NSData *sKeyData = [aKey dataUsingEncoding:NSUTF8StringEncoding];
//
//    unsigned char output[32];
//    KISA_SHA256_MD((unsigned char *)[sKeyData bytes], (int)[sKeyData length], output);
//    sKeyData = [NSData dataWithBytes:output length:strlen((const char *)output)];
//
//    unsigned char sIv[16];
//    [sKeyData getBytes:sIv range:NSMakeRange(16, 8)];
//    return [NSData dataWithBytes:sIv length:sizeof(sIv)];
//}

+(NSData *)seedKeyV2:(NSString *)aKey
{
    NSData *sKeyData = [aKey dataUsingEncoding:NSUTF8StringEncoding];
    sKeyData = [sKeyData SHA256];
    return [sKeyData subdataWithRange:NSMakeRange(0, 16)];
}
+(NSData *)seedIvV2:(NSString *)aKey
{
    NSData *sKeyData = [aKey dataUsingEncoding:NSUTF8StringEncoding];
    sKeyData = [sKeyData SHA256];
    return [sKeyData subdataWithRange:NSMakeRange(16, 8)];
}

#pragma mark - encrypt / decrypt

+(NSString *)encryptBySeed:(NSString *)aData key:(NSString *)aKey
{
    if (aData == nil || aKey == nil)
    {
        return nil;
    }
    
    NSString *sEncryptedString = nil;
    unsigned char *sSeedKey = (unsigned char *) [[self seedKeyV2:aKey] bytes];
    unsigned char *sSeedIv  = (unsigned char *) [[self seedIvV2:aKey] bytes];
    
    NSLog(@"SeedKey=%@", base64EncodeWithData([NSData dataWithBytes:sSeedKey length:16]));
    NSLog(@"SeedIv=%@", base64EncodeWithData([NSData dataWithBytes:sSeedIv length:16]));
    
    NSData *sPlainTextData = [aData dataUsingEncoding:NSUTF8StringEncoding];
        
    unsigned char ciphertext[[sPlainTextData length] + 16];

    int sOutlen = KISA_SEED_CBC_ENCRYPT(sSeedKey,
                                       sSeedIv,
                                       (unsigned char *)[sPlainTextData bytes],
                                       (unsigned int)[sPlainTextData length],
                                       ciphertext);
    
    if (sOutlen > 0)
    {
        NSData *sEncryptData = [NSData dataWithBytes:ciphertext length:sOutlen];
        sEncryptedString = base64EncodeWithData(sEncryptData);
    }
    
    return sEncryptedString;
}

+(NSString *)decryptBySeed:(NSString *)aData key:(NSString *)aKey
{
    if (aData == nil || aKey == nil)
    {
        return nil;
    }
    
    NSString *sDecryptedString = nil;
    unsigned char *sSeedKey = (unsigned char *) [[self seedKeyV2:aKey] bytes];
    unsigned char *sSeedIv  = (unsigned char *) [[self seedIvV2:aKey] bytes];
    
    NSLog(@"SeedKey=%@", base64EncodeWithData([NSData dataWithBytes:sSeedKey length:16]));
    NSLog(@"SeedIv=%@", base64EncodeWithData([NSData dataWithBytes:sSeedIv length:16]));
    
    NSData *sCipherTextData = base64DecodeToData(aData);
    
    unsigned char *plaintext = (unsigned char *)malloc(sizeof(unsigned char) * [sCipherTextData length]);
    
    int sOutlen = KISA_SEED_CBC_DECRYPT(sSeedKey,
                                       sSeedIv,
                                       (unsigned char *)[sCipherTextData bytes],
                                       (unsigned int)[sCipherTextData length],
                                       plaintext);
    
    if (sOutlen > 0)
    {
//        NSLog(@"==Char encoding   : plaintext length = %ld, string = %@", strlen((const char *)plaintext), [NSString stringWithUTF8String:(const char *)plaintext]);
        
        NSData *sDecryptData = [NSData dataWithBytes:plaintext length:sOutlen];
        sDecryptedString = [NSString stringWithUTF8String:[sDecryptData bytes]];
        
//        NSLog(@"==NSData encoding : plaintext length = %d, string = %@", sOutlen, [NSString stringWithUTF8String:[sDecryptData bytes]]);
    }
    
    return [sDecryptedString stringByTrimmingCharactersInSet:[NSCharacterSet controlCharacterSet]];
}

@end
