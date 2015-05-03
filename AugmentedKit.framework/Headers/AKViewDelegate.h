//
//  AKViewDelegate.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//

//System
#import <Foundation/Foundation.h>

@class AKSurfaceView;
@protocol AKViewDataSource;


/**
 AKSurfaceView sends its events via this protocol. With these events you can arrange your environment.
 */
@protocol AKViewDelegate<AKViewDataSource>

@optional

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/**
 AugmentedKit engine will start
 @param engineView current engine instance */
- (void) engineWillStart:(AKSurfaceView *)engineView;

/**
 AugmentedKit engine started to work
 @param engineView current engine instance */
- (void) engineDidStarted:(AKSurfaceView *)engineView;

/**
 AugmentedKit engine will stop
 @param engineView current engine instance */
- (void) engineWillStop:(AKSurfaceView *)engineView;

/**
 AugmentedKit engine stopped
 @param engineView current engine instance */
- (void) engineDidStopped:(AKSurfaceView *)engineView;
    
/**
 When an error ocurres in AugmentedKit engine, you get details and reason via this callback.
 AugmentedKit will stop when you get didFailWithError.
 @param error pointer of the error container.
 */
- (void)didFailWithError:(NSError *)error;

/**
 Sometimes AugmentedKit gives you warnings about markers or runtime. 
 You will get detailed information via didFailWithWarning. AugmentedKit will not stop when you get this callback.
 */
- (void)didFailWithWarning:(NSError *)error;

@end