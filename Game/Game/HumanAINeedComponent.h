//
//  HumanAINeedComponent.h
//  Game
//
//  Created by Pawel Sulik on 19/02/15.
//  Copyright (c) 2015 LifeUniversalis. All rights reserved.
//

#pragma once

#include <GameEngine.h>

class HumanComponent;

class Service;

class HumanAINeedComponent : public GameObjectComponent
{
public:
    HumanAINeedComponent(const std::string &name);
    virtual ~HumanAINeedComponent();
    
    
    void onParentChangedComponents();
    
    //This value will be clamped to range 0...100.0
    float getPriority();
    //This value will be clamped to range 0...1.0
    float getProgress();
    
    virtual void updatePriority() = 0;

    virtual float valueImpact(Service* product);
    
    virtual std::string getNeedName() = 0;
    
    bool canBeCancelled();
    
protected:
    float _priority;
    float _progress;
    bool _canBeCancelled;
    HumanComponent* _humanComponent;
};