//
//  HZHCommenDefineHeader.h
//  TestCollectionView
//
//  Created by HZH on 16/8/9.
//  Copyright © 2016年 黄志宏. All rights reserved.
//

#ifndef HZHCommenDefineHeader_h
#define HZHCommenDefineHeader_h
//----------------------ABOUT SCREEN & SIZE 屏幕&尺寸 ----------------------------
/**
 iPad Air {{0, 0}, {768, 1024}}
 iphone4s {{0, 0}, {320, 480}}     960*640
 iphone5 5s {{0, 0}, {320, 568}}      1136*640
 iphone6 6s {{0, 0}, {375, 667}}     1334*750
 iphone6Plus 6sPlus {{0, 0}, {414, 736}}  1920*1080
 Apple Watch 1.65inches(英寸) 320*640
 */

//1.获取屏幕宽度与高度
#define KSCREEN_WIDTH   [UIScreen mainScreen].bounds.size.width
#define KSCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height

#define KScreenTabBarH        49.0f
#define KScreenStatusBarH     20.0f
#define KNavigationBarH 44.0f

//需要横屏或者竖屏，获取屏幕宽度与高度
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上

#define SCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define SCREENH_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define SCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif


//2.获取通知中心
#define HHNotificationCenter [NSNotificationCenter defaultCenter]

//3.设置随机颜色
#define HHRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

//4.设置RGB颜色/设置RGBA颜色
#define HHRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define HHRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
// clear背景颜色
#define HHClearColor [UIColor clearColor]
// rgb颜色转换（16进制->10进制）
#define HHUIColorFrom0x16(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//5.自定义高效率的 NSLog
#ifdef DEBUG
#define HHLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define HHLog(...)
#endif

//6.弱引用/强引用
#define HHWeakSelf(type)  __weak typeof(type) weak##type = type;
#define HHStrongSelf(type)  __strong typeof(type) type = weak##type;

//7.设置 view 圆角和边框
#define HHViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

#define HHViewBorder(View, Width, Color)\
\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]];

#define HHViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];
//8.由角度转换弧度 由弧度转换角度
#define HHDegreesToRadian(x) (M_PI * (x) / 180.0)
#define HHRadianToDegrees(radian) (radian*180.0)/(M_PI)

//9.设置加载提示框（第三方框架：MB,参数分别为view,字符串,时间）
#define HHShowText(View,Str,f)  MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:View animated:YES];\
hud.mode = MBProgressHUDModeText;\
hud.label.text = Str;\
[hud hideAnimated:YES afterDelay:f];

//10.获取图片资源
#define HHGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

//11.获取当前语言
#define LRCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//12.使用 ARC 和 MRC
#if __has_feature(objc_arc)
// ARC
#else
// MRC
#endif

//13.判断当前的iPhone设备/系统版本
//判断是否为iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

//判断是否为iPad
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

// 判断是否为 iPhone 5SE
#define iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

// 判断是否为iPhone 6/6s
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

// 判断是否为iPhone 6Plus/6sPlus
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

//获取系统版本
#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))

/** 是否为iOS6 */
#define iOS6 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) ? YES : NO)

/** 是否为iOS7 */
#define iOS7 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) ? YES : NO)

/** 是否为iOS8 */
#define iOS8 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) ? YES : NO)

/** 是否为iOS9 */
#define iOS9 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) ? YES : NO)

//14.判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//15.沙盒目录文件
//获取temp
#define kPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//16.GCD 的宏定义
//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);
//17.数字转为字符串
#define HHintToStr(S)    [NSString stringWithFormat:@"%ld",S]
//18.字体大小定义
#define HHFONT(F) [UIFont systemFontOfSize:F]
//19.创建一个label 参数:Labelname(labelName) (L,T,W,H)frame ,TextStr (text),Location(1:left,2:center,3:right),SuperView(父视图);

#define HHnewLabel(Labelname,frameL,frameT,frameW,frameH,Color,TextStr,Location,fontsize,SuperView)     UILabel *Labelname = [[UILabel alloc]init];\
Labelname.frame = CGRectMake(frameL, frameT, frameW, frameH);\
Labelname.backgroundColor = Color;\
Labelname.text = TextStr; \
if (Location == 1) {Labelname.textAlignment = NSTextAlignmentLeft;}else if (Location == 2){Labelname.textAlignment = NSTextAlignmentCenter;}else if (Location == 3){Labelname.textAlignment = NSTextAlignmentRight;}\
Labelname.font = [UIFont systemFontOfSize:fontsize];\
[SuperView addSubview:Labelname];\
//20,创建一个button
#define HHnewButton(BtnName,frameL,frameT,frameW,frameH,Color,textStr,fontSize,superView)   UIButton *BtnName = [UIButton buttonWithType:(UIButtonTypeCustom)];\
BtnName.frame = CGRectMake(frameL, frameT, frameW, frameH);\
[BtnName setTitle:textStr forState:(UIControlStateNormal)];\
BtnName.backgroundColor = Color;\
BtnName.titleLabel.font = [UIFont systemFontOfSize:fontSize];\
[superView addSubview:BtnName];
//21.创建一个ImageView
#define HHnewImageView(ImgName,frameL,frameT,frameW,frameH,superView)  UIImageView *ImgName = [[UIImageView alloc]init];\
ImgName.frame = CGRectMake(frameL, frameT, frameW, frameH);\
[superView addSubview:ImgName];


#endif /* HZHCommenDefineHeader_h */
