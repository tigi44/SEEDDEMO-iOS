//
//  NSData+SHA256.h
//  SEEDDemo_app
//
//  Created by tigi on 2018. 6. 22..
//  Copyright © 2018년 tigi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (SHA256)

+(NSData *)SHA256:(NSData *)input;
-(NSData *)SHA256;

+(NSString *)SHA256Hex:(NSData *)input;
-(NSString *)SHA256Hex;

@end
