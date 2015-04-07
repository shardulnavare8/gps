//
//  AWDeviceLockCommand.h
//  AirWatch
//
//  Created by Pranay Swar on 7/27/13.
//  Copyright (c) 2013 AirWatch. All rights reserved.
//

#import <AWSDK/AWCommand.h>

@interface AWDeviceLockCommand : AWCommand
/** Time when command was queued. */
@property (nonatomic,readonly) NSDate *commandTimeStamp;
@end
