//
//  SEEDDEMO_iOSTests.m
//  SEEDDEMO-iOSTests
//
//  Created by tigi on 11/12/2018.
//  Copyright © 2018 tigi. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "SeedUtil.h"

@interface SEEDDEMO_iOSTests : XCTestCase

@end

@implementation SEEDDEMO_iOSTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    
    NSString *sKey = @"asdasdasdasdasdasdasdasdasdasdasdasdasdasd";
    NSString *sData = @"qwwwweqweqweqweqweqweqweqweqweqweweqwe";
    
    NSString *sEncryptData = [SeedUtil encryptBySeed:sData key:sKey];
    NSLog(@"encData=%@", sEncryptData);
    
    NSAssert([sEncryptData isEqualToString:@"/SSHeJMRh3XW921aseMkjWZKN/B5jk3jNvz043HI6+cXXoO/+D3rsJnYrQIe1eKT"], @"Wrong Encrypted Data!!");
    
    NSString *sDecryptData = [SeedUtil decryptBySeed:sEncryptData key:sKey];
    NSLog(@"decData=%@", sDecryptData);
    
    NSAssert([sDecryptData isEqualToString:sData], @"Wrong Decrypted Data!!");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
