//
//  AKMarker.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//


//System
#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

#import "AKLocation.h"

@class AKMarkerTemplate;

/**
 AKMarker is the virtual pointer of the location in the AugmentedKit
 It has own location and marker view and it holds location coordinate and
 UI element reference together to make things up on AKSurfaceView.
 */

@interface AKMarker : NSObject
    
/**
 (Optional) Order of the marker in all markers in the current rendering engine. 
 The value may change by AugmentedKit render engine.
 
 */
@property (nonatomic, assign) int orderId;

/** 
 Index of the marker on assigned markers 
 */
@property (nonatomic, assign) NSUInteger index;


/** 
 Distance between the marker object and the user’s current location
 */
@property (nonatomic, assign, readonly) float distance;

/** 
 Marker selected. 
 You can set this value in runtime. When you change this value
 you might need to check marker selected in RenderingMarker method of AKSurfaceView.
 
 @see RenderingMarker
 */
@property (nonatomic, assign)  BOOL selected;


/** 
 Coordinates of the marker that returns AKLocation instace
 @see AKLocation
 */
@property (nonatomic,readonly) AKLocation *coordinate;

/** 
 Name of the Marker 
 */
@property (nonatomic,readonly) NSString *markerName;

/** 
 Unique identifier key for marker aka marker Id
 You can use this property to identify your markers.
 
 */
@property (nonatomic,readonly) NSString* markerId;

/** 
 Template of the marker that must be subclassed from AKMarkerTemplate
 @see AKMarkerTemplate
 */
@property (nonatomic,readonly)       AKMarkerTemplate* markerTemplateView;


/**
 Initialize a new AKMarker
 @param name name of the marker
 @param Id unique identifier key for marker aka marker Id
 @param location of the marker with AKLocation type.
 @see AKLocation
 */
-(id) initWithInfo:(NSString *)name
             andId:(NSString *)Id
     andCoordinate:(AKLocation *)coord;

/**
 Angle of marker according to the user’s location.
 @return float angle value in meters
 */
-(float) angleOfMarker;

/**
 (Optional) You might need to evaluate marker data before give them to AKSurfaceView.
 AKSurfaceView if it is already using this function before start of rendering markers.
 
 @return NSError error detail about marker validation
 */
- (NSError *) validate;
@end
