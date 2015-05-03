//
//  AKDeviceManager.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//


//System
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

//Sensor delegate
#import "AKViewSensorDelegate.h"

@class      AKLocation;
@protocol   AKViewSensorDelegate;

/**
 AKDeviceManager listens and evaluates the device’s sensor data. 
 It has ability to apply various filters and data corrections on the received sensor data to make them more accurate.
 
 It responsible to distribute sensor values to listeners that implements AKViewSensorDelegate and 
 attaches on AKDeviceManager trough addDelegate method.
 
 It has convenient methods to get more accurate device sensor data for AugmentedKit. 
 If you need to get sensor data in your apps you can use this class.
 
 @see AKViewSensorDelegate
 */

@interface AKDeviceManager : NSObject<UIAccelerometerDelegate, CLLocationManagerDelegate>

/******************************************
 @name initialization
 ******************************************/
/**
 Singleton instance of AKDeviceManager
 @return AKDeviceManager current AKDeviceManager instance
 */
+ (AKDeviceManager *)sharedInstance;


/******************************************
 @name Sensors
 ******************************************/
/**
 Original trueHeading value of the CLHeading value
 @return CLLocationDirection trueHeading value
 */
- (CLLocationDirection)trueHeading;

/**
 Corrected heading data that is computed and fixed with accelerometer data.
 @return CLLocationDirection corrected heading data
 */
- (CLLocationDirection)correctedHeading;

/**
 ForwardTilt forward tilt position value of the device position
 @return UIAccelerationValue forward tilt position of the device
 */
- (UIAccelerationValue)forwardTilt;

/**
 Sideways tilt value of the device position
 @return UIAccelerationValue sideways tilt of the device
 */
- (UIAccelerationValue)sidewaysTilt;


/**
 Returns device’s current location with AKLocation object. It’s similar to CLLocation of CoreLocation framework.
 @return AKLocation current corrdinate
 @see AKLocation
 */
- (AKLocation *)getCurrentCoordinate;


/**
 Returns current device orientation with UIDeviceOrientation type
 @return UIDeviceOrientation current device orientation
 */
- (UIDeviceOrientation) deviceOrientation;


/******************************************
 @name Actions
 ******************************************/
/**
 Starts updating combined device sensors (Accelerometer, Compass and GPS)
 @see AKDeviceManager
 */

- (void)startUpdating;


/**
 Stop updating device sensors
 @see AKDeviceManager
 */
- (void)stopUpdating;


/******************************************
 @name Delegation
 ******************************************/
/**
 AKDeviceManager uses Multicast delegate structure to distribute sensor events to each attached objects in the same time.
 You just need to implement AKViewSensorDelegate protocol on any object to get device sensor data.
 
 add an object on AKDeviceManager multicast delegate chain
 @param delegate any object which needs to be implement AKViewSensorDelegate protocol
 */
- (void)addDelegate:(id)delegate;

/**
 Removes given object from delegate chain
 @param delegate any object that needs to remove AKDeviceManager delegate chain 
 */
- (void)removeDelegate:(id)delegate;

@end


