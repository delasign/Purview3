//
//  AKViewSensorDelegate.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//


//System
#import <Foundation/Foundation.h>

@class AKLocation;

/**
 AKViewSensorDelegate notifies the app about device sensors. AugmentedKit is already using this
 delegate to get device sensor data internally.
 
 The delegate also gives you filtered and corrected sensor data. As many people know that sometimes,
 device sensors give data from their cache So, you will be need to check and fix this sensor information to
 get accurate data.
 
 If you use AKDeviceManager with AKViewSensorDelegate you will not need to implement many complex
 corrections and check algorithms.
 */

@protocol AKViewSensorDelegate <NSObject>
@optional


/**
 Returns accelerometer data from the device sensor with filtered values. Normally you might get incorrect
 values from accelerometer sensor on device. So, you need to filter and check these values correct or not
 with many algorithms. ARDeviceManager can do the all of them for you to make things up.
 
 @param oldOrientation previous orientation of the device
 @param newOrientation new orientation of the device
 @see UIDeviceOrientation
 */
- (void)didDeviceOrientationChanged:(UIDeviceOrientation)oldOrientation
                  andNewOrientation:(UIDeviceOrientation) newOrientation;


/**
 Returns accelerometer data from the device sensor with filtered values. Normally you might get incorrect
 values from accelerometer sensor on device. So, you need to filter and check these values correct or not
 with many algorithms. ARDeviceManager can do all of this for you to make things up.
 
 @param x x value of UIAcceleration object
 @param y y value of UIAcceleration object
 @param z z value of UIAcceleration object
 @param forwardTilt forward or backward tilt value of the device position
 @param sidewaysTilt sideways tilt value of the device position
 */
- (void)didAccelerometerChanged:(float)x
                           andY:(float)y
                           andZ:(float)z
                 andforwardTilt:(float)forwardTilt
                andSidewaysTilt:(float)sidewaysTilt;


/** 
 Returns filtered compass data. ARDeviceManager applies some complex filters
 when it gets compass data from the device sensors. It applies some fixes with Accelerometer values.
 
 @param x x value of CLHeading object
 @param y y value of CLHeading object
 @param z z value of CLHeading object
 @param trueheading original trueHeading value of the CLHeading
 @param magneticHeading original magneticHeading value of the CLHeading
 @param correctHeading heading data that coputed and fixed with accelerometer data..
 */
- (void)didHeadingChanged:(float)x
                     andY:(float)y
                     andZ:(float)z
           andTrueHeading:(float)trueheading
       andMagneticHeading:(float)magneticHeading
        andCorrectHeading:(float)correctHeading;


/**
 Returns device current location with AKLocation object.
 @param currentLocation an instance pointer of AKLocation object.
 @see AKLocation
 */
- (void)didLocationChanged:(AKLocation *)currentLocation;


/**
 When an error occurred in AKDeviceManager, you get details and reason via this callback.
 AKDeviceManager will be stop when you get didFailWithError callback.
 @param error pointer of the error container.
 */
- (void)didFailWithError:(NSError *)error;

@end
