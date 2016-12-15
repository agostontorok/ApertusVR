#include <iostream>
#include "ApeLinkageDesignerVRPlugin.h"

ApeLinkageDesignerVRPlugin::ApeLinkageDesignerVRPlugin()
{
	mpSystemConfig = Ape::ISystemConfig::getSingletonPtr();
	mpEventManager = Ape::IEventManager::getSingletonPtr();
	mpEventManager->connectEvent(Ape::Event::Group::NODE, std::bind(&ApeLinkageDesignerVRPlugin::eventCallBack, this, std::placeholders::_1));
	mpScene = Ape::IScene::getSingletonPtr();
}

ApeLinkageDesignerVRPlugin::~ApeLinkageDesignerVRPlugin()
{
	std::cout << "ApeLinkageDesignerVRPlugin dtor" << std::endl;
}

void ApeLinkageDesignerVRPlugin::eventCallBack(const Ape::Event& event)
{

}

void ApeLinkageDesignerVRPlugin::Init()
{
	std::cout << "ApeLinkageDesignerVRPlugin::init" << std::endl;
	if (auto sceneProperty = mpScene->getProperty().lock())
	{
		sceneProperty->setAmbientColor(Ape::Color(0.1f, 0.1f, 0.1f, 1.0f));
		sceneProperty->setBackgroundColor(Ape::Color(1.0f, 1.0f, 1.0f, 1.0f));
	}
}

void ApeLinkageDesignerVRPlugin::Run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	mpEventManager->disconnectEvent(Ape::Event::Group::NODE, std::bind(&ApeLinkageDesignerVRPlugin::eventCallBack, this, std::placeholders::_1));
}

void ApeLinkageDesignerVRPlugin::Step()
{

}

void ApeLinkageDesignerVRPlugin::Stop()
{

}

void ApeLinkageDesignerVRPlugin::Suspend()
{

}

void ApeLinkageDesignerVRPlugin::Restart()
{

}
