//
//  TestNode.cpp
//  rock_box2d
//
//  Created by ChildhoodAndy on 14-5-2.
//
//

#include "TestNode.h"

TestNode::~TestNode()
{
    delete []_vertices;
}

bool TestNode::init()
{
    if ( !Node::init() ) {
        return false;
    }
    
    _radius = 100;
    _numSegments = 10;
    
    float deltaAngle = 2 * M_PI / _numSegments;
    
    _vertices = new Vertex2F[_numSegments+1+2];
//    _vertices = (Vertex2F*) malloc(sizeof(Vertex2F) * (_numSegments+1+2));
    
    _vertices[0] = Vertex2F(0, 0);
    
    for (int i = 1; i <= _numSegments; i++)
    {
        GLfloat theta = deltaAngle * (i - 1);
        
        GLfloat x = _radius * cosf(theta);
        GLfloat y = _radius * sinf(theta);
        
        _vertices[i] = Vertex2F(x, y);
    }
    
    _vertices[_numSegments+1] = _vertices[1];
    
    return true;
}

void TestNode::draw(Renderer* renderer, const kmMat4 &transform, bool transformUpdated)
{
    Node::draw(renderer, transform, transformUpdated);
    
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    // Set the color
    glColor4f(1.0, 1.0, 0.0, 1.0);
    
    // First argument - 2 numbers per Vertex2D
    // Second argument - data type
    // Third argument - stride (ignore for now)
    // Fourth argument - pass the vertices
    glVertexPointer(2, GL_FLOAT, 0, _vertices);
    
    // Last argument - total number of vertices
    glDrawArrays(GL_TRIANGLE_FAN, 0, (_numSegments+2));
    
    // Renable disabled states
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);
}
