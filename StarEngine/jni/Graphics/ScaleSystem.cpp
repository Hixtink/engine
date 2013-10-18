#include "ScaleSystem.h"
#include "GraphicsManager.h"

namespace star
{
	std::shared_ptr<ScaleSystem> ScaleSystem::m_ScaleSystemPtr = nullptr;

	ScaleSystem::ScaleSystem()
		:m_Scale(0)
		,m_AspectRatio(0)
	{
	}


	ScaleSystem::~ScaleSystem(void)
	{
	}

	std::shared_ptr<ScaleSystem> ScaleSystem::GetInstance()
	{
		if(m_ScaleSystemPtr == nullptr)
		{
			m_ScaleSystemPtr = std::shared_ptr<ScaleSystem>(new ScaleSystem());
		}			
		return m_ScaleSystemPtr;	
	}

	void ScaleSystem::SetWorkingResolution(int xPixels, int yPixels)
	{
		SetWorkingResolution(vec2(xPixels, yPixels));
	}

	void ScaleSystem::SetWorkingResolution(const vec2& pixels)
	{
		m_WorkingRes = pixels;
		m_AspectRatio = pixels.x / pixels.y;
		UpdateWorkingResolution();
	}

	float ScaleSystem::GetScale()
	{
		return m_Scale;
	}

	float ScaleSystem::GetAspectRatio()
	{
		return m_AspectRatio;
	}

	void ScaleSystem::UpdateWorkingResolution()
	{
		m_Scale = m_WorkingRes.x / (float)GraphicsManager::GetInstance()->GetWindowWidth();
	}
}
