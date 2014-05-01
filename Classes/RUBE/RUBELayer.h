#ifndef RUBE_LAYER
#define RUBE_LAYER

#include "BasicRUBELayer.h"

//
//  RUBEImageInfo
//
//  Holds information about one image in the layer, most importantly
//  the body it is attached to and its position relative to that body.
//
//  When the body is moved by the physics engine, this information is
//  used to place the image in the correct position to match the physics.
//  If the body is NULL, the position is relative to 0,0 and angle zero.
//
USING_NS_CC;
struct RUBEImageInfo {
    
    Sprite* sprite;      // the image
    std::string name;               // the file the image was loaded from
    class b2Body* body;             // the body this image is attached to (can be NULL)
    float scale;                    // a scale of 1 means the image is 1 physics unit high
    float aspectScale;              // modify the natural aspect of the image
    float angle;                    // 'local angle' - relative to the angle of the body
    Point center;        // 'local center' - relative to the position of the body
    float opacity;                  // 0 - 1
    bool flip;                      // horizontal flip
    int colorTint[4];               // 0 - 255 RGBA values
    
};

//-------------------------

class RUBELayer : public BasicRUBELayer
{
public:
    static Scene* scene();
    virtual std::string getFilename();
    virtual cocos2d::Point initialWorldOffset();
    virtual float initialWorldScale();
    
    virtual void afterLoadProcessing(b2dJson* json);
    virtual void clear();
    
    void setImagePositionsFromPhysicsBodies();
    virtual void update(float dt);
    
    void removeBodyFromWorld(b2Body* body);
    void removeImageFromWorld(RUBEImageInfo* imgInfo);
    
    Sprite* getAnySpriteOnBody(b2Body* body);
    Sprite* getSpriteWithImageName(std::string name);
protected:
    std::set<RUBEImageInfo*> m_imageInfos;
};

#endif /* RUBE_LAYER */
