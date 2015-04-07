/*! 
 @header AWCommandResponse
 The AWCommandResponse class declares the pragmatic interface for an object that manages responses
 to an @link AWCommand @/link that is sent from the AirWatch console.
 
 @language objc
 
 @copyright Copyright 2013 AirWatch LLC. All rights reserved.<p>
 Unless required by applicable law, this Software Development Kit and sample code is distributed on
 an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. AirWatch
 expressly disclaims any and all liability resulting from User’s use of this Software Development
 Kit. Any modification made to the SDK must have written approval by AirWatch.</p>
 */

#import <Foundation/Foundation.h>
#import <AWSDK/AWCommandTypes.h>
#import <AWSDK/AWCommand.h>

/*!
    @enum AWResponseContentType
    @brief These constants specify types of content that can be sent in an AWCommandResponse.
 
    @constant AWCertificateResponseContent Indicates that the response content is an array of one or
    more NSDictionaries containing the required information about installed certificates.
 
    @constant AWInstalledProfilesContent Indicates that the response content is an array of one or
    more NSDictionaries containing the required information about installed profiles.
 */
enum
{
    AWCertificateResponseContent = 0,
    AWInstalledProfilesContent
};
typedef NSUInteger AWResponseContentType;

/*! @constant 
    @brief The key to use when specifying a certificate common name.
 */
extern NSString *const AWCertificateResponseCommonName;

/*! @constant 
    @brief The key to use when specifying a certificate's data section.
 */
extern NSString *const AWCertificateResponseData;

/*! @constant 
    @brief The key to use when indicating if a certificate is an identity.
 */
extern NSString *const AWCertificateResponseIsIdentity;

@interface AWCommandResponse : NSObject

/*!
 @property
 @brief Indicates the status of how a command was handled.
 */
@property (nonatomic, assign) AWCommandStatus status;

/*!
 @property
 @brief The UUID of the command that the receiver is a response for.
 */
@property (nonatomic, copy) NSString *payloadIdentifier;

/*!
 @property
 @brief The target command that the receiver is a response for.
 */
@property (nonatomic, copy) NSString *commandTarget;


/*!
 @property
 @brief The object that will be sent along with the status.
 @discussion
     <p>If <strong><i>contentType</i></strong> is AWCertificateResponseContent, then
     <strong><i>content</i></strong> should be a NSArray of NSDictionary objects. These dictionaries
     should contain three key/value pairs.
     1. Key: @link AWCertificateResponseCommonName @/link - Value: (NSString) The common name of the
     certificate.
     2. Key: @link AWCertificateResponseData @/link - Value: (NSString) The bases 64 encoded data
     portion of the certificate.
     3. Key: @link AWCertificateResponseIsIdentity @/link - Value: (BOOL) Indicates if the
     certificate is an identity.
     </p>
 */
@property (nonatomic, retain) id responseContent;

/*!
 @property
 @brief The type of <strong><i>responseContent</i></strong> being sent.
 */
@property (nonatomic, assign) AWResponseContentType contentType;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
        @link ACKNOWLEDGED @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object. 
*/
+ (AWCommandResponse*)acknowledgeResponseForCommand:(AWCommand*)command;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
        @link ACKNOWLEDGED @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @param contentType The @link AWResponseContentType type @/link of content being sent.
 @param content The object that will be serialized and sent to the AirWatch console.
 @return Returns an initialized AWCommandResponse object. 
 @discussion 
    The method determines if <strong><i>content</i></strong> is a valid object based on the 
    <strong><i>contentType</i></strong>. 
 
    
*/
+ (AWCommandResponse*)acknowledgeResponseForCommand:(AWCommand *)command
                                        contentType:(AWResponseContentType)contentType
                                    responseContent:(id)content;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
 @link ERROR @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object.
 */
+ (AWCommandResponse*)errorResponseForCommand:(AWCommand*)command;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
 @link COMMANDFORMATERROR @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object.
 */
+ (AWCommandResponse*)commandFormatErrorResponseForCommand:(AWCommand*)command;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
 @link IDLE @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object.
 */
+ (AWCommandResponse*)idleResponseForCommand:(AWCommand*)command;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
 @link NOTNOW @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object.
 */
+ (AWCommandResponse*)notnowResponseForCommand:(AWCommand*)command;

/*!
 @method
 @brief Returns an AWCommandResponse object with the status set to
 @link UNKNOWN @/link and the payloadIdentifier set to the UUID of command.
 @param command The AWCommand received from the console.
 @return Returns an initialized AWCommandResponse object.
 */
+ (AWCommandResponse*)unknownResponseForCommand:(AWCommand*)command;


/*!
 @method
 @brief Returns a plist as NSData that will be sent as the body of the response to the AirWatch
        console.
 @return NSData containing the reponse information to a command sent by the AirWatch console.
 */
- (NSData*)payload;
@end
