//
//  HZHViewController.m
//  hzhCommonDefine
//
//  Created by HZH on 16/8/9.
//  Copyright © 2016年 黄志宏. All rights reserved.
//

#import "HZHViewController.h"

@implementation HZHViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    //创建一个label
    HHnewLabel(Hzhlabel, KSCREEN_WIDTH/2.0-50, 100, 100, 40, [UIColor whiteColor], @"宏定义", 2, 12, self.view);
    HHViewBorderRadius(Hzhlabel, 5, 1, [UIColor redColor]);
    //创建一个button
    HHnewButton(Hzhbutton, KSCREEN_WIDTH/2.0 - 50, 150, 100, 40, [UIColor lightGrayColor], @"宏定义", 12, self.view);
    HHViewBorderRadius(Hzhbutton, 5, 1, [UIColor redColor]);
    //创建一个iamgeView
    HHnewImageView(HzhImage, KSCREEN_WIDTH/2.0 - 50, KSCREENH_HEIGHT/2.0+ 100, 100, 100, self.view);
    HzhImage.image = HHGetImage(@"test");
    //一个弹窗
    HHShowText(self.view, @"欢迎使用宏定义", 3);
}

@end
