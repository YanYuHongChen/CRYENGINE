// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <CryAnimation/ICryAnimation.h>
#include <CryExtension/ClassWeaver.h>

class CSkeletonPoseModifier : public IAnimationPoseModifier
{
public:
	struct SJoint
	{
		string m_name;
		int m_crc;
		QuatT m_transform;
		int m_id;

		SJoint();
		SJoint(const string& name, const QuatT& transform);
	};

public:
	virtual CSkeletonPoseModifier::~CSkeletonPoseModifier() {}

	CRYINTERFACE_BEGIN()
	CRYINTERFACE_ADD(IAnimationPoseModifier)
	CRYINTERFACE_END()

	CRYGENERATE_CLASS(CSkeletonPoseModifier, "AnimationPoseModifier_SkeletonPoseModifier", 0x1558135D7DB242D1, 0xA93B228776A9D99B);

public:
	void PoseJoint(const string& name, const QuatT& transform);

	// IAnimationPoseModifier implementation.
	virtual bool Prepare(const SAnimationPoseModifierParams& params) override;
	virtual bool Execute(const SAnimationPoseModifierParams& params) override;
	virtual void Synchronize() override                           {}
	virtual void GetMemoryUsage(ICrySizer* pSizer) const override {}

private:
	std::vector<SJoint> m_posedJoints;
};