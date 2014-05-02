//
//  TestNode.h
//  rock_box2d
//
//  Created by ChildhoodAndy on 14-5-2.
//
//

#ifndef __rock_box2d__TestNode__
#define __rock_box2d__TestNode__

#include "cocos2d.h"

USING_NS_CC;
class TestNode:public Node
{
public:
    virtual bool init() override;
    ~TestNode();
    CREATE_FUNC(TestNode);
    
    virtual void draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated);
private:
    Vertex2F* _vertices;
    int _radius;
    int _numSegments;
};

#endif /* defined(__rock_box2d__TestNode__) */
