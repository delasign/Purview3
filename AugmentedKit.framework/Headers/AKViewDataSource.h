//
//  AKViewDataSource.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//

//System
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

//AugmentedKit
#import "AKLocation.h"

@class AKMarkerTemplate;
@class ARMarkerTemplate3D;
@class AKSurfaceView;
@class AKMarker;

/**
 AKViewDataSource interacts between AugmentedKit engine and your app to get markers data. 
 */
@protocol AKViewDataSource<NSObject>
@required
/**
 AugmentedKit engine asks your object when it starts to render a marker, 
 it also passes the marker information for each item and waits for a copy of AKMarkerTemplate instance.

 You must implement this method into your implementation file.

 Sample usage :
 
    -(AKMarkerTemplate*) viewforMarker:(AKMarker*) marker
    {
        //create and return a new markerview
        ARAnnotationView *markerView = [[ARAnnotationView alloc] initWithFrame:CGRectMake(0, 0, 230, 80)];
        markerView.title.text = marker.markerName;
        markerView.ObjectId = @"give any unique id";
        return markerView;
    }

 
 @param marker current rendering marker instance. Each marker must have unique ObjectId value. It can be NSString type
 
 @return AKMarkerTemplate instance.
 
*/
    -(AKMarkerTemplate*) viewforMarker:(AKMarker*) marker; 
@optional

/**
 This method called by AugmentedEngine during each frame rendering. 
 It works like a game engine. You can manipulate your view that has to be a subclass of AKMarkerTemplate.
 You can change your view’s transform property in here. You can also add/remove extra animations, layers etc.
 
 Sample usage :
 
    -(CATransform3D)RenderingMarker:(AKMarker*)marker andTransform:(CATransform3D)transform
    {
        //it's marker which container of the MarkerView 
        AKMarkerTemplate *markerView = [marker markerTemplateView]; 
        //do something on markerView  
        return transform;
    }

 see AugmentedKit SDK Samples Glossy Markers sample.
 
 @param marker current instance of rendering marker.
 @param transform CATransform3D property of current marker view. 
 @return CATransform3D you must return original or manuplated CATransform3D transform value. 
 */
    -(CATransform3D) RenderingMarker:(AKMarker*)marker andTransform:(CATransform3D) transform;
@end


