//
//  QueueHeader.h
//  Queue
//
//  Created by shenyuanluo on 2017/11/10.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef QueueHeader_h
#define QueueHeader_h


/** 队列作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetFailure          = 0,            // 操作失败
    RetSuccess          = 1,            // 操作成功
}RetValue;


/** 队列结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;



#endif /* QueueHeader_h */
