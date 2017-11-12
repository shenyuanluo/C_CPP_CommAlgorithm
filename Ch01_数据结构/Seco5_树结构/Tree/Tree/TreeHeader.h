//
//  TreeHeader.h
//  Tree
//
//  Created by shenyuanluo on 2017/11/11.
//  Copyright © 2017年 http://blog.shenyuanluo.com/ All rights reserved.
//

#ifndef TreeHeader_h
#define TreeHeader_h


/** 树操作返回值 */
typedef enum {
    RetError            = -1,           // 操作出错
    RetFailure          = 0,            // 操作失败
    RetSuccess          = 1,            // 操作成功
}RetValue;


/** 树结点类型 */
typedef struct {
    char key[15];                       // 学号
    char name[20];                      // 姓名
    int age;                            // 年龄
}NodeData;


#endif /* TreeHeader_h */
