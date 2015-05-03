//
//  AKLocation.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//


//System
#import <CoreLocation/CoreLocation.h>

/**
 AKLocation object contains coordinates of the location. 
 It also provides convenient methods of location and calculation formulas.
 */
@interface AKLocation : NSObject {
    float Latitude;
    float Longitude;
    float Altitude;
}

/**
 Type used to represent a latitude coordinate in degrees under the WGS 84 reference frame. 
 The degree can be positive (North and East) or negative (South and West).
 */
@property (nonatomic, assign) float Latitude;

/**
 Type used to represent a Longitude coordinate in degrees under the WGS 84 reference
 frame. The degree can be positive (North and East) or negative (South and West).
 */
@property (nonatomic, assign) float Longitude;

/**  
 Returns the altitude of the location. Can be positive (above sea level) or negative (below sea level). 
 You may need to use considerAltitude functionality of AKSurfaceView to make more accurate Augmented Environment
 
 */
@property (nonatomic, assign) float Altitude;


/**
 Init AKLocation object with CLLocationCoordinate2D struct.
 @param location location value that type of CLLocationCoordinate2D
 @return id AKLocation instance
 @see CLLocationCoordinate2D
 */
- (id) initWithLocation:(CLLocationCoordinate2D)location;

/**
 Init AKLocation object with primitive values.
 @param latitude latitude value of given location
 @param longitude longitude value of given location
 @param altitude altitude value of given location
 @return id AKLocation instance
 */
- (id) initWithLocation:(float)latitude
           andlongitude:(float)longitude
            andaltitude:(float)altitude;


/**
 Get analytical angle between two location.
 @param location1 location value that type of AKLocation
 @param location2 location value that type of AKLocation
 @return analytical angle value between two locations in meters
 */
+ (double) getAnalyticalAngle:(AKLocation *)location1
                 andlocation2:(AKLocation *)location2;


/**
 Get angle between two locations.
 @param location1 location value that type of AKLocation
 @param location2 location value that type of AKLocation
 @return angle value between two location in meters
 */
+ (double) getAngle:(AKLocation *)location1
       andlocation2:(AKLocation *)location2;


/**
 Calculates the distance between given location1 and location2 values.
 This method uses Haversine formula to get distance between two location
 @see http://en.wikipedia.org/wiki/Haversine_formula
 
 
 @param location1 location value that type of AKLocation
 @param location2 location value that type of AKLocation
 @return float distance result in meter
 @see AKLocation
 */
+ (float) getDistance:(AKLocation *)location1
    andSecondLocation:(AKLocation *)location2;


/**
 Calculates the distance between given location1 and location2 values.
 
 @param location1 location value that type of CLLocationCoordinate2D
 @param location2 location value that type of CLLocationCoordinate2D
 @return float distance result in meter
 @see CLLocationCoordinate2D
 */
+ (float) getDistanceWithCLLocation:(CLLocationCoordinate2D)location1
                  andSecondLocation:(CLLocationCoordinate2D)location2;



/**
 Compares two AKLocation object.
 @param location1 location value that type of AKLocation
 @param location2 location value that type of AKLocation
 @return BOOL comparision result
 @see AKLocation
 */
+ (BOOL) isEqual:(AKLocation *)location1 andSecondLocation:(AKLocation *) location2;

@end
