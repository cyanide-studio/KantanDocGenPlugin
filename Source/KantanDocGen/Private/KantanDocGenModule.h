// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

// Copyright (C) 2016-2017 Cameron Angus. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"
#include "DocGenTaskProcessor.h" // TUniquePtr seems to need full definition...

class FUICommandList;

/*
Module implementation
*/
class FKantanDocGenModule : public FDefaultGameModuleImpl
{
public:
	FKantanDocGenModule()
	{
	}
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void GenerateDocs(struct FKantanDocGenSettings const& Settings);

protected:
	void ShowDocGenUI();

protected:
	TUniquePtr<FDocGenTaskProcessor> Processor;

	TSharedPtr<FUICommandList> UICommands;
};
