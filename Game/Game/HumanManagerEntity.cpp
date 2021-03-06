#include "HumanManagerEntity.h"
//#include "BuildingTestComponent.h"

#include "HumanIncludes.h"

#include "PaymentAgentComponent.h"


#include "DayTimeEntity.h"


HumanManagerEntity::HumanManagerEntity() : GameEnvironmentEntity(EN_HUMAN_MGR)
{
}


HumanManagerEntity::~HumanManagerEntity(void)
{
}


void HumanManagerEntity::onStart()
{
}

void HumanManagerEntity::onUpdate()
{
//	LOG("HumanManager sie kurwa update'uje!!!!!!!!!!");
    
    
//    DayTimeEntity *dt = (DayTimeEntity*)GameEngine::engine()->currentEnvironment->findEntity(EN_DAYTIME);
    
//    if(dt->getCurrentGameDate().minute == 5)
//    {
//        std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
//        
//        for(auto human : this->getHumans())
//        {
//            HumanComponent *comp = (HumanComponent*)human->findComponent("HumanComponent");
//            std::cout << comp->getHumanName() << " is ";
//            if(comp->getWorkplace() == nullptr)
//                std::cout << "unemployed!!!\n";
//            else
//                std::cout << "a happy slave!\n";
//        }
//    }
}

void HumanManagerEntity::onStop()
{
}

GameObject* HumanManagerEntity::create()
{
	GameObject* retVal = new GameObject();
	retVal->setName("Human");
    
    //General components
    retVal->addComponent(new HumanComponent("Ryszard", 18));
    retVal->addComponent(new MotionComponent());
    retVal->addComponent(new HumanInteractionControllerComponent());
    retVal->addComponent(new PaymentAgentComponent());
    
    //AI Stuff
    retVal->addComponent(new HumanTaskQueueComponent());
    retVal->addComponent(new HumanAIMasterComponent());
    retVal->addComponent(new HumanAISeekJobComponent());
    retVal->addComponent(new HumanAITestNeedComponent());
    retVal->addComponent(new HumanAIWorkNeedComponent());
    
    //Settings
    ((MotionComponent*)retVal->findComponent(HC_MOTION))->setSpeed(20.0f);
    ((MotionComponent*)retVal->findComponent(HC_MOTION))->setThreshold(1.0f);
    
	return retVal;
}

void HumanManagerEntity::add(GameObject* human)
{
	GameEngine::engine()->currentScene->addObject(human);
	_humans.push_back(human);
}

void HumanManagerEntity::remove(GameObject* human)
{
	GameEngine::engine()->currentScene->removeObject(human);
	for(int i = 0; i < _humans.size(); i++)
	{
		if(_humans[i] == human)
		{
			_humans.erase(_humans.begin() + i);
			return;
		}
	}
}

std::vector<GameObject*> HumanManagerEntity::getHumans()
{
    return _humans;
}