//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//

#pragma once

#import <ConnectedDevicesRemoteSystemsCommanding/ConnectedDevicesRemoteSystemsCommanding.h>

@class LaunchUriProvider;

@protocol LaunchUriProviderDelegate
- (void)launchUriProvider:(LaunchUriProvider*)launchUriProvider didReceiveRequestForUri:(NSString*)uri;
@end

@interface LaunchUriProvider : NSObject <MCDLaunchUriProvider>
@property(nonatomic, weak) id<LaunchUriProviderDelegate> delegate;
- (instancetype)initWithDelegate:(id<LaunchUriProviderDelegate>)delegate;

- (void)onLaunchUriAsync:(nonnull NSString*)uri
                 options:(nullable MCDRemoteLauncherOptions*)options
              completion:(nonnull void (^)(BOOL, NSError* _Nullable))completionBlock;
@property(nonatomic, readonly, strong, nonnull) NSArray<NSString*>* supportedUriSchemes;

@end
