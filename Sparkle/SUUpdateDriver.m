//
//  SUUpdateDriver.m
//  Sparkle
//
//  Created by Andy Matuschak on 5/7/08.
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#import "SUUpdateDriver.h"
#import "SUUpdaterPrivate.h"
#import "SUHost.h"
#import "SULog.h"
#import "SPUProxy.h"
NSString *const SUUpdateDriverFinishedNotification = @"SUUpdateDriverFinished";

@interface SUUpdateDriver ()

@property (weak) id<SUUpdaterPrivate> updater;
@property (copy) NSURL *appcastURL;
@property (getter=isInterruptible) BOOL interruptible;

@end

@implementation SUUpdateDriver

@synthesize updater;
@synthesize host;
@synthesize interruptible;
@synthesize finished;
@synthesize appcastURL;
@synthesize automaticallyInstallUpdates;
@synthesize proxy;
- (instancetype)initWithUpdater:(id<SUUpdaterPrivate>)anUpdater
{
    if ((self = [super init])) {
        self.updater = anUpdater;
    }
    return self;
}

- (NSString *)description { return [NSString stringWithFormat:@"%@ <%@>", [self class], [self.host bundlePath]]; }

- (void)checkForUpdatesAtURL:(NSURL *)URL host:(SUHost *)h proxy:(SUProxy)p
{
    self.appcastURL = URL;
    self.host = h;
    self.proxy = p;
}

- (void)abortUpdate
{
    [self setValue:@YES forKey:@"finished"];
    [[NSNotificationCenter defaultCenter] postNotificationName:SUUpdateDriverFinishedNotification object:self];
}

-(BOOL)resumeUpdateInteractively {
    return NO;
}

-(BOOL)downloadsAppcastInBackground {
    return YES;
}

-(BOOL)downloadsUpdatesInBackground {
    return NO;
}

- (void)showAlert:(NSAlert *)alert {
    // Only UI-based subclass shows the actual alert
    SULog(SULogLevelDefault, @"ALERT: %@\n%@", alert.messageText, alert.informativeText);
}

@end
