//  Author: Chris Campbell - www.iforce2d.net
//  -----------------------------------------
//
//  only for this demo project, you can remove this in your own app
//

#include "ExamplesMenuLayer.h"

#include "BasicRUBELayer.h"
#include "RUBELayer.h"
#include "DestroyBodyLayer.h"
#include "PinballRUBELayer.h"
#include "PlanetCuteRUBELayer.h"
#include "MenuScreenRUBELayer.h"
#include "UIControlsRUBELayer.h"

using namespace cocos2d;

Scene* ExamplesMenuLayer::createScene()
{
    Scene *scene = Scene::create();
    auto layer = ExamplesMenuLayer::create();
    scene->addChild(layer);
    return scene;
}

bool ExamplesMenuLayer::init()
{
	if ( CCLayer::init() ) {
        
        MenuItemFont* basicItem = MenuItemFont::create("Basic load", CC_CALLBACK_0(ExamplesMenuLayer::loadBasic, this));
        MenuItemFont* imagesItem = MenuItemFont::create("Images load", CC_CALLBACK_0(ExamplesMenuLayer::loadImages, this));
        MenuItemFont* destroyItem = MenuItemFont::create("Destroy bodies", CC_CALLBACK_0(ExamplesMenuLayer::loadDestroy, this));
        MenuItemFont* pinballItem = MenuItemFont::create("Pinball demo", CC_CALLBACK_0(ExamplesMenuLayer::loadPinball, this));
        MenuItemFont* planetCuteItem = MenuItemFont::create("PlanetCute demo", CC_CALLBACK_0(ExamplesMenuLayer::loadPlanetCute, this));
        MenuItemFont* simpleMenuItem = MenuItemFont::create("Simple menu demo", CC_CALLBACK_0(ExamplesMenuLayer::loadSimpleMenu, this));
        MenuItemFont* uiControlsItem = MenuItemFont::create("UI controls demo", CC_CALLBACK_0(ExamplesMenuLayer::loadUIControls, this));
        
        Menu* menu = CCMenu::create(basicItem,imagesItem,destroyItem,pinballItem,planetCuteItem,simpleMenuItem,uiControlsItem,NULL);
        menu->alignItemsVertically();
        addChild(menu);
        
	}
	return true;
}

void ExamplesMenuLayer::loadBasic()
{
    Director::getInstance()->replaceScene( BasicRUBELayer::scene() );
}

void ExamplesMenuLayer::loadImages()
{
    Director::getInstance()->replaceScene( RUBELayer::scene() );
}

void ExamplesMenuLayer::loadDestroy()
{
    Director::getInstance()->replaceScene( DestroyBodyLayer::scene() );
}

void ExamplesMenuLayer::loadPinball()
{
    Director::getInstance()->replaceScene( PinballRUBELayer::scene() );
}

void ExamplesMenuLayer::loadPlanetCute()
{
    Director::getInstance()->replaceScene( PlanetCuteRUBELayer::scene() );
}

void ExamplesMenuLayer::loadSimpleMenu()
{
    Director::getInstance()->replaceScene( MenuScreenRUBELayer::scene() );
}

void ExamplesMenuLayer::loadUIControls()
{
    Director::getInstance()->replaceScene( UIControlsRUBELayer::scene() );
}



