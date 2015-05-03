//
//  AKSurfaceView.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//

//System
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

//AugmentedKit
#import "AKDeviceManager.h"
#import "AKViewDelegate.h"
#import "AKMarkerTemplate.h"


/**
 With this enum you can be able to choose annotation order matrix on surface view.
 
 - AKMarkerDisplayStyle2D each markers are ordered in 2D matrix (x, y) on surface.
    markers are ordered in y position according to their distance.
 
 - AKMarkerDisplayStyle3D each markers are ordered in 3D matrix (x, y, z) position on surface.
    markers are ordered in z,y position according to their distance.
 */
typedef enum {
    // 2D matrix renderer
    AKMarkerDisplayStyle2D = 0,
    // 3D matrix renderer
    AKMarkerDisplayStyle3D = 1
} AKMarkerDisplayStyle ;


typedef enum {
    // By using the difference between the farest marker and the closest marker, real depth is defined by the value of @maxmarkerdistance
    AKMarkerDistanceTypeRealDepth           = 0,
    // @maxmarkerdistance / The distance between markers calculated by the number of markers
    AKMarkerDistanceTypeMarkerAmount        = 1,
    // The distance between each marker is distributed equally
    // The distance is defined by @maxmarkerdistance (ex: @maxmarkerdistance = 30 m)
    AKMarkerDistanceTypeWithMaxDistance     = 3,
    // if AKMarkerDistanceTypeDefault is used, @maxmarkerdistance is avoided.
    AKMarkerDistanceTypeDefault             = 4
    
}AKMarkerDistanceType;


/**
 Touch directions enum types
 */
typedef NS_OPTIONS(NSUInteger, TOUCH_SWIPE_DIRECTIONS) {
    TOUCH_SWIPE_DIRECTIONS_NONE           = 0,
    TOUCH_SWIPE_DIRECTIONS_HORIZONTAL     = 1 << 0,
    TOUCH_SWIPE_DIRECTIONS_VERTICAL       = 1 << 1
};

@class AKMarker;
@protocol AKViewDelegate;
@protocol AKViewSensorDelegate;
@protocol AVCaptureVideoDataOutputSampleBufferDelegate;


/**
 Reffers to AugmentedKitAPIKey on main app bundle, which you can obtain it from AugmentedKit official web site.
 If you get a new license key, please visit : http://www.augmentedkit.com/license/buy
 */
FOUNDATION_EXPORT NSString *const kAugmentedKitAPIKey;

/**
AKSurfaceView instance provides functionality to interact with the user and AugmentedKit’s AR Engine. It may contain Markers, MarkerViews, Radar and also overlays on its surface to make augmented reality environment on the device. Many things are orchestrated on this object by AugmentedKit. You can use AKViewDelegate and AKViewDataSource protocols to allow easy interactions between your objects and AugmentedKit AR Engine.
 
 Sample usage:
 
    AKSurfaceView *surfaceView = [[AKSurfaceView alloc] initWithFrame:self.view.bounds];
    surfaceView.center = self.view.center;
    [surfaceView addDelegate:self];
    [self.view addSubview:surfaceView];
    [surfaceView start];
*/

@interface AKSurfaceView : UIView <AKViewDelegate, AKViewSensorDelegate, AVCaptureVideoDataOutputSampleBufferDelegate>

/******************************************
 @name Delegation
 ******************************************/
/** The receiver’s AKViewDelegate */
@property (nonatomic, assign) id<AKViewDelegate> delegate;


/******************************************
 @name Markers
 ******************************************/
/** 
 Markers works smilar to MKAnnotation of MapKit framework they only contains location data that longtitude, lattitude also can be altitude.
 @see AKMarker
 */

/**
 Add location refference Marker into the marker queue of AKSurfaceView
 @param marker marker object as location information of the marker
 */
- (void)addmarker:(AKMarker *) marker;




/** 
 Removes the given AKMarker object instance from the marker queue of AKSurfaceView
 @param marker target marker object
 */
- (void)removemarker:(AKMarker *)marker;



/**
 Finds the given ARMarker object in markers queue
 
 @param markerId value of target marker object
 @return AKMarker AKMarker instance that added before through addMarker
 @see addmarker:
 */
- (AKMarker *)findMarker:(NSString *)markerId;




/******************************************
 @name Controls
 ******************************************/

/** 
 Clear existing markers queue
 */
- (void)clearmarkers;


/**
 Pauses the current augmented view engine.
 When your application goes to the background AugmentedKit automatically pause current AR.
 So, you do not need to make any changes if your application provides multi-task functionality
 */
- (void)pauseRunning;


/** 
 Resumes the current augmented view engine. 
 Resumes augmented engine when your application come to front from background AugmentedKit automatically resume the current engine..
 */
- (void)resumeRunning;


/** 
 Starts the AugmentedKit’s AR enviroment engine
 */
- (void)startRunning;


/** 
 Stops the AugmentedKit’s enviroment engine
 */
- (void)stopRunning;


/**
 AugmentedKit version information
 @return version version and build date of AugmentedKit
 */
- (NSString *)version;

/******************************************
 @name Properties
 ******************************************/

/** 
 List of living markers of the AKSurfaceView marker chain.
 */
@property (nonatomic, readonly) NSArray *markerList;

