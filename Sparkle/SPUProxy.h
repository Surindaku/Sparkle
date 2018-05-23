//
//  SPUProxy.h
//  Sparkle
//
//  Created by Mikhail Filimonov on 19/04/2018.
//  Copyright © 2018 Sparkle Project. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
NS_ASSUME_NONNULL_BEGIN

typedef struct {
    __unsafe_unretained NSString *host;
    __unsafe_unretained NSString *port;
    __unsafe_unretained NSString * _Nullable user;
    __unsafe_unretained NSString * _Nullable pass;
    BOOL hasProxy;
} SUProxy;



NS_ASSUME_NONNULL_END
