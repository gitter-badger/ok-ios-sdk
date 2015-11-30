typedef void (^OKResultBlock)(id data);
typedef void (^OKErrorBlock)(NSError *error);
#define OKColor [UIColor colorWithRed:0xED/255.f green:0x81/255.f blue:0x2B/255.f alpha:1.f]

FOUNDATION_EXPORT  NSString * const OK_API_ERROR_CODE_DOMAIN;
FOUNDATION_EXPORT  NSString * const OK_SDK_ERROR_CODE_DOMAIN;

typedef NS_ENUM(NSInteger, OKSDKErrorCode) {
    OKSDKErrorCodeNotIntialized = 1,
    OKSDKErrorCodeNoSchemaRegistered = 2,
    OKSDKErrorCodeBadOAuthRedirectUri = 3,
    OKSDKErrorCodeBadApiReponse = 4,
    OKSDKErrorCodeOAuthError = 5,
    OKSDKErrorCodeUserConfirmationDialogAlreadyInProgress = 6,
    OKSDKErrorCodeNotAuthorized = 7,
    OKSDKErrorCodeCancelledByUser = 8
};

@interface OKSDKInitSettings: NSObject
@property (nonatomic, assign) NSString *appId;
@property (nonatomic, assign) NSString *appKey;
@property (nonatomic, assign) UIView *webViewParent;
@property (nonatomic, assign) UIViewController *webViewControlllerParent;
@end

@interface OKSDK : NSObject

+(void)initWithSettings: (OKSDKInitSettings *) settings;

+(void)authorizeWithPermissions:(NSArray *)permissions success:(OKResultBlock)successBlock error:(OKErrorBlock) errorBlock;

+(void)invokeMethod:(NSString *)method arguments:(NSDictionary *)arguments success:(OKResultBlock)successBlock error:(OKErrorBlock) errorBlock;

+(void)invokeSdkMethod:(NSString *)method arguments:(NSDictionary *)arguments success:(OKResultBlock)successBlock error:(OKErrorBlock) errorBlock;

+(void)sdkInit:(OKResultBlock)successBlock error:(OKErrorBlock) errorBlock;

+(void)openUrl:(NSURL *)url;

+(void)showWidget:(NSString *)command arguments:(NSDictionary *) arguments options:(NSDictionary *)options success:(OKResultBlock)successBlock error:(OKErrorBlock) errorBlock;

+(void)shutdown;

+(void)clearAuth;

@end