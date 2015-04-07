//
//  AWCompliancePolicy.h
//  AirWatch
//
//  Created by Nolan Roberson on 1/21/13.
//  Copyright (c) 2013 AirWatch. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    AWComplianceUnknown = 0,
    AWCompliant = 3,
    AWNonCompliant = 4
} AWComplianceStatus;

@interface AWCompliancePolicy : NSObject

@property (readonly) NSString *policyIdentifier;
@property (nonatomic, copy) NSString *policyName;
@property (nonatomic, copy) NSString *policyStatus;
@property (nonatomic) AWComplianceStatus status;
@property (nonatomic, retain) NSDate *lastComplicanceCheck;
@property (nonatomic, retain) NSDictionary *rule;

- (void)evaluateCompliance;

@end

@interface AWPasscodeCompliancePolicy : AWCompliancePolicy

@end

@interface AWCompromisedCompliancePolicy : AWCompliancePolicy

@end
