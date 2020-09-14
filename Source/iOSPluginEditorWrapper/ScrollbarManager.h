/*
  =============================================================================

    ScrollbarManager.
    Created: 1 Jul 2020 2:59:58a
    Author:  discoDSP

  =============================================================================
*/

#pragma once

#include "JuceHeader.h"

/**
* This enables/disables the scrollbar if the user clicks inside the area of a constraint
* */

class ScrollbarManager : public MouseListener
{
public:
    
    ScrollbarManager(Viewport& vp);
    
    ~ScrollbarManager();
    
    virtual void mouseDown(const MouseEvent& event) override;
    
    virtual void mouseUp(const MouseEvent& event) override;
    
    void addConstraint(int initialX, int initialY, int width, int height);
    
    void removeAllConstraints();
    
    void scrollEnabled(bool);
    
private:

    Viewport& viewport;
    
    std::vector<Rectangle<int>> constraints;
    
};
