//
//  SPUDownloaderSession.h
//  Sparkle
//
//  Created by Deadpikle on 12/20/17.
//  Copyright © 2017 Sparkle Project. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
#import "SPUDownloader.h"
#import "SPUDownloaderProtocol.h"
#import "SUExport.h"

NS_CLASS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0)
SU_EXPORT @interface SPUDownloaderSession : SPUDownloader <SPUDownloaderProtocol>
@property (nonatomic, readwrite) NSURLSessionDownloadTask *download;
- (void)URLSession:(NSURLSession *)__unused session downloadTask:(NSURLSessionDownloadTask *)__unused downloadTask didFinishDownloadingToURL:(NSURL *)location;
-(NSString *)suggestedFilename;
-(BOOL)moveItemAtPath:(NSString *)fromPath toPath:(NSString *)toPath error:(NSError *)error;
- (void)startDownloadWithRequest:(SPUURLRequest *)request;
@end
