//
//  SinglyFriendModel.m
//  SinglySDK
//
//  Created by Thomas Muldowney on 9/25/12.
//  Copyright (c) 2012 Singly. All rights reserved.
//

#import "SinglyFriendModel.h"
#import <SinglySDK/SinglySession.h>
#import <SinglySDK/SinglyAPIRequest.h>

@interface SinglyFriendModel () {
    SinglySession* _session;
    NSArray* _services;
}
@end

@implementation SinglyFriendModel

-(id)initWithSession:(SinglySession *)session;
{
    self = [super init];
    if (self) {
        _session = session;
    }
    return self;
}

-(id)initWithSession:(SinglySession *)session forService:(NSArray *)services;
{
    self = [super init];
    if (self) {
        _session = session;
        _services = services;
    }
    return self;
}

-(void)fetchDataWithCompletionHandler:(DataReadyBlock)completionHandler;
{
    [_session requestAPI:[SinglyAPIRequest apiRequestForEndpoint:@"types/contacts" withParameters:@{@"limit": @"500"}] withCompletionHandler:^(NSError *error, id json) {
        // Get out of here on system or remote errors
        if (error || [json objectForKey:@"error"]) {
            NSError* finalError = error ? error : [NSError errorWithDomain:@"SinglySDK" code:100 userInfo:@{NSLocalizedDescriptionKey:[json objectForKey:@"error"]}];
            return completionHandler(finalError);
        }
        
        // Do our processing via gcd
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            NSArray* contacts = (NSArray*)json;
            NSLog(@"Got %d contacts", contacts.count);
            for (NSDictionary* contact in contacts) {
                NSDictionary* oembed = [contact objectForKey:@"oembed"];
                if (!oembed || ![oembed objectForKey:@"title"]){
                    NSLog(@"Skipped for no title or oembed");
                    continue;
                }
            }
        });
        
    }];
}

@end