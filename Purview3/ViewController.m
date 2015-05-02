//
//  ViewController.m
//  Purview3
//
//  Created by Kevin Taniguchi on 5/2/15.
//  Copyright (c) 2015 100x. All rights reserved.
//

#import "ViewController.h" 
#import <Gimbal/Gimbal.h>


// c9154a3f-654e-4fe1-a7c7-f94c817996f8

@interface ViewController ()<GMBLPlaceManagerDelegate, GMBLCommunicationManagerDelegate>

@property (nonatomic) GMBLPlaceManager *placeManager;
@property (nonatomic) GMBLCommunicationManager *communicationManager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//     GMBLCommunication *communication = [GMBLCommunicationManager communicationForLocalNotification:notification];
    
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
