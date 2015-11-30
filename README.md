How to use
==========
First you should select External and IOS platforms and enable Client OAuth authorization using ok.ru app edit form. 
Also your should send request for LONG_ACCESS_TOKEN to [api-support](mailto:api-support@ok.ru) or you can simple not request for LONG_ACCESS_TOKEN permission during OAuth authorization.

Add *ok{appId}* schema to your app Info.plist file. For example *ok12345* if your app has appId *12345*. Then add *ok{appId}* and *okauth* to [LSApplicationQueriesSchemes](https://developer.apple.com/library/mac/documentation/General/Reference/InfoPlistKeyReference/Articles/LaunchServicesKeys.html#//apple_ref/doc/uid/TP40009250-SW14).
Don't forget add ok{appId}://authorize to allowed redirect urls for your application in ok.ru app profile. Also you should add next block to your Info.plist file.
```xml
 <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSAllowsArbitraryLoads</key>
        <true/>
    </dict>
```

Add OKSDK.h and OKSDK.m to your project. For example you can use git submodule.

Init your sdk with appId and appPublicKey in AppDelegate didFinishLaunchingWithOptions
```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [OKSDK initWithAppIdAndAppKey:[NSNumber numberWithUnsignedLongLong:12345] appKey:@"ABCABCABCABC"];
    return YES;
}
```

Add openUrl to AppDelegate openURL
```objective-c
-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    [OKSDK openUrl:url];
    return YES;
}
```

To understand how to interact with OKSDK please look at examples  [repository](https://github.com/apiok/ok-ios-sdk-examples)



