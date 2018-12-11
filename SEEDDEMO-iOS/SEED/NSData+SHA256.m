//
//  NSData+SHA256.m
//  SEEDDemo_app
//
//  Created by tigi on 2018. 6. 22..
//  Copyright © 2018년 tigi. All rights reserved.
//

#import "NSData+SHA256.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSData (SHA256)

+(NSData *)SHA256:(NSData *)input {
    unsigned char result[CC_SHA256_DIGEST_LENGTH];
    
    CC_SHA256(input.bytes, (CC_LONG)input.length, result);
    return [[NSData alloc] initWithBytes:result length:CC_SHA256_DIGEST_LENGTH];
}

-(NSData *)SHA256 {
    return [NSData SHA256:self];
}

+(NSString *)SHA256Hex:(NSData *)input {
    unsigned char result[CC_SHA256_DIGEST_LENGTH];
    
    CC_SHA256(input.bytes, (CC_LONG)input.length, result);
    NSMutableString *ret = [NSMutableString stringWithCapacity:CC_SHA256_DIGEST_LENGTH*2];
    for (int i = 0; i<CC_SHA256_DIGEST_LENGTH; i++) {
        [ret appendFormat:@"%02x",result[i]];
    }
    return ret;
}

-(NSString *)SHA256Hex {
    return [NSData SHA256Hex:self];
}

@end
