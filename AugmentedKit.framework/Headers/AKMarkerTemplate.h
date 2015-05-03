//
//  ARMarkerTemplate.h
//  AugmentedKit
//
//  Created by Luteg
//  Copyright (c) 2012 Luteg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>


/**
 The base class of UI element of augmented markers. You must create your marker with subclassing AKMarkerTemplate. It holds your marker’s identity. AKMarkerTemplate used by AugmentedKit render engine on surface view.
 
 [![](http://augmentedkit.com/docs/images/marker-template.png)](http://augmentedkit.com/docs/images/marker-template.png)

 There is a bunch of examples on how to use custom marker templates in AugmentedKit SDK samples. You can see how to create, use and manipulate your marker views in the runtime.

 AKMarkerTemplate is subclassed from the UIView

 @see UIView
 */
@interface AKMarkerTemplate : UIView 

@end
