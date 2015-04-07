/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! @file AWCommandManager.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWCommandTypes.h>
#import <AWSDK/AWProfile.h>
#import <AWSDK/AWCommand.h>
#import <AWSDK/AWCommandResponse.h>

@class AWCommandManager;

/**
 @brief		The delegate of a `AWCommandManager`.
 @version 3.7.1
 */
@protocol AWCommandManagerDelegate <NSObject>

@required
/**
 *  This will test to see if your handler object is of the correct type to execute an incoming command request.
 *
 *  @param commandType A Command type of AWCommandTypes.
 *
 *  @return Returns the result of the delegate executing the command.
 */
- (BOOL)canHandleCommandType:(AWCommandType)commandType;


/*!
 @method
 @param command An AWCommand from the console to be processed by the delegate.
 @return Returns an AWCommandResponse object based on the execution status of the command.
 */
- (AWCommandResponse*)responseForCommand:(AWCommand *)command;

@optional

/**
 *  Notifies the delegate that the command processor failed to process a command.
 *
 *  @param processor The command processor.
 *  @param error Details of the error
 */
- (void)commandManager:(AWCommandManager *)proccessor failedWithError:(NSError *)error;

/**
 *  Notifies the delegate of an empty command queue. There's no or no more command to process.
 *
 *  @param processor The command processor.
 *
 */
- (void)commandManagerFinishedReceivingCommands:(AWCommandManager *)processor;

/**
 *  Notifies the delegate of the start of command processing.
 *
 *  @param processor The command processor.
 *
 */
- (void)commandManagerStartedReceivingCommands:(AWCommandManager *)processor;

@end


extern NSString *const kAWProfileUpdated AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use AWNotificationCommandManagerInstalledNewProfile");
extern NSString *const AWNotificationCommandManagerInstalledNewProfile;
extern NSString *const AWNotificationCommandManagerRemovedApplicationProfiles;
/**
 @brief		Command manager is used to query the command queue.
 @details	Manager for the command processor. Allows a device to query the command queue for commands to execute.
 @version 3.7.1
 */
@interface AWCommandManager : NSObject <AWCommandManagerDelegate>
{
    
}

/**
 *  The object that acts as the delegate of the receiving command processor.
 *
 *  The delegate must adopt the AWCommandManagerDelegate protocol. The delegate object is not retained.
 */
@property (nonatomic, assign) id <AWCommandManagerDelegate>delegate;

/**
 *  Returns the singleton instance of the CommandManager class.
 *
 *  Method should be called when you need to access an instantiated CommandManager singleton.
 *
 *  @return the shared AWCommandManager object instantiated in the singleton.
 */
+ (AWCommandManager *)sharedManager;

/**
 *  This will register a handler object with the CommandManager to be used when an incoming command is to be processed.
 *
 *  @param handler A handler that can process a command and responds to the AWCommandManagerDelegate protocols.
 *
 */
- (void)registerForCommands:(id <AWCommandManagerDelegate>)handler;

/**
 *  This will remove a handler from the CommandManager registration list.
 *
 *  @param handler An object to be removed from the registration list.
 *
 */
- (void)unregisterForCommands:(id <AWCommandManagerDelegate>)handler;

/**
 Starts loading commands from AirWatch with the command processor.
 */
- (void)loadCommands;

/** Returns the SDK profile that was saved upon the last Install Profile Command
 @return the AWProfile stored locally
 */
- (AWProfile *) sdkProfile;

/** Returns the app profile that was saved upon the last Install Profile Command
 @return the AWProfile stored locally
 */
- (AWProfile *) appProfile;

/**
 This method returns all stored profiles.
 @return an NSArray containing all stored AWProfile objects.
 */
- (NSArray *) allProfiles;

/**
 This method is used to obtain a specific Profile. The method find all profiles that contain a
 payload where the value for PayloadType matches the passed parameter.
 
 @param key NSString used to find specific payloads
 @return    an array of AWProfile objects containing a payload that matches provided key for
            Payload Type
 */
- (NSArray *) profilesWithPayloadType:(NSString*)type;

@end
