/*
	Functions and classes allowing convenient manipulation of nif files. Provides a layer
	of abstraction for creating nifs that Nifly provides for reading them.

	Copied from Outfit Studio, all their copywrite restrictions apply
	*/
#include <map>
//#include "object3d.hpp"
#include "BasicTypes.hpp"
#include "geometry.hpp"
#include "skin.hpp"
//#include "NifFile.hpp"
//#include "NifUtil.hpp"
#include "Anim.h"

#pragma once

enum TargetGame {
	FO3, FONV, SKYRIM, FO4, SKYRIMSE, FO4VR, SKYRIMVR, FO76
};

extern std::string curRootName;


std::string SkeletonFile(enum TargetGame game);

void SetNifVersion(nifly::NifFile* nif, enum TargetGame targ);

void AddCustomBoneRef(const std::string& boneName, const std::string* parentBone = nullptr,
	const nifly::MatTransform* xformToParent = nullptr);

AnimInfo* CreateSkinForNif(nifly::NifFile* nif, enum TargetGame game);

void GetGlobalToSkin(AnimInfo* anim, nifly::NiShape* theShape, nifly::MatTransform* outXform);

void SetGlobalToSkinXform(AnimInfo* anim, nifly::NiShape* theShape, const nifly::MatTransform& gtsXform);

nifly::NiShape* XXXCreateShapeFromData(nifly::NifFile* nif, const char* shapeName,
	const std::vector<nifly::Vector3>* verts, const std::vector<nifly::Triangle>* tris,
	const std::vector<nifly::Vector2>* uv, const std::vector<nifly::Vector3>* norms);

void AddBoneToShape(AnimInfo* anim, nifly::NiShape* theShape, std::string boneName, nifly::MatTransform* boneXform=nullptr);

void SetShapeGlobalToSkinXform(AnimInfo* anim, nifly::NiShape* theShape, const nifly::MatTransform& gtsXform);

void SetShapeWeights(AnimInfo* anim, nifly::NiShape* theShape, std::string boneName, AnimWeight& theWeightSet);

int SaveSkinnedNif(AnimInfo* anim, std::string filepath);

void GetPartitions(nifly::NifFile* workNif, nifly::NiShape* shape, 
	nifly::NiVector<nifly::BSDismemberSkinInstance::PartitionInfo>& partitions,
	std::vector<int>& indices);
