/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWContentCategory.h */

#import <Foundation/Foundation.h>

/**
 @brief		Content management category.
 @details	Represents a category to manage content.
 @version 3.7.1
 */
@interface AWContentCategory : NSObject
{
    
}

/** @name Configuring a Content Category */
//@{

/** The identifier of the category. */
@property (nonatomic, assign) NSInteger identifier;

/** The identifier of the category's parent category. */
@property (nonatomic, assign) NSInteger parentIdentifier;

/** The display name of the category. */
@property (nonatomic, copy) NSString *name;

/** A boolean indicating whether or not the category has child categories. */
@property (nonatomic, assign) BOOL hasSubCategories;

//@}

@end
