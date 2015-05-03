//
//  ViewController.m
//  Purview3
//
//  Created by Kevin Taniguchi on 5/2/15.
//  Copyright (c) 2015 100x. All rights reserved.
//

#import "ViewController.h" 
#import <Gimbal/Gimbal.h>
#import <AugmentedKit/AugmentedKit.h>

// c9154a3f-654e-4fe1-a7c7-f94c817996f8

@interface ViewController ()<GMBLPlaceManagerDelegate, GMBLCommunicationManagerDelegate, AKViewDelegate>

@property (nonatomic, strong) GMBLPlaceManager *placeManager;
@property (nonatomic, strong) GMBLCommunicationManager *communicationManager;
@property (nonatomic, strong) AKSurfaceView *surfaceView;

@end

@implementation ViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    
//     GMBLCommunication *communication = [GMBLCommunicationManager communicationForLocalNotification:notification];
    
    self.surfaceView = [[AKSurfaceView alloc] initWithFrame:self.view.bounds];
    self.surfaceView.center = self.view.center;
    //We prefer to open 2D mode
    self.surfaceView.RenderStyle = AKMarkerDisplayStyle2D;
    //surfaceView.RenderStyle = AKMarkerDisplayStyle3D;
    
    //Do not consider altitude for marker locations
    self.surfaceView.considerAltitude = NO;
    
    //Assign this contoller to AKSurfaceView's delegate
    self.surfaceView.delegate = self;
    
    // Change marker padding
    // see http://www.augmentedkit.com/docs/Classes/AKSurfaceView.html#//api/name/markerPadding
    self.surfaceView.markerPadding = 70;
    
    //Finally add surface view onto controller's view
    [self.view addSubview:self.surfaceView];
    
    [Gimbal setAPIKey:@"c9154a3f-654e-4fe1-a7c7-f94c817996f8" options:nil];
    
    [Gimbal resetApplicationInstanceIdentifier];
    
    if ([GMBLPlaceManager isMonitoring]) {
        NSLog(@"*****");
    }

    
     [GMBLPlaceManager startMonitoring];
    
    self.placeManager = [GMBLPlaceManager new];
    self.placeManager.delegate = self;
    [GMBLPlaceManager startMonitoring];
    
    
    [GMBLCommunicationManager startReceivingCommunications];
    
    self.communicationManager = [GMBLCommunicationManager new];
    self.communicationManager.delegate = self;
    [GMBLCommunicationManager startReceivingCommunications];
}

- (void)placeManager:(GMBLPlaceManager *)manager didBeginVisit:(GMBLVisit *)visit {
    NSLog(@"(****** VIUST %@", visit);
}

- (void)placeManager:(GMBLPlaceManager *)manager didEndVisit:(GMBLVisit *)visit {
    NSLog(@"didendvisut %@", visit);
}

- (void)placeManager:(GMBLPlaceManager *)manager didReceiveBeaconSighting:(GMBLBeaconSighting *)sighting forVisits:(NSArray *)visits {
    NSLog(@"SIGINTING %@", sighting);
    NSLog(@"11111 visits %@", visits);
}


@end
