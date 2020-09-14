/*
  ==============================================================================

    ScrollbarManager.cpp
    Created: 1 Jul 2020 2:59:58am
    Author:  discoDSP

  ==============================================================================
*/

#include "ScrollbarManager.h"

ScrollbarManager::ScrollbarManager(Viewport& vp) : viewport(vp)
{
    viewport.addMouseListener(this, true);
    viewport.setScrollBarsShown(false, false, true, false);
    scrollEnabled(false);
    
};

ScrollbarManager::~ScrollbarManager()
{
    viewport.removeMouseListener(this);
};

void ScrollbarManager::mouseDown(const MouseEvent& event)
{
    jassert(constraints.size() != 0);
    
    auto e = event.getEventRelativeTo(&viewport);
        
    auto position = e.getMouseDownPosition();
            
    for (auto rectangle : constraints)
    {
        if (rectangle.contains(position))
        {
            scrollEnabled(true);
            break;
        }
    }
};

void ScrollbarManager::mouseUp(const MouseEvent& event)
{
    if (viewport.isScrollOnDragEnabled())
        scrollEnabled(false);
};

void ScrollbarManager::addConstraint(int initialX, int initialY, int width, int height)
{
    constraints.emplace_back(initialX, initialY, width, height);
};

void ScrollbarManager::removeAllConstraints()
{
    if (!constraints.empty())
        constraints.clear();
};

void ScrollbarManager::scrollEnabled(bool enabled)
{
    viewport.setScrollOnDragEnabled(enabled);
}

