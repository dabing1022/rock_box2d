//
//  ContentScene.cpp
//  rock_box2d
//
//  Created by ChildhoodAndy on 14-4-30.
//
//

#include "ContentScene.h"
#include "ExamplesMenuLayer.h"
#include "CutTheRopeScene.h"

struct DEMO
{
    const std::string demo_name;
    std::function<Scene*()> callback;
}demos[] =
{
    { "01 RUBE_TEST", [](){ return ExamplesMenuLayer::createScene(); } },
    { "02 CutTheRope", [](){ return CutTheRopeScene::createScene(); } },
};

Scene* ContentScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ContentScene::create();
    scene->addChild(layer);
    return scene;
}

bool ContentScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto bg = LayerColor::create(Color4B(255, 255, 255, 255), visibleSize.width, visibleSize.height);
    this->addChild(bg);
    
    TableView* tableView = TableView::create(this, Size(visibleSize.width, 500));
    tableView->setDirection(ScrollView::Direction::VERTICAL);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    tableView->setPosition(Point(visibleSize.width/6, visibleSize.height/6));
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    return true;
}

void ContentScene::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", cell->getIdx());
    auto scene = demos[cell->getIdx()].callback();
    Director::getInstance()->replaceScene(scene);
}

Size ContentScene::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    return Size(60, 60);
}

void ContentScene::tableCellHighlight(TableView* table, TableViewCell* cell)
{
    auto itemBg = static_cast<Sprite*>(cell->getChildByTag(100));
    itemBg->setTexture(Director::getInstance()->getTextureCache()->addImage("scrollItemBgSelected.png"));
}

void ContentScene::tableCellUnhighlight(TableView* table, TableViewCell* cell)
{
    auto itemBg = static_cast<Sprite*>(cell->getChildByTag(100));
    itemBg->setTexture(Director::getInstance()->getTextureCache()->addImage("scrollItemBgNormal.png"));
}

TableViewCell* ContentScene::tableCellAtIndex(TableView *table, ssize_t idx)
{
    auto demo_name = demos[idx].demo_name;
    TableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new TableViewCell();
        cell->autorelease();
        auto sprite = Sprite::create("scrollItemBgNormal.png");
        sprite->setAnchorPoint(Point::ZERO);
        sprite->setPosition(Point(0, 0));
        sprite->setTag(100);
        cell->addChild(sprite);
        
        auto label = Label::createWithSystemFont(demo_name, "Helvetica", 20.0);
        label->setPosition(Point::ZERO + Point(10, 10));
        label->setColor(Color3B(0, 0, 0));
		label->setAnchorPoint(Point::ZERO);
        label->setTag(200);
        cell->addChild(label);
    }
    else
    {
        auto label = (Label*)cell->getChildByTag(200);
        label->setString(demo_name);
    }
    
    
    return cell;
}

ssize_t ContentScene::numberOfCellsInTableView(TableView *table)
{
    return sizeof(demos) / sizeof(demos[0]);
}
