//
//  HumanAISeekJobComponent.h
//  LifeUniversalis
//
//  Created by Pawel Sulik on 14.02.15.
//
//

#pragma once

#include <GameEngine.h>

class HumanComponent;

class HumanAISeekJobComponent : public GameObjectComponent
{
public:
    HumanAISeekJobComponent();
    ~HumanAISeekJobComponent();
    
    void onStart();
    void onBeforeFirstUpdate();
    void onUpdate();
    void onAttachToParent();
    void onDetachFromParent();
    void onDelete();
    void onEnabled();
    void onDisabled();
    
protected:
    
    HumanComponent* _human;
};