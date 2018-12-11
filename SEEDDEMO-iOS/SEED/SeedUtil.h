//
//  SeedUtil.h
//  SEEDDemo_app
//
//  Created by tigi on 2018. 5. 28..
//  Copyright © 2018년 tigi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SeedUtil : NSObject

+(NSString *)encryptBySeed:(NSString *)aData key:(NSString *)aKey;
+(NSString *)decryptBySeed:(NSString *)aData key:(NSString *)aKey;

@end
