//
//  WorkHumanTask.cpp
//  Game
//
//  Created by Pawel Sulik on 08/04/15.
//  Copyright (c) 2015 LifeUniversalis. All rights reserved.
//

#include "WorkHumanTask.h"
#include "Workplace.h"
#include "BuildingComponent.h"
#include "HumanInteractionControllerComponent.h"
#include "HumanWorkInteraction.h"
#include "HumanComponentNames.h"


std::string WorkHumanTask::getTaskName()
{
    return HT_WORK;
}

void WorkHumanTask::onUpdate()
{
    HumanInteraction* currentInteraction = _humanComponent->humanInteraction->getCurrentInteraction();
    if (getState() == EXECUTING)
    {
        if (currentInteraction == nullptr)
        {
            terminateGracefully();
        }
    }
    if (getState() == TERMINATING)
    {
        if (currentInteraction == nullptr)
            finish();
    }
}

Vector3 WorkHumanTask::getTarget()
{
    if (_humanComponent->getWorkplace() == nullptr)
        return Vector3(0, 0, 0);
    return _humanComponent->getWorkplace()->parent->getParent()->getTransform().getWorldPosition();
}

void WorkHumanTask::humanTaskWillTerminateImmediately(HumanTask* task)
{
    if (_humanComponent->humanInteraction->getCurrentInteraction() != nullptr)
        _humanComponent->humanInteraction->getCurrentInteraction()->terminateImmediately();
}

void WorkHumanTask::humanTaskDidTerminate(HumanTask* task)
{
    ((DayTimeEntity*) GameEngine::engine()->currentEnvironment->findEntity(EN_DAYTIME))->showOutputNextFrame();
    LOG("WORK HAS BEEN TERMINATED!");
}

void WorkHumanTask::humanTaskDidExecute(HumanTask* task)
{
    if (_humanComponent->getWorkplace() == nullptr)
        terminateImmediately();
    else
    {
        LOG("WorkHumanTask executed.");
        LOGF(F("\tCurrent state is: %1%") % getState());
    }
}

void WorkHumanTask::humanTaskWillInteract(HumanTask* task)
{
    LOGF(F("HumanTaskWillInteract: interactionExecution return code: %1%") % _humanComponent->humanInteraction->executeInteraction(new HumanWorkInteraction()));
}