//
//  CutTheRopeScene.cpp
//  rock_box2d
//
//  Created by ChildhoodAndy on 14-5-2.
//
//

#include "CutTheRopeScene.h"
#include "TestNode.h"

Scene* CutTheRopeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = CutTheRopeScene::create();
    scene->addChild(layer);
    return scene;
}

bool CutTheRopeScene::init()
{
    if ( !Layer::init() ) {
        return false;
    }
    
    _testNode = TestNode::create();
    this->addChild(_testNode);
    _testNode->setPosition(Point(200, 200));
    
    
    return true;
}


