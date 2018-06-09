//
//  SPUDownloaderProtocol.h
//  PersistentDownloader
//
//  Created by Mayur Pawashe on 4/1/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
#import "SPUProxy.h"

NS_ASSUME_NONNULL_BEGIN
@class SPUProxy;
@class SPUURLRequest;

// The protocol that this service will vend as its API. This header file will also need to be visible to the process hosting the service.
@protocol SPUDownloaderProtocol

- (void)startPersistentDownloadWithRequest:(SPUURLRequest *)request bundleIdentifier:(NSString *)bundleIdentifier desiredFilename:(NSString *)desiredFilename proxy:(SUProxy)proxy;

- (void)startTemporaryDownloadWithRequest:(SPUURLRequest *)request proxy:(SUProxy)proxy;

- (void)downloadDidFinish;

- (void)cleanup;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
