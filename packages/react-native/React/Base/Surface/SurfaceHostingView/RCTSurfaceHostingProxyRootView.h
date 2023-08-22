/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <React/RCTBridgeModule.h>
#import <React/RCTRootView.h>

#import "RCTSurfaceHostingView.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This is a RCTRootView-compatible implementation of RCTSurfaceHostingView.
 * Use this class to replace all usages of RCTRootView in the app for easier migration
 * to RCTSurfaceHostingView.
 *
 * WARNING: In the future, RCTRootView will be deprecated in favor of RCTSurfaceHostingView.
 */
@interface RCTSurfaceHostingProxyRootView : RCTSurfaceHostingView

#pragma mark RCTRootView compatibility - keep these sync'ed with RCTRootView.h

@property (nonatomic, copy, readonly) NSString *moduleName;
@property (nonatomic, strong, readonly) RCTBridge *bridge;
@property (nonatomic, strong, readonly) RCTModuleRegistry *moduleRegistry;
@property (nonatomic, strong, readonly) id<RCTEventDispatcherProtocol> eventDispatcher;
@property (nonatomic, copy, readwrite) NSDictionary *appProperties;
@property (nonatomic, assign) RCTRootViewSizeFlexibility sizeFlexibility;
@property (nonatomic, weak) id<RCTRootViewDelegate> delegate;
@property (nonatomic, weak) UIViewController *reactViewController;
@property (nonatomic, strong, readonly) UIView *view;
@property (nonatomic, strong, readonly) UIView *contentView;
@property (nonatomic, strong) UIView *loadingView;
@property (nonatomic, assign) BOOL passThroughTouches;
@property (nonatomic, assign) NSTimeInterval loadingViewFadeDelay;
@property (nonatomic, assign) NSTimeInterval loadingViewFadeDuration;
@property (nonatomic, assign) CGSize minimumSize;

/**
 * Bridgeless mode initializer
 */
- (instancetype)initWithSurface:(id<RCTSurfaceProtocol>)surface
                sizeMeasureMode:(RCTSurfaceSizeMeasureMode)sizeMeasureMode
                 moduleRegistry:(RCTModuleRegistry *)moduleRegistry;

- (instancetype)initWithSurface:(id<RCTSurfaceProtocol>)surface;

- (void)cancelTouches;

@end

NS_ASSUME_NONNULL_END
