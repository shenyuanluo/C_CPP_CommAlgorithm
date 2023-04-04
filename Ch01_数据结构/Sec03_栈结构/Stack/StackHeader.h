//
//  StackHeader.h
//  Stack
//
//  Created by shenyuanluo on 2017/11/9.
//  Copyright © 2017年 shenyuanluo. All rights reserved.
//

#ifndef StackHeader_h
#define StackHeader_h


/** 栈作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetFailure          = 0,            // 操作失败
    RetSuccess          = 1,            // 操作成功
}RetValue;


/** 栈结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


#endif /* StackHeader_h */