/** 
 Padding between markers can be increase via this property.
 It can be positive or negative according to your markers layout. 
 Please see Image Markers sample in AugmentedKit SDK Samples.
 
 [![](http://augmentedkit.com/docs/images/marker-padding.png)](http://augmentedkit.com/docs/images/marker-padding.png)

 */
@property (nonatomic, assign) float markerPadding;


/** 
Markers can arrange according to this value on 2D or 3D matrix space, if you need to order each marker on (z) deep you can set as AKMarkerDisplayStyle3D, otherwise this value will be AKMarkerDisplayStyle2D as default.

 [![](http://augmentedkit.com/docs/images/marker-rendering.png)](http://augmentedkit.com/docs/images/marker-rendering.png)
 
 Note : AKEngine sorts each marker according to their distance value.
 
    surfaceView.RenderStyle = AKMarkerDisplayStyle2D | AKMarkerDisplayStyle2D;
 
 @see AKMarkerDisplayStyle
*/
@property (nonatomic, assign) AKMarkerDisplayStyle RenderStyle;


/**
 AugmentedKit considers markerDistanceType value during rendering marker depth.
 This property can be use only in AKMarkerDisplayStyle = AKMarkerDisplayStyle3D mode. 
 See @AKMarkerDisplayStyle to get more detail about options.
 */
@property (nonatomic, assign) AKMarkerDistanceType markerDistanceType;


/**
 This value can be use with markerDistanceType. see @markerDistanceType.
 Default is 150m.
 
 */
@property (nonatomic, assign) float maxMarkerDistance;

/** 
 Show/Hide AKRadar view on the AKSurfaceView. default value is YES.
 
 [![](http://augmentedkit.com/docs/images/radar-view.png)](http://augmentedkit.com/docs/images/radar-view.png)
 
 
 */
@property (nonatomic, assign) BOOL showRadar;


/**
 The number of frames that must pass before the AugmentedKit's rendering engine notifies the target again.
 
 The default value is 1, which results in your application being notified at the refresh rate of the display. 
 If the value is set to a value larger than 1, the AugmentedKit's rendering engine notifies your application at a fraction of the native refresh rate.
 For example, setting the interval to 2 causes the rendering engine to fire every other frame, providing half the frame rate.
 
 You should set this property value before call AKSurfaceView startRunning function. Pausing and resuming will not be effect running instance.
 Setting this value to less than 1 results in undefined behavior and is a programmer error.
 
 If you set 2 you will get around //30fps 60/n = fps
 */
@property(nonatomic) NSInteger frameInterval;

/**
 Configure swipe directions on AKSurfaceView. By default, AKSurfaceView accepts vertical and horizontal
 swipe to see markers around you fast way. You can manage touch directions.
 
 swipeDirections has by default  (TOUCH_SWIPE_DIRECTIONS_HORIZONTAL | TOUCH_SWIPE_DIRECTIONS_VERTICAL)
 */
@property (nonatomic) TOUCH_SWIPE_DIRECTIONS swipeDirections;


/** 
 Working state of the AugmentedKit engine.
 */
@property (nonatomic, readonly) BOOL running;

/**
 Pauses the state of the AugmentedKit engine.
 */
@property (nonatomic, readonly) BOOL paused;

/** ....*/
@property (nonatomic)     float altitudeScale;

/**
 Default is NO.
 If you set considerAltitude to YES, AugmentedKit will consider altitude value of the retrieved geo location value 
 including user location. You must provide altitude value for each AKMarker if you have. 
 Otherwise you might get unexpected marker orders.
 
 */
@property (nonatomic)     BOOL considerAltitude;

/**
 Use this value in development only. The default value is NO.
 */
@property (nonatomic)     BOOL showFPS;


/**
 If you are using altitude based location markers, you might need to simulate altitude value of the user location.
 You can use this value during development.
 */
@property (nonatomic)     float baseAltitude;

/**
 Vertical start position of the marker view.
 You can set vertical start positions of your marker views according to your app style.
 
 [![](http://augmentedkit.com/docs/images/vertical-start.png)](http://augmentedkit.com/docs/images/vertical-start.png)

 Default value is AKSurfaceView screen height size / 2
 
 */
@property (nonatomic)     float verticalStartPosition;


/**
 AugmentedKit renders augmented environment and it puts your markers into 2D or 3D matrix. 
 Another great thing of AugmentedKit is you can touch and scroll markers on UI without turning around. 
 When you move the device each markers go back to their original positions.
 
 With maximumVerticalScroll value you can block max y deep. Default value is AKSurfaceView screen height
 
 [![](http://augmentedkit.com/docs/images/vertical-scroll.png)](http://augmentedkit.com/docs/images/vertical-scroll.png)

 
 */
@property (nonatomic)     float maximumVerticalScroll;

/**
 Blocks min y deep. 
 Default value is AKSurfaceView screen -height
 */
@property (nonatomic)     float minimumVerticalScroll;

/**
 You can change AugmentedKit marker render range in meters.
 If you change this value AugmentedKit will consider your range in runtime and it will renders only in range markers. 
 
 Default is 0 means it renders each marker without range filter that you’ve given.
 */
@property (nonatomic)     float defaultRange;


/**
 Normally, AugmentedKit changes radar position according to device orientation if you are creating an augmented games 
 or related apps. You might need to close automatic positioning feature of radar. 
 You can set manually CGPoint of radar position with this property
 
 Default is CGPointZero
 */
@property (nonatomic)     CGPoint radarPosition;


@end
