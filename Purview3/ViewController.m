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

@interface ViewController ()<GMBLPlaceManagerDelegate>

@property (nonatomic) GMBLPlaceManager *placeManager;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [Gimbal setAPIKey:@"c9154a3f-654e-4fe1-a7c7-f94c817996f8" options:nil];
    
    [Gimbal resetApplicationInstanceIdentifier];
    
    if ([GMBLPlaceManager isMonitoring]) {
        NSLog(@"*****");
    }

    
     [GMBLPlaceManager startMonitoring];
    
    self.placeManager = [GMBLPlaceManager new];
    self.placeManager.delegate = self;
    [GMBLPlaceManager startMonitoring];
}

@end
