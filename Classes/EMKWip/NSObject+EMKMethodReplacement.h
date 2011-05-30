//
//  NSObject+EMKMethodReplacement.h
//  EMKPantry
//
//  Created by Benedict Cohen on 28/05/2011.
//  Copyright 2011 Benedict Cohen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "objc/runtime.h"

@interface NSObject (EMKMethodReplacement)

//These methods work fine when replacing methods implemented on a class or a superclass.
//They do not work if the method to be replaced is implemented in a category.
//This is due to the face that the order that categories are loaded and added to a class are not
//known at compile time.
//It would be possible to manage the order that methods are called once they've been loaded,
//providing that?????
+(void)EMK_replaceInstanceMethodForSelector:(SEL)selector withImplementation:(IMP)newImplementation;
+(IMP)EMK_instanceMethodForSelector:(SEL)selector replacedByImplementation:(IMP)laterImplementation;

+(void)EMK_replaceInstanceMethodForSelector:(SEL)selector withImplementationBlock:(void *(^)(id, SEL, ...))impBlock;


@end
