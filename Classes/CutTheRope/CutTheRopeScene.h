//
//  CutTheRopeScene.h
//  rock_box2d
//
//  Created by ChildhoodAndy on 14-5-2.
//
//

#ifndef __rock_box2d__CutTheRopeScene__
#define __rock_box2d__CutTheRopeScene__

#include "cocos2d.h"

USING_NS_CC;
class TestNode;
class CutTheRopeScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(CutTheRopeScene);

    TestNode* _testNode;
};

#endif /* defined(__rock_box2d__CutTheRopeScene__) */
